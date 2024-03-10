#*******************************************************************************
# Creator:        Hai Cao Xuan (cxhai.sdh221@hcmut.edu.vn)
# Description:    makefile
#*******************************************************************************
# Copyright (c) 2022 Hai Cao Xuan
#*******************************************************************************

FILES := $(shell cat filelist)

VERILATOR = verilator
VERILATOR_COV = verilator_coverage

SDL_CFLAGS = `sdl2-config --cflags`
SDL_LDFLAGS = `sdl2-config --libs`

### LINT FLAGS
LINT_FLAGS = -Wall --lint-only -sv

### VERILATE FLAGS
# Generate C++ in executable form
VERILATOR_FLAGS += -sv -cc
# Optimize
VERILATOR_FLAGS += -x-initial unique
VERILATOR_FLAGS += -x-assign unique
VERILATOR_FLAGS += -O3 -CFLAGS -DCOVERAGE

VERILATOR_FLAGS += -CFLAGS "${SDL_CFLAGS}" -LDFLAGS "${SDL_LDFLAGS}"

# Input files for Verilator
VERILATOR_INPUT = $(FILES) top.sv --top-module top

.PHONY: lint
lint:
	@echo "------------------> LINT CHECK <------------------"
	@$(VERILATOR) $(LINT_FLAGS) $(FILES)

.PHONY: build
build: ./obj_dir/Vtop
./obj_dir/Vtop: $(FILES) top.sv test/tb_top.cpp
	@echo "-------------------> BUILD <----------------------"
	@$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INPUT) --exe test/tb_top.cpp
	make -C ./obj_dir -f Vtop.mk

.PHONY: sim
sim: ./obj_dir/Vtop
	@echo "-----------------> SIMULATING <-------------------"
	@./obj_dir/Vtop



.PHONY: clean
clean:
	@rm -rf obj_dir
	@echo "-----------------> ALL CLEAN <--------------------"
