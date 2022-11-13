all:
	
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

MAKEFLAGS+= -rR -j1
AR_FLAGS= rU
LD_FLAGS= @etc/ld_flags
CPPFLAGS= @etc/cppflags 
DEPFLAGS= -MF $<.d -MT $@ -MD
CXXFLAGS:= @etc/cxxflags
ASMFLAGS:= @etc/asmflags

CXX:= g++

LD= ld


BIN_ASM:=$(wildcard bin/*.S)
BIN_CXX:=$(wildcard bin/*.cc)
BIN_OBJ:=$(patsubst %.cc,%.cc.o,$(BIN_CXX))
BIN_OBJ+=$(patsubst %.S,%.S.o,$(BIN_ASM))

LIB_ASM:=$(wildcard lib/*.S)
LIB_CXX:=$(wildcard lib/*.cc)
LIB_OBJ:=$(patsubst %.cc,%.cc.o,$(LIB_CXX))
LIB_OBJ+=$(patsubst %.S,%.S.o,$(LIB_ASM))

lib/strerror_list.cc: script/genstrerror.pl
	rm -f lib/strerror_list*
	vi_perl $<

START:= lib/start.o
LIB_LIB:=lib/libkernpp.a

LO1:=$(patsubst %.cc,%.cc.o,$(LIB_CXX))
LO2:=$(filter-out $(START),$(LO1)) 
LO3:=$(sort $(LO2))
LIB_OBJ:=$(LO3)

BIN_EXE:=$(patsubst %.cc,%,$(BIN_CXX))
BIN_EXE+=$(patsubst %.S,%,$(BIN_ASM))

all: $(BIN_EXE) 


$(LIB_LIB): $(LIB_OBJ)
	ar $(AR_FLAGS) $@.new $(LIB_OBJ)
	mv $@.new $@

bin/false bin/true: START:=

.PRECIOUS: lib/start.o
$(filter-out bin/report,$(BIN_EXE)): %: %.cc.o $(START) $(LIB_LIB)
	$(LD) -static $(START) $<  $(LIB_LIB) -o $@

%.S.o: %.S
	$(CXX) -g $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(LIB_OBJ): %.cc.o: %.cc  etc/asmflags etc/cppflags etc/cxxflags fakefile
	@echo $@
#    	$(CXX) $(CPPFLAGS) -E $< -o $(<:.cc=.cc.ii) $(DEPFLAGS)
#    	$(CXX) $(CXXFLAGS) -S $(<:.cc=.cc.ii)  -o $(<:.cc=.cc.s)
#    	$(CXX) $(ASMFLAGS) -c $(<:.cc=.cc.s)   -o $@

deps=$(wildcard */*.d)

depends.mk: $(deps)
	perl depends.pl $(deps) > $@

include depends.mk

clean:
	rm -f */*.cc.o */*.cc.ii */*.cc.s */*.cc.d $(BIN_EXE) $(LIB_LIB)
