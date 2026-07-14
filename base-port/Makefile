-include $(BASE_PORT)/script/riscv32.mk
ifeq ($(MAKECMDGOALS),)
  MAKECMDGOALS  = image
  .DEFAULT_GOAL = image
endif
# Compilers
LLVM_BIN  ?= /home/zhangfulin/RISCV-VLIW/llvm-project-llvmorg-21.1.8/build-debug/bin
CC 			= $(LLVM_BIN)/clang
CXX 		= $(LLVM_BIN)/clang++
AS 			= $(LLVM_BIN)/clang
LD 			= $(LLVM_BIN)/ld.lld
OBJ_DUMP 	= $(LLVM_BIN)/llvm-objdump
OBJ_COPY 	= $(LLVM_BIN)/llvm-objcopy
LLC 		= $(LLVM_BIN)/llc

# include 
WORK_DIR  = $(abspath .)
INC_PATH = -I$(WORK_DIR)/include
INC_PATH += -I$(BASE_PORT)/base/include
INC_PATH += -I$(BASE_PORT)/tool/include

# FLAGS and LIBS
CFLAGS    += -O2 -Wall -Werror $(INC_PATH) -Wno-main -fno-asynchronous-unwind-tables -fno-builtin -fno-stack-protector -MMD --target=riscv32-unknown-unknown -mcpu=dandelion -march=rv32imfd 
AFLAGS 	  += -MMD $(INC_PATH) --target=riscv32-unknown-unknown -mcpu=dandelion -march=rv32imfd 
LDFLAGS   += -T $(BASE_PORT)/script/linker.ld --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0 
LIBS 	  += $(BASE_PORT)/base/build/libbase.a $(BASE_PORT)/tool/build/libtool.a
LINKAGE   = $(OBJS) $(LIBS)

# Build directory and OBJS
BUILD_DIR = $(abspath ./build)
IMAGE ?= $(BUILD_DIR)/$(NAMES)-riscv32
TAR_DIR = $(BUILD_DIR)/riscv32
IR_DIR  = $(BUILD_DIR)/riscv32-ir
ASM_DIR = $(BUILD_DIR)/riscv32-asm
OBJS = $(addprefix $(TAR_DIR)/, $(addsuffix .o, $(basename $(SRCS))))
IRS  = $(addprefix $(IR_DIR)/,  $(addsuffix .ll, $(basename $(SRCS))))
ASMS = $(addprefix $(ASM_DIR)/, $(addsuffix .s,  $(basename $(SRCS))))

# Keep IR and assembly files generated in chained pattern rules.
.SECONDARY: $(IRS) $(ASMS)

# Colors
COLOR_RED   		= \033[1;31m
COLOR_GREEN 		= \033[1;32m
COLOR_YELLOW 		= \033[33m
COLOR_NONE  		= \033[0m

# Step 1: Compile C to LLVM IR (.ll)
$(IR_DIR)/%.ll: %.c
	@mkdir -p $(dir $@) && printf "$(COLOR_YELLOW)[IR]$(COLOR_NONE) $<\n"
	@$(CC) $(CFLAGS) -emit-llvm -S -o $@ $(realpath $<)

# Step 2: Compile IR to assembly (.s)
$(ASM_DIR)/%.s: $(IR_DIR)/%.ll
	@mkdir -p $(dir $@) && printf "$(COLOR_YELLOW)[LLC]$(COLOR_NONE) $<\n"
	@$(LLC) -mtriple=riscv32 -mcpu=dandelion -mattr=+m,+f,+d -filetype=asm -o $@ $<

# Step 3: Assemble .s to object file (.o)
$(TAR_DIR)/%.o: $(ASM_DIR)/%.s
	@mkdir -p $(dir $@) && printf "$(COLOR_YELLOW)[AS]$(COLOR_NONE) $<\n"
	@$(AS) $(AFLAGS) -c -o $@ $<

# Hand-written assembly (.S) bypasses IR pipeline
$(TAR_DIR)/%.o: %.S
	@mkdir -p $(dir $@) && printf "$(COLOR_YELLOW)[AS]$(COLOR_NONE) $<\n"
	@$(AS) $(AFLAGS) -c -o $@ $(realpath $<)

# make libbase
$(LIBS):
	@make -s -C $(BASE_PORT)/base libkernel
	@make -s -C $(BASE_PORT)/tool libkernel

# Linkage
$(IMAGE).elf: $(OBJS) $(LIBS)
	@printf "$(COLOR_YELLOW)[LD]$(COLOR_NONE) build/$(notdir $@)\n"
	@$(LD) $(LDFLAGS) -o $@ --start-group $(LINKAGE) --end-group
	@$(OBJ_DUMP) -d $@ > $(IMAGE).txt
	@$(OBJ_COPY) -O binary $@ $(IMAGE).bin

image: $(IMAGE).elf

run: image
	@make -s -C $(SIM_PATH) run IMG=$(IMAGE).bin ARGS=$(ARGS) USE_SIMULATOR_ONLY_MODE=$(USE_SIMULATOR_ONLY_MODE)

gdb: image
	@make -s -C $(SIM_PATH) gdb IMG=$(IMAGE).bin ARGS=$(ARGS) USE_SIMULATOR_ONLY_MODE=$(USE_SIMULATOR_ONLY_MODE)

clean: 
	rm -rf $(BUILD_DIR)
clean-all:
	rm -rf $(BUILD_DIR) $(BASE_PORT)/*/build
