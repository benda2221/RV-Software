
# make ar
LLVM_BIN  ?= /home/zhangfulin/RISCV-VLIW/llvm-project-llvmorg-21.1.8/build-debug/bin
CROSS_COMPILE :=
AR  = $(LLVM_BIN)/llvm-ar
CC  = $(LLVM_BIN)/clang
AS  = $(LLVM_BIN)/clang
LLC = $(LLVM_BIN)/llc

COMMON_FLAGS = -march=rv32imf -mcpu=dandelion -O2 --target=riscv32-unknown-unknown -g

CFLAGS = -MMD $(COMMON_FLAGS) $(INC_PATH)
CFLAGS += -fno-asynchronous-unwind-tables -fno-builtin -fno-stack-protector -ffp-contract=off
AFLAGS = $(COMMON_FLAGS)
LLCFLAGS = --fp-contract=off -riscv-enable-pipeliner -riscv-disable-shallow-dependency=false
ARFLAGS = rcs

BUILD_DIR = $(abspath ./build)
TAR_DIR = $(BUILD_DIR)/riscv32
IR_DIR  = $(BUILD_DIR)/riscv32-ir
ASM_DIR = $(BUILD_DIR)/riscv32-asm
OBJS = $(addprefix $(TAR_DIR)/, $(addsuffix .o, $(basename $(KER_SRCS))))
IRS  = $(addprefix $(IR_DIR)/,  $(addsuffix .ll, $(basename $(KER_SRCS))))
ASMS = $(addprefix $(ASM_DIR)/, $(addsuffix .s,  $(basename $(KER_SRCS))))
LIBKER = $(BUILD_DIR)/lib$(LIBNAME).a

# Keep IR and assembly files generated in chained pattern rules.
.SECONDARY: $(IRS) $(ASMS)

# Step 1: Compile C to LLVM IR (.ll)
$(IR_DIR)/%.ll: %.c
	@mkdir -p $(dir $@) && printf "\033[33m[IR]\033[0m $<\n"
	@$(CC) $(CFLAGS) -emit-llvm -S -o $@ $(realpath $<)

# Step 2: Compile IR to assembly (.s)
$(ASM_DIR)/%.s: $(IR_DIR)/%.ll
	@mkdir -p $(dir $@) && printf "\033[33m[LLC]\033[0m $<\n"
	@$(LLC) $(LLCFLAGS) -mtriple=riscv32 -mcpu=dandelion -mattr=+m,+f,-d,-unaligned-scalar-mem -filetype=asm -o $@ $<

# Hand-written assembly (.S) bypasses the IR pipeline. Keep this rule before
# the generated-assembly rule so a clean build does not try to derive start.ll.
$(TAR_DIR)/%.o: %.S
	@mkdir -p $(dir $@) && printf "\033[33m[AS]\033[0m $<\n"
	@$(AS) $(AFLAGS) -c -o $@ $(realpath $<)

# Step 3: Assemble .s to object file (.o)
$(TAR_DIR)/%.o: $(ASM_DIR)/%.s
	@mkdir -p $(dir $@) && printf "\033[33m[AS]\033[0m $<\n"
	@$(AS) $(AFLAGS) -c -o $@ $<

libkernel: $(LIBKER)
$(LIBKER): $(OBJS)
	@printf "\033[33m[AR]\033[0m build/$(notdir $@)\n"
	@$(AR) $(ARFLAGS) $@ $(realpath $^)

clean:
	rm -rf $(BUILD_DIR)
