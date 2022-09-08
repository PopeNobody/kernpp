test:

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
CXX_BIN:=$(patsubst %.cc,%,$(BIN_CXX))
ASM_BIN:=$(patsubst %.S,%,$(BIN_ASM))
BIN_BIN:=$(CXX_BIN) $(ASM_BIN)

LIB_ASM:=$(wildcard lib/*.S)
LIB_CXX:=$(wildcard lib/*.cc)
LIB_OBJ:=$(patsubst %.cc,%.cc.o,$(LIB_CXX))
LIB_OBJ+=$(patsubst %.S,%.S.o,$(LIB_ASM))

lib/strerror_list.cc: script/genstrerror.pl
	rm -f lib/strerror_list*
	vi_perl $<

START:= lib/start.S.o
LIB_LIB:=lib/libkernpp.a

$(LIB_LIB): $(LIB_OBJ)
	ar $(AR_FLAGS) $@.new $(LIB_OBJ)
	mv $@.new $@

.PRECIOUS: lib/start.S.o

$(ASM_BIN): %: %.S.o 
	$(LD) -static $< -o $@

$(CXX_BIN): %: %.cc.o $(START) $(LIB_LIB)
	$(LD) -static $(START) $<  $(LIB_LIB) -o $@

$(filter %.S.o,$(LIB_OBJ)): %.S.o: %.S
	$(CXX) -g $(CPPFLAGS) $(CXXFLAGS) $(ASMFLAGS) -c $< -o $@

$(filter %.cc.o,$(LIB_OBJ)): %.cc.o: %.cc  etc/asmflags etc/cppflags etc/cxxflags
	$(CXX) -g $(CPPFLAGS) $(CXXFLAGS) $(ASMFLAGS) -c $< -o $@

$(filter %.cc.o, $(BIN_OBJ)): %.cc.o: %.cc etc/asmflags etc/cppflags etc/cxxflags
	$(CXX) -g $(CPPFLAGS) $(CXXFLAGS) $(ASMFLAGS) -c $< -o $@

$(filter %.S.o,$(BIN_OBJ)): %.S.o: %.S etc/asmflags etc/cppflags etc/cxxflags
	$(CXX) -g $(CPPFLAGS) $(CXXFLAGS) $(ASMFLAGS) -c $< -o $@


deps=$(wildcard */*.d)

depends.mk: $(deps)
	perl depends.pl $(deps) > $@

include depends.mk

clean:
	rm -f */*.cc.o */*.cc.ii */*.cc.s */*.cc.d $(BIN_EXE) $(LIB_LIB)

test: $(BIN_BIN)
	perl test.pl $(BIN_BIN)

$(patsubst %,%_test,$(BIN_BIN)): %_test: %
	perl test.pl $<

