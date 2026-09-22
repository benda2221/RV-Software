# `riscv_conv_fast_q15` 非对齐 `SW` 问题记录

日期：2026-08-17

## 结论

`FilteringFunctions/conv_riscv_conv_fast_q15` 在严格对齐配置下会执行地址为
`4n+2` 的 `sw`。这不是 LLVM bundle 重排造成的寄存器生命周期错误，也不是
LLVM 后端未拆分一个已经标注为低对齐的内存访问；直接原因是 NMSIS 移植层把
可能只有 2 字节对齐的 `q15_t *` 强制转换为 `int32_t *` 并解引用，使 LLVM IR
得到错误的 `align 4` 对齐承诺。

该问题应优先在程序/NMSIS 移植层修正。当前任务只记录问题，不修改算法、移植层、
编译器、RTL 或 Simulator。

## 运行配置

- 前端目标：`-mcpu=dandelion -march=rv32imf`
- LLC：`-mcpu=dandelion -mattr=+m,+f,-d,-unaligned-scalar-mem`
- 处理器策略：严格对齐，不依赖硬件非对齐访问
- bundle：包内所有指令读取包开始前的寄存器快照，包结束后统一提交写回

## 地址形成过程

测试 wrapper 的局部输出数组 `pDst` 起始地址是 `0x80027fd8`，满足 4 字节对齐。
算法进入 stage 1 后输出 511 个 `q15_t`：

```text
0x80027fd8 + 511 * sizeof(q15_t)
= 0x80027fd8 + 0x3fe
= 0x800283d6
```

因此进入 stage 2 时 `pOut == 0x800283d6`，只满足 2 字节对齐。stage 2 使用
`write_q15x2_ia` 进行一次 packed 32 位写，最终生成：

```asm
sw a0, 0(a4)   # a4 = 0x800283d6
```

仅提高输出数组的起始对齐不能解决这个问题，因为奇数个 Q15 输出会再次把指针移动到
`4n+2` 地址。

## 源码与 IR 证据

移植层当前的 32 位写宏为：

```c
#define __SW(address, value) (*(int32_t *)(address) = (int32_t)(value))
```

`write_q15x2` 在未启用非对齐路径时调用该宏。`int32_t *` 解引用向 C 编译器承诺
4 字节对齐；当实际地址为 `4n+2` 时，源码已经违反该对齐约定。对应 LLVM IR 为：

```llvm
store i32 %or, ptr %pOut.2941, align 4
store i32 %or146, ptr %add.ptr.i806, align 4
```

LLVM 后端依据 `align 4` 生成 `sw` 是符合 IR 语义的。只有当源码通过
`memcpy`、低对齐指针或目标专用接口把访问正确表达为 `align 1/2` 后，严格对齐
后端才有责任将它合法化为 `sh`/`sb` 序列。

## 已观察到的运行时后果

RTL 与 reference Simulator 在执行该非对齐 `sw` 后对内存的处理不一致：

```text
写入地址：0x800283d6
包含地址 0x800283d4 的 RTL word：       0xbda40000
包含地址 0x800283d4 的 Simulator word： 0xbda49bac
```

在此之前，地址 `0x800283d4` 的低半字由下面的指令写成 `0x9bac`：

```asm
sh a1, 0(t2)
```

随后 RTL 的非对齐 `sw` 路径覆盖了低两个字节，而 reference Simulator 保留了它们，
最终在 PC `0x80000654` 的 `lbu a3, 0(s0)` 上表现为寄存器 `a3` 不一致。失败之前
`s0` 在两侧始终一致，因而该现象不是较早发生的 `s0` 寄存器错误。

这里包含两个需要分开处理的问题：

1. 程序/移植层在严格对齐目标上发出了无效的非对齐 32 位访问。
2. RTL memory 与 reference Simulator 对该无效访问的处理规则不一致。

第二项会使 difftest 更早暴露分歧，但即使统一两侧行为，也不能使第一项程序访问变得
合法。

## 后续修正建议（本次不实施）

1. 在 NMSIS 移植层用两次 16 位写实现可能只有 2 字节对齐的 packed Q15 写；或使用
   `memcpy`/`__builtin_memcpy` 正确表达低对齐访问。
2. 性能敏感路径可先标量写出一个 Q15 元素，将 `pOut` 调整到 4 字节边界，再执行
   packed 循环。
3. 增加 LLVM 严格对齐回归测试，验证真正标注为 `align 2` 的 `i32` store 会被拆分。
4. 统一 RTL memory 与 Simulator 的非对齐策略：严格模式下同时拒绝/报错，或者同时
   正确实现跨 word 访问。
5. 在移植层构建中增加 `-Wcast-align` 或 alignment sanitizer 检查。

## 相关文件

- `port/include/nmsis_core.h`：`__SW` 定义
- `vendor/NMSIS/DSP/Include/riscv_math_memory.h`：`write_q15x2`
- `vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_fast_q15.c`：stage 1/2
- `build/riscv32-ir/vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_fast_q15.ll`：
  `align 4` store
- `build/riscv32-asm/vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_fast_q15.s`：
  非对齐 `sw`
