all:
MAKEFLAGS+=-rR

AR_FLAGS= rU
LD_FLAGS= @etc/ld_flags
CPPFLAGS= @etc/cppflags 
DEPFLAGS= -MF $<.d -MT $@ -MD
CXXFLAGS:= @etc/cxxflags
ASMFLAGS:= @etc/asmflags

CXX:= g++

LD= ld


START:= lib/start.S.o

BIN_ASM:=$(wildcard bin/*.S)
BIN_CXX:=$(wildcard bin/*.cc)
BIN_CXX_OBJ:=$(patsubst %.cc,%.cc.o,$(BIN_CXX))
BIN_ASM_OBJ:=$(patsubst %.S,%.S.o,$(BIN_ASM))
BIN_OBJ:=$(BIN_CXX_OBJ) $(BIN_ASM_OBJ)
BIN_CXX_EXE:=$(patsubst %.cc,%,$(BIN_CXX))
BIN_ASM_EXE:=$(patsubst %.S,%,$(BIN_ASM))

LIB_ASM:=$(filter-out lib/start.S, $(wildcard lib/*.S))
LIB_CXX:=$(wildcard lib/*.cc)
LIB_CXX_OBJ:=$(patsubst %.cc,%.cc.o,$(LIB_CXX))
LIB_ASM_OBJ:=$(patsubst %.S,%.S.o,$(LIB_ASM))
LIB_OBJ:=$(LIB_CXX_OBJ) $(LIB_ASM_OBJ)

CXX_OBJ:=$(LIB_CXX_OBJ) $(BIN_CXX_OBJ)
ASM_OBJ:=$(LIB_ASM_OBJ) $(BIN_ASM_OBJ)
ALL_CXX:=$(LIB_CXX) $(BIN_CXX)

lib/strerror_list.cc: script/genstrerror.pl
	rm -f lib/strerror_list*
	vi_perl $<

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

.PRECIOUS: lib/start.S.o
$(BIN_CXX_EXE): %: %.cc.o $(START) $(LIB_LIB) etc/ld_flags
	$(LD) @etc/ld_flags $(START) $<  $(LIB_LIB) -o $@

$(BIN_ASM_EXE): %: %.S.o etc/ld_flags
	$(LD) @etc/ld_flags $< -o $@

%.S.o: %.S
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

%.cc.o: %.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

%.cc.d: %.cc.o
	@true

$(CXX_OBJ): %.cc.o: %.cc  etc/asmflags etc/cppflags etc/cxxflags
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@ $(DEPFLAGS)
	$(CXX) $(CPPFLAGS) -E $< -o $(<:.cc=.cc.ii) $(DEPFLAGS)
	$(CXX) $(CXXFLAGS) -S $(<:.cc=.cc.ii)  -o $(<:.cc=.cc.s)
	$(CXX) $(ASMFLAGS) -c $(<:.cc=.cc.s)   -o $@

deps=$(patsubst %,%.d,$(ALL_CXX))

depends.mk: $(deps) Makefile depends.pl
	vi_perl depends.pl $(deps) > $@.new && mv $@.new $@

include depends.mk

tags: alldeps
	ctags $(cat alldeps)

clean:
	rm -f */*.cc.o */*.cc.ii */*.cc.s */*.cc.d $(BIN_EXE) $(LIB_LIB)
