BASE_PORT = $(abspath ../base-port)
SIM_PATH = $(abspath ../../)
SUITE ?= BasicMathFunctions
TEST_SYSTEM ?=
USE_SIMULATOR_ONLY_MODE ?= 1

-include generated/benchmark/suites.mk
-include generated/legacy/cases.mk

ifeq ($(TEST_SYSTEM),benchmark)
ifneq ($(TEST_CASE),)
include generated/benchmark/$(SUITE)/cases/$(TEST_CASE)/sources.mk
else
include generated/benchmark/$(SUITE)/sources.mk
endif
NAMES = $(TEST_NAME)
SRCS = $(TEST_SRCS)
else ifeq ($(TEST_SYSTEM),legacy)
ifneq ($(TEST_CASE),)
include generated/legacy/$(SUITE)/cases/$(TEST_CASE)/sources.mk
else
include generated/legacy/$(SUITE)/sources.mk
endif
NAMES = $(TEST_NAME)
SRCS = $(TEST_SRCS)
else ifeq ($(TEST_SYSTEM),testing-smoke)
include generated/testing_smoke/$(SUITE)/sources.mk
NAMES = $(TEST_NAME)
SRCS = $(TEST_SRCS)
else
NAMES = nmsis-dsp-integer
SRCS = $(shell find src/ -name "*.c")
endif

CFLAGS += -I$(abspath port/include)
CFLAGS += -I$(abspath vendor/NMSIS/DSP/Include)
CFLAGS += -I$(abspath vendor/NMSIS/DSP/PrivateInclude)
CFLAGS += -I$(abspath vendor/NMSIS/DSP/Benchmark)
CFLAGS += -I$(abspath vendor/NMSIS/DSP/Test)
CFLAGS += -I$(abspath vendor/NMSIS/DSP/Test/BasicMathFunctions)
AFLAGS += -I$(abspath port/include)

include $(BASE_PORT)/Makefile

CFLAGS += -Wno-unused-function -Wno-unused-variable -Wno-unused-but-set-variable
CFLAGS += -Wno-implicit-const-int-float-conversion -Wno-implicit-function-declaration

.PHONY: generate-tests benchmark legacy-test testing-smoke test-all run-generated-all run-benchmark run-legacy run-legacy-generated-all run-testing-smoke

generate-tests:
	python3 scripts/generate_zircon_tests.py

benchmark: generate-tests
	$(MAKE) TEST_SYSTEM=benchmark SUITE=$(SUITE) clean image

legacy-test: generate-tests
	$(MAKE) TEST_SYSTEM=legacy SUITE=$(SUITE) clean image

testing-smoke: generate-tests
	$(MAKE) TEST_SYSTEM=testing-smoke SUITE=BasicMaths clean image

run-benchmark: generate-tests
	$(MAKE) TEST_SYSTEM=benchmark SUITE=$(SUITE) run

run-legacy: generate-tests
	$(MAKE) TEST_SYSTEM=legacy SUITE=$(SUITE) run

run-legacy-generated-all: generate-tests
	@set -e; for entry in $(LEGACY_CASES); do \
		suite=$${entry%%:*}; test_case=$${entry#*:}; \
		$(MAKE) TEST_SYSTEM=legacy SUITE=$$suite TEST_CASE=$$test_case run; \
	done

run-testing-smoke: generate-tests
	$(MAKE) TEST_SYSTEM=testing-smoke SUITE=BasicMaths run

run-generated-all:
	@set -e; for suite in $(BENCHMARK_SUITES); do \
		$(MAKE) TEST_SYSTEM=benchmark SUITE=$$suite run; \
	done
	$(MAKE) TEST_SYSTEM=legacy SUITE=BasicMathFunctions run

test-all:
	$(MAKE) generate-tests
	$(MAKE) run-generated-all
