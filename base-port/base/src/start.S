.section entry, "ax"
.globl _start
.type _start, @function

_start:
  fmv.s	ft0, ft0
  addi s0, zero, 0
  lui sp, %hi(_stack_pointer)
  nop
  nop
  nop
  nop
  nop
  fmv.s	ft0, ft0
  addi sp, sp, %lo(_stack_pointer)
  nop
  nop
  nop
  nop
  nop
  jal call_main

