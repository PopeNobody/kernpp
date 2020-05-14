
all:

fuck: bin/markout
	./bin/markout /bin/ls */fuck */cat.cc

MAKEFLAGS:=-rR -j8
AR_FLAGS = rU
LD_FLAGS = @ld_flags
CPPFLAGS= @cppflags 
DEPFLAGS= -MF $<.d -MT $@ -MD
CXXFLAGS:= @cxxflags
ASMFLAGS:= @asmflags

CXX:= clang++
LD= ld


BIN_SRC:=$(wildcard bin/*.cc bin/*.S)
LIB_SRC:=$(wildcard lib/*.cc lib/*.S)


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
%: %.o $(START) $(LIB_LIB) ld_flags
	$(LD) -static $(START) $<  $(LIB_LIB) -o $@

%.o: %.S
	$(CXX) -g $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

%.o: %.cc cxxflags cppflags asmflags
	$(CXX) $(CPPFLAGS) -E $< -o $(<:.cc=.ii) $(DEPFLAGS)
	$(CXX) $(CXXFLAGS) -S $(<:.cc=.ii)  -o $(<:.cc=.s)
	$(CXX) $(ASMFLAGS) -c $(<:.cc=.s)   -o $@

tags: $(wildcard */*.{cc,hh}) $(wildcard */*.{cc.hh}) Makefile
	ctags -R .

include /dev/null $(wildcard $(ALL_SRC:=.d))

clean:
	rm -f */*.o */*.ii */*.s */*.d $(BIN_EXE) $(LIB_LIB)

check_env:
	printenv
include/getopt.h: ;
