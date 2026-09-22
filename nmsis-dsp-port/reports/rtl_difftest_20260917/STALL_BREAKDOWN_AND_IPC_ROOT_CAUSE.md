# 多重前递阻塞统计与 IPC 根因分析

## 1. 结论

当前晚前递 RTL 在 12 个具有完整聚合报告的 NMSIS Benchmark suite 上全部通过
RTL/reference difftest。累计执行 53,137,208 条指令、17,787,795 个周期，IPC 为
2.987285。

最重要的结论是：**多重前递本身没有导致 IPC 下降**。在当前 RTL 上进行只开关
跨包 late-forward、其余实现完全相同的受控 A/B 后：

| 配置 | 周期 | 指令 | 加权 IPC |
| --- | ---: | ---: | ---: |
| 关闭跨包 late-forward | 17,955,875 | 53,137,208 | 2.959322 |
| 打开跨包 late-forward | 17,787,795 | 53,137,208 | 2.987285 |
| 变化 | **-168,080** | 0 | **+0.945%** |

因此，当前实现相对 2026-09-10 历史报告的 IPC -0.833%，来自两个版本之间的其他
RTL 差异，不能归因于多重前递。按总周期作算术分解：

```text
历史报告                         17,639,675 cycles
当前 RTL、关闭 late-forward      17,955,875 cycles  (+316,200)
打开 late-forward                17,787,795 cycles  (-168,080)
当前结果相对历史报告                                 +148,120
```

这里的“当前 RTL、关闭 late-forward”是用于隔离该功能的实验配置，并不等同于历史
RTL；其价值是证明 late-forward 在相同其余条件下净收益 168,080 周期。

## 2. 统计口径

统计信号来自 Hazard 最终采用的、经过优先级裁决后的控制，而不是未采用的候选条件：

1. div stall；
2. branch redirect/flush；
3. nested stall；
4. ID RAW stall。

因此 `div + nested + ID RAW = frontend stall`，三者互斥。RAW 子类型和 replay
生产者子类型允许重叠，报告中单独列出 overlap。

`Branch flush` 和 `late-forward hit` 是事件周期，不是 frontend stall，不能与三个
stall 原因直接相加。late-forward hit 只在 EX1 指令包实际前进时计数，被 div、branch
或 nested 控制覆盖的候选匹配不计为有效命中。

## 3. 当前 frontend stall 构成

| 类型 | 周期 | 占总周期 | 占 frontend stall |
| --- | ---: | ---: | ---: |
| Frontend stall 合计 | 6,068,227 | 34.115% | 100.000% |
| ID RAW stall | 5,264,651 | 29.597% | 86.758% |
| Nested stall | 559,427 | 3.145% | 9.219% |
| Div stall | 244,149 | 1.373% | 4.023% |
| 其他 frontend stall | 0 | 0.000% | 0.000% |

从绝对占比看，当前性能的第一大阻塞仍是 ID RAW。nested 是第二大类，div stall
占比较小。

### 3.1 ID RAW 子类型

| RAW 子类型 | 周期 | 占 ID RAW | 占总周期 |
| --- | ---: | ---: | ---: |
| needWB RAW | 4,610,699 | 87.578% | 25.921% |
| replay RAW | 680,301 | 12.922% | 3.825% |
| needWB 与 replay 同拍重叠 | 26,349 | 0.500% | 0.148% |

`needWB RAW` 与 `replay RAW` 是原因位，可能同拍成立；ID RAW 合计使用两者的并集。
needWB 包括仍需等到 WB 的 load、MUL/DIV、FPU/FDiv 等结果。

### 3.2 replay RAW 的生产者来源

| replay 生产者来源 | 周期 | 占 replay RAW |
| --- | ---: | ---: |
| 涉及跨包 late-forward 的生产者 | 16,131 | 2.371% |
| 涉及普通同包浅依赖生产者 | 668,425 | 98.254% |
| 两类生产者同拍出现 | 4,255 | 0.625% |
| 仅 late-forward 生产者 | 11,876 | 1.746% |
| 仅浅依赖生产者 | 664,170 | 97.629% |

因此，不能把全部 680,301 个 replay RAW 周期算作多重前递的新代价。真正涉及
late-forward 生产者的 replay stall 只有 16,131 个周期；replay RAW 的主体是原有
同包浅依赖生产者被后继 ID 包读取。

## 4. 控制与前递事件

| 事件 | 次数/周期 | 占总周期或事件比例 |
| --- | ---: | ---: |
| Branch flush 合计 | 1,636,836 | 9.202% 总周期 |
| Branch flush at EX2 | 1,251,568 | 76.463% branch flush |
| Branch flush at EX3 | 385,268 | 23.537% branch flush |
| EX3 flush 且分支使用 late-forward | 16,853 | 1.030% branch flush |
| 有效 late-forward hit cycle | 239,373 | 1.346% 总周期 |
| late-forward lane | 262,795 | 事件计数 |
| late-forward operand | 263,307 | 事件计数 |

EX3 branch flush 中只有 16,853 次由 late-forward 分支引起，占总周期 0.095%，占
全部 EX3 flush 4.374%。所以“分支因晚前递延迟到 EX3”是可测量的代价，但不是总体
IPC 变化的主因。

## 5. 受控 A/B 的 stall 变化

| 指标 | 关闭 late-forward | 打开 late-forward | 变化 |
| --- | ---: | ---: | ---: |
| Frontend stall | 6,320,629 | 6,068,227 | **-252,402** |
| ID RAW stall | 6,076,480 | 5,264,651 | **-811,829** |
| Nested stall | 0 | 559,427 | +559,427 |
| Div stall | 244,149 | 244,149 | 0 |
| replay RAW | 1,521,088 | 680,301 | **-840,787** |
| Branch flush 合计 | 1,636,836 | 1,636,836 | 0 |
| Branch flush at EX2 | 1,268,388 | 1,251,568 | -16,820 |
| Branch flush at EX3 | 368,448 | 385,268 | +16,820 |

这说明当前设计的实际行为是：

- late-forward 大量消除了原本在 ID 等待浅依赖生产者的 replay RAW；
- 当“晚前递消费者又是同包浅依赖生产者”时，旧的一拍等待从 ID 移到 EX1，表现为
  nested stall；
- replay RAW 的减少量大于 nested 的增加量，最终 frontend stall 净减少 252,402；
- 有 16,820 个 branch redirect 从 EX2 移到 EX3，但 branch flush 事件总数不变；
- 综合全部流水线效应后，总周期净减少 168,080。

所以 559,427 个 nested stall 是当前 late-forward 收益未能完全兑现的最大限制因素，
但它不是相对旧实现凭空新增的 559,427 个损失周期，也不是历史 IPC 下降的证据。

## 6. 各 suite 的受控 A/B 结果

正的 IPC 变化表示打开 late-forward 后变快。

| Suite | 关闭时周期 | 打开时周期 | 周期变化 | IPC 变化 |
| --- | ---: | ---: | ---: | ---: |
| BasicMathFunctions | 2,753,333 | 2,749,797 | -3,536 | +0.129% |
| BayesFunctions | 10,399 | 10,403 | +4 | -0.039% |
| ComplexMathFunctions | 1,232,222 | 1,233,880 | +1,658 | -0.135% |
| ControllerFunctions | 562,920 | 563,877 | +957 | -0.170% |
| DistanceFunctions | 224,931 | 224,451 | -480 | +0.214% |
| InterpolationFunctions | 79,944 | 80,002 | +58 | -0.072% |
| MatrixFunctions | 7,966,948 | 7,808,812 | **-158,136** | **+2.025%** |
| QuaternionMathFunctions | 585,523 | 585,533 | +10 | -0.002% |
| SVMFunctions | 99,383 | 99,395 | +12 | -0.012% |
| StatisticsFunctions | 1,098,102 | 1,092,601 | -5,501 | +0.504% |
| SupportFunctions | 2,525,444 | 2,525,509 | +65 | -0.003% |
| TransformFunctions | 816,726 | 813,535 | -3,191 | +0.392% |

收益高度集中在 MatrixFunctions：其减少 158,136 周期，占总净收益的 94.08%。部分
suite 有很小的负收益，但不改变总体结论。

## 7. 对 IPC 下降的最终定位

### 7.1 可以确认的结论

1. **多重前递净提升当前处理器 IPC 0.945%，不是历史 IPC 下降原因。**
2. 当前最大绝对瓶颈是 needWB RAW（总周期的 25.921%），但它在 late-forward A/B
   中基本不变，因此也不是该功能造成的回退。
3. late-forward 将大量 ID replay RAW 转换为无停顿执行或 EX1 nested stall，净减少
   252,402 个 frontend stall 周期。
4. nested stall 是进一步优化 late-forward 的首要目标；减少 nested 才能把已经识别
   的相关转换成更高的实际收益。
5. late-forward branch 的 EX3 重定向和 late-producer replay RAW 数量都较小，优化
   优先级低于 nested 和 needWB。

### 7.2 为什么历史对比会显示下降

历史报告与当前 RTL 之间不只有 late-forward 一项差异。当前工作树还包含 LSU/存储
顺序、FPU/FDiv、乘除法停顿、branch flush 等实现变化。历史基线与当前 no-late
实验相差 316,200 周期，而 late-forward 又收回 168,080 周期，最终才表现为历史
对比中的 +148,120 周期。因此把这 +148,120 周期全部记在多重前递名下属于基线混杂。

若要继续定位剩余 316,200 周期，应以当前版本为基线，逐项对 LSU/store buffer、
FPU/FDiv、分支控制等功能做同样的单变量 A/B；仅靠当前一次运行的 stall 构成无法把
历史版本之间的混合差异可靠分摊到某个模块。

## 8. 优化建议

优先级建议如下：

1. 统计 nested 的 producer/consumer lane、操作数以及连续出现次数，针对编译器调度
   避免“late producer 同时作为 shallow producer”的包形；
2. 在不引入 `EX3 -> EX2 ALU -> EX2 ALU` 长组合路径的前提下，研究能否只对可安全
   拆解的 nested 情况免除 EX1 停顿；
3. 继续细分 needWB RAW 为 load、mul、div、FPU、FDiv，定位 4.61M RAW 周期中的
   主导单元；
4. EX3 late-branch 和 late-producer replay RAW 占比较低，作为后续优化项。
