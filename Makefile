test:

MAKEFLAGS:=-rR
ARFLAGS = rvU

CXX:= g++
LD:= ld

CPP_FLAGS= -MD -MF $@.d
CPP_FLAGS+= -Iinc
CPP_FLAGS+= -nostdinc

CXX_FLAGS:=
CXX_FLAGS+= -fno-rtti
CXX_FLAGS+= -fno-exceptions
CXX_FLAGS+= -fno-chkp-instrument-calls
CXX_FLAGS+= -ffast-math
CXX_FLAGS+= -fno-PIC
CXX_FLAGS+= -fno-chkp-check-incomplete-type
CXX_FLAGS+= -fno-chkp-check-read
CXX_FLAGS+= -fno-chkp-check-write
CXX_FLAGS+= -fno-chkp-instrument-calls
CXX_FLAGS+= -fno-chkp-narrow-bounds
CXX_FLAGS+= -fno-chkp-optimize
CXX_FLAGS+= -fno-chkp-store-bounds
CXX_FLAGS+= -fno-chkp-use-static-bounds
CXX_FLAGS+= -fno-chkp-use-static-const-bounds
CXX_FLAGS+= -fno-chkp-use-wrappers
CXX_FLAGS+= -fno-chkp-instrument-calls
CXX_FLAGS+= -fomit-frame-pointer
CXX_FLAGS+= -fno-stack-protector
CXX_FLAGS+= -fverbose-asm

BIN_CXX:=$(wildcard bin/*.cc)
BIN_GEN:=$(patsubst %.cc, %.s, $(BIN_CXX))
BIN_ASM:=$(filter-out $(BIN_GEN), $(wildcard bin/*.s))
BIN_GEN+=$(patsubst %.s, %.o, $(BIN_GEN) $(BIN_ASM))

LIB_CXX:=$(wildcard lib/*.cc)
LIB_GEN:=$(patsubst %.cc, %.s, $(LIB_CXX))
LIB_ASM:=$(filter-out $(LIB_GEN), $(wildcard lib/*.s))
LIB_OBJ:=$(patsubst %.s, %.o, $(LIB_GEN) $(LIB_ASM))
LIB_GEN+=$(LIB_OBJ)

ASM_EXE:=$(patsubst %.s, %, $(BIN_ASM))
CXX_EXE:=$(patsubst %.cc, %, $(BIN_CXX))
BIN_EXE:=$(ASM_EXE) $(CXX_EXE)

.PRECIOUS: $(BIN_GEN) $(LIB_GEN)

(%): %
	ar $(ARFLAGS) $@ $<

lib/libkernpp.a: $(patsubst %, lib/libkernpp.a(%), $(LIB_OBJ)) $(START)

$(ASM_EXE): %: %.o
	$(LD) -o $@ $<

$(CXX_EXE): %: %.o lib/start.o lib/libkernpp.a
	$(LD) $(START) -o $@ $< lib/libkernpp.a

%.s: %.cc
	$(CXX) $(CXX_FLAGS) $(CPP_FLAGS) -S $< -o $@

%.o: %.s
	$(CXX) -c $< -o $@

all: $(BIN_EXE)

bin/%.out: bin/%.sh bin/%
	bash $< > $@

test: all $(patsubst %,%.out,$(BIN_EXE))

clean:
	rm -f $(BIN_GEN) $(ASM_EXE) $(CXX_EXE) $(LIB_GEN) lib/libkernpp.a

show:
	@echo ASM_EXE=$(ASM_EXE)
	@echo CXX_EXE=$(CXX_EXE)
	@echo
	@echo BIN_ASM=$(BIN_ASM)
	@echo BIN_CXX=$(BIN_CXX)
	@echo BIN_EXE=$(BIN_EXE)
	@echo BIN_GEN=$(BIN_GEN)
	@echo
	@echo LIB_ASM=$(LIB_ASM)
	@echo LIB_CXX=$(LIB_CXX)
	@echo LIB_GEN=$(LIB_GEN)
	@echo LIB_OBJ=$(LIB_OBJ)

Makefile: ;
	
deps:
	touch deps

include deps

.PHONY: test clean show all
