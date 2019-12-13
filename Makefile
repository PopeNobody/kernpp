test: test_ls


test_ls: bin/ls | all
	@echo testing $<
	#bin/ls bin # */*.[ch][ch]
	bin/ls .

test_%: bin/% | all
	@echo testing $<
	./bin/$*

test_algo: algo
	./algo * */*.[ch][ch] *.cc *.cc *.cc

algo: algo.cc
	$(CXX) algo.cc -o algo


MAKEFLAGS:=-rR
ARFLAGS = rvU

CXX:= g++
LD= ld -Map $@.map

CPP_FLAGS= -MD -MF $@.d -MT $@
CPP_FLAGS+= -Iinclude
CPP_FLAGS+= -nostdinc

CXX_FLAGS:= @cxx_flags

#bin/ls.s: CXX_FLAGS+=-fexceptions

DEPS=/dev/null

include/syscall_fwd.hh: script/genheaders.pl script/syscall.pl
	perl script/genheaders.pl > $@

BIN_CXX:=$(wildcard bin/*.cc)
BIN_GEN:=$(patsubst %.cc, %.s, $(BIN_CXX))
BIN_ASM:=$(filter-out $(BIN_GEN), $(wildcard bin/*.s))
BIN_GEN+=$(patsubst %.s, %.o, $(BIN_GEN) $(BIN_ASM))
BIN_GEN+=$(patsubst %.cc, %.ii, $(BIN_CXX))
DEPS+=$(patsubst %.cc,%.ii.d,$(BIN_CXX))

LIB_CXX:=$(filter-out lib/save_this.cc, $(wildcard lib/*.cc))
LIB_GEN:=$(patsubst %.cc, %.s, $(LIB_CXX))
LIB_ASM:=$(filter-out  lib/save_this.s $(LIB_GEN), $(wildcard lib/*.s))
LIB_OBJ:=$(patsubst %.s, %.o, $(LIB_GEN) $(LIB_ASM))
LIB_GEN+=$(LIB_OBJ)
DEPS+=$(patsubst %.cc,%.ii.d,$(LIB_CXX))

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
ifdef LINK_WITH_CXX
	$(CXX) -static -nostartfiles $(START) -o $@ $< lib/libkernpp.a
else
	$(LD) $(START) -o $@ $< lib/libkernpp.a
endif

ifdef SKIP_PREPROC
%.s: %.cc cxx_flags
	$(CXX) $(CXX_FLAGS) $(CPP_FLAGS) -S $< -o $@ 
else

%.ii: %.cc cxx_flags
	$(CXX) $(CXX_FLAGS) $(CPP_FLAGS) -E $< -o $@ 

%.s: %.ii cxx_flags
	$(CXX) $(CXX_FLAGS) $(CPP_FLAGS) -S $< -o $@ 

endif

#    bin/static.o: %.o: %.s
#    	$(CXX) -g -c $< -o $@

%.o: %.s
	$(CXX) -c $< -o $@

all: $(BIN_EXE)

bin/%.out: bin/%.sh bin/%
	bash $< > $@

test: all

clean:
	rm -f deps $(BIN_GEN) $(ASM_EXE) $(CXX_EXE) $(LIB_GEN) lib/libkernpp.a
	rm -f $(patsubst %.cc,%.d,$(BIN_CXX) $(LIB_CXX))
	touch deps

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

deps: $(wildcard $(DEPS))
	@cat $(sort $(wildcard $(DEPS))) > deps.new
	@cmp deps deps.new && rm -f deps.new && touch deps || mv -v deps.new deps

include deps

check_env:
	printenv

SOURCES:= $(wildcard */*.cc */*.hh */*.s )
tags: .PHONY
	ctags $(SOURCES)

.PHONY: test clean show all
