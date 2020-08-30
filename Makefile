

whatever: bin/report

rep_src:= 
rep_src+= lib/mm.cc
rep_src+= lib/dbg.cc
rep_src+= lib/abi.cc
rep_src+= lib/new.cc
rep_src+= lib/c_str.cc
rep_src+= lib/errno.cc
rep_src+= lib/init_array.cc
rep_src+= lib/strerror_list.cc
rep_obj:= $(patsubst %,%.o,$(rep_src))

bin/report: bin/report.cc.o $(rep_obj)
	$(LD) -static $(START) $^   -o $@

#    shit: all
#    	./bin/report ./bin/false || ./bin/report ./bin/true
#    	./bin/report ./bin/false || ./bin/report ./bin/true

all:

#    fuck: bin/markout
#    	./bin/markout /bin/ls */fuck */cat.cc

MAKEFLAGS:=-rR -j1
AR_FLAGS = rU
LD_FLAGS = @ld_flags
CPPFLAGS= @cppflags 
DEPFLAGS= -MF $<.d -MT $@ -MD
CXXFLAGS:= @cxxflags
ASMFLAGS:= @asmflags

CXX:= g++

LD= ld


BIN_SRC:=$(wildcard bin/*.cc bin/*.S)
LIB_SRC:=$(wildcard lib/*.cc lib/*.S)
LIB_SRC+=lib/strerror_list.cc

BIN_ASM:=$(patsubst %.S,  %, $(filter %.S,  $(BIN_SRC)))
BIN_CXX:=$(patsubst %.cc, %, $(filter %.cc, $(BIN_SRC)))

LIB_ASM:=$(patsubst %.S,  %, $(filter %.S,  $(LIB_SRC)))
LIB_CXX:=$(patsubst %.cc, %, $(filter %.cc, $(LIB_SRC)))

#    MYF_SRC:=$(wildcard my-file/*.cc)
#    MYF_ASM:=$(patsubst %.S,  %, $(filter %.S,  $(MYF_SRC)))
#    MYF_CXX:=$(patsubst %.cc, %, $(filter %.cc, $(MYF_SRC)))

my-file/check_print:
	@echo not making

my-file/check_print.o:
	@echo not making

lib/strerror_list.cc: script/genstrerror.pl
	rm -f lib/strerror_list*
	vi_perl $<

START:= lib/start.o
BIN_EXE:=$(BIN_CXX) $(BIN_ASM)
#    MYF_EXE:=$(MYF_CXX)

LIB_LIB:=lib/libkernpp.a
LIB_OBJ:=$(filter-out $(START), $(patsubst %,%.o,$(LIB_CXX) $(LIB_ASM)))

ALL_SRC:=$(LIB_SRC) $(BIN_SRC) 
# $(MYF_SRC)
test: all

all: $(BIN_EXE) 
	
# $(MYF_CXX)

sizes: all
	@echo sizes
	@du -k $(BIN_EXE) | sort -n | xargs -n 6 | column -t
	@echo
	@du -k */*.o */*.a | sort -n | xargs -n 6 | column -t
	@echo
	@echo

$(LIB_LIB): $(LIB_OBJ)
	ar $(AR_FLAGS) $@.new $(LIB_OBJ)
	mv $@.new $@

bin/false bin/true: START:=

.PRECIOUS: lib/start.o
$(filter-out bin/report,$(BIN_EXE)): %: %.cc.o $(START) $(LIB_LIB) ld_flags
	$(LD) -static $(START) $<  $(LIB_LIB) -o $@

%.o: %.S
	$(CXX) -g $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

ifeq (1,1)
%.cc.o: %.cc cxxflags cppflags asmflags
	$(CXX) $(CPPFLAGS) -E $< -o $(<:.cc=.cc.ii) $(DEPFLAGS)
	$(CXX) $(CXXFLAGS) -S $(<:.cc=.cc.ii)  -o $(<:.cc=.cc.s)
	$(CXX) $(ASMFLAGS) -c $(<:.cc=.cc.s)   -o $@
else
%.cc.i: %.cc cxxflags cppflags asmflags
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -E $< -o $@ $(DEPFLAGS)

%.cc.o: %.cc cxxflags cppflags asmflags
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@ $(DEPFLAGS)
endif

tags: $(wildcard */*.{cc,hh}) $(wildcard */*.{cc.hh}) Makefile
	ctags -R .
deps=$(wildcard */*.d)

depends.mk: $(deps)
	perl depends.pl $(deps) > $@

include depends.mk

clean:
	rm -f */*.o */*.ii */*.s */*.d $(BIN_EXE) $(LIB_LIB)

check_env:
	printenv
include/getopt.h: ;
