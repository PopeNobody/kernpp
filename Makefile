test:


MAKEFLAGS:=-rR
AR_FLAGS = rvU
LD_FLAGS = -static -nostartfiles -nostdlib
CPPFLAGS= @cpp_flags 
DEPFLAGS= -MF $<.d -MT $@ -MD
CXXFLAGS:= @cxx_flags

CXX:= g++
LD= ld 


BIN_SRC:=$(wildcard bin/*.cc bin/*.S)
LIB_SRC:=$(wildcard lib/*.cc lib/*.S)


BIN_ASM:=$(patsubst %.S,  %, $(filter %.S,  $(BIN_SRC)))
BIN_CXX:=$(patsubst %.cc, %, $(filter %.cc, $(BIN_SRC)))

LIB_ASM:=$(patsubst %.S,  %, $(filter %.S,  $(LIB_SRC)))
LIB_CXX:=$(patsubst %.cc, %, $(filter %.cc, $(LIB_SRC)))

START:= lib/start.o
BIN_EXE:=$(BIN_CXX) $(BIN_ASM)
LIB_LIB:=lib/libkernpp.a
LIB_OBJ:=$(filter-out $(START), $(patsubst %,%.o,$(LIB_CXX) $(LIB_ASM)))
ALL_SRC:=$(LIB_SRC) $(BIN_SRC)
test: all

all: $(BIN_EXE)

(%): %
	flock $(LIB_LIB).lock ar $(AR_FLAGS) $@ $<

$(BIN_ASM): START:=

$(BIN_EXE): %: %.o $(START) $(LIB_LIB) cxx_flags cpp_flags
	$(CXX) $(START) $(LD_FLAGS) $(CXXFLAGS) $<  $(LIB_LIB) -o $@

$(LIB_LIB): $(patsubst %, $(LIB_LIB)(%), $(LIB_OBJ))
	touch $@

%.o: %.S
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

#    bin/fmt.o: bin/fmt.ii
#    	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -S $<            -o $(<:.ii=.s)
#    	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(<:.ii=.s)   -o $@

%.o: %.cc cxx_flags cpp_flags
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -E $< -o $(<:.cc=.ii) $(DEPFLAGS)
	$(CXX) $(CXXFLAGS) -S $(<:.cc=.ii)  -o $(<:.cc=.s)
	$(CXX) $(CXXFLAGS) -c $(<:.cc=.s)   -o $@

tags:
	ctags -R .

$(ALL_SRC) $(ALL_SRC:=.d):;

include /dev/null $(wildcard $(ALL_SRC:=.d))

clean:
	rm -f */*.o */*.ii */*.s */*.d $(BIN_EXE) $(LIB_LIB)

check_env:
	printenv
