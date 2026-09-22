CROSS_COMPILE := 
COMMON_FLAGS  := --target=riscv32-unknown-unknown -mcpu=dandelion -march=rv32imf -g -fno-pic
CFLAGS        += $(COMMON_FLAGS) -static -fdata-sections -ffunction-sections
AFLAGS        += $(COMMON_FLAGS) 
LDFLAGS       += -melf32lriscv -static --gc-sections -e _start
