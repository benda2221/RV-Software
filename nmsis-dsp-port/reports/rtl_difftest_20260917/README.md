# NMSIS RTL difftest 结果（2026-09-17）

## 测试对象

- RTL 仿真器：`ZirconSim/build/VCPU`
- 构建模式：`difftest`
- 软件集：`RV-Software/nmsis-dsp-port` 生成的 14 个 Benchmark suite
- 对照模型：Zircon reference Simulator
- 浅依赖：启用

为缩短 FilteringFunctions 的运行时间，各 case 使用独立进程执行；每个进程均使用同一个
RTL difftest 可执行文件和对应的 RV32 镜像。波形输出指向 `/dev/null`，不影响 RTL、
reference Simulator 或 difftest 检查。

## 总结果

| 项目 | 数量 |
| --- | ---: |
| Benchmark case 总数 | 337 |
| RTL difftest 通过 | 335 |
| RTL difftest 失败 | 1 |
| 构建失败 | 1 |

| Suite | Case 数 | 结果 |
| --- | ---: | --- |
| BasicMathFunctions | 51 | 51 PASS |
| BayesFunctions | 1 | 1 PASS |
| ComplexMathFunctions | 19 | 19 PASS |
| ControllerFunctions | 13 | 13 PASS |
| DistanceFunctions | 18 | 18 PASS |
| FastMathFunctions | 18 | 17 PASS，1 BUILD FAIL |
| FilteringFunctions | 67 | 66 PASS，1 DIFFTEST FAIL |
| InterpolationFunctions | 9 | 9 PASS |
| MatrixFunctions | 32 | 32 PASS |
| QuaternionMathFunctions | 8 | 8 PASS |
| SVMFunctions | 4 | 4 PASS |
| StatisticsFunctions | 57 | 57 PASS |
| SupportFunctions | 24 | 24 PASS |
| TransformFunctions | 16 | 16 PASS |

补充测试：

- legacy BasicMath fixed runner：30/30 checks PASS。
- `testing-smoke/BasicMaths`：q7、q15、q31 共 156 次调用均打印 PASS；程序返回后进入
  无提交状态，最终以 stall timeout（退出码 253）结束。该 smoke runner 不属于上述
  337 个 Benchmark case。

## 唯一 RTL difftest 失败

Case：`FilteringFunctions/conv_riscv_conv_fast_q15`

该 case 并行运行和单独串行复跑均在同一点确定性失败：

```text
cycle: 2511351
pc:    0x80000474
inst:  0x00044683    # lbu x13, 0(x8)
reg:   x13
DUT:   0x00000000
REF:   0x000000ac
```

这与既有报告
[`FILTERING_CONV_FAST_Q15_UNALIGNED_SW.md`](../strict_alignment_20260817/FILTERING_CONV_FAST_Q15_UNALIGNED_SW.md)
记录的是同一个已知问题。NMSIS 的 packed Q15 路径在只有 2 字节对齐的地址上执行 32 位
`sw`；RTL memory 与 reference Simulator 对该无效非对齐访问的处理不同。当前构建布局
改变了最终报错 PC，但访问模式和 `x13: 0x0 / 0xac` 的症状一致。因此不能把该失败归因于
本次晚前递修改。

## 唯一构建失败

Case：`FastMathFunctions/sqrt_riscv_sqrt_f32`

链接阶段缺少双精度软件运行库符号：

```text
__floatsidf
__divdf3
__truncdfsf2
```

这是此前已有的 RV32 运行库缺口；其余 17 个 FastMath case 均通过 RTL difftest。

## 与既有结果比较

### f32 candidate RTL difftest

旧基线 `manifests/f32_candidate_run_summary.csv`：

| 结果 | 旧基线 | 本次 |
| --- | ---: | ---: |
| PASS | 65 | 108 |
| FAIL | 44 | 0 |
| BUILD FAIL | 0（计入 FAIL） | 1 |
| 总数 | 109 | 109 |

旧基线单独记录的 17 个 f32 difftest mismatch case，本次均已通过。总计有 43 个旧失败
转为通过；剩余 1 个是上述 `sqrt_f32` 已知链接失败。

### 全 Benchmark 的 Simulator-vs-x86 数值基线

旧报告 `reports/simulator_vs_x86_20260817/README.md` 的统计是 294 个 hash match、41 个
hash mismatch、2 个无法比较。本次测试衡量的是“RTL 是否与 reference Simulator 一致”，
不是“reference Simulator 是否与 x86 数值一致”，因此两组数字不能直接相减。

本次结果表明：除已知非对齐 Q15 case 外，所有可构建 Benchmark 均与 reference Simulator
一致。旧报告中的部分 x86 hash mismatch（例如定点边界语义、未初始化数据或测试契约问题）
仍可能存在，但它们不构成 RTL difftest 失败。

## 结论

当前晚前递 RTL 在 NMSIS Benchmark 上未出现新的、可归因于前递逻辑的回归。可构建的
336 个 case 中 335 个通过；唯一失败与 2026-08-17 已记录的非对齐 Q15 内存语义问题一致。
