test:


MAKEFLAGS:=-rR
AR_FLAGS = rvU
LD_FLAGS = @ld_flags
CPPFLAGS= @cppflags 
DEPFLAGS= -MF $<.d -MT $@ -MD
CXXFLAGS:= @cxxflags

CXX:= g++
LD= ld.gold 


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
	@echo sizes
	@du -k $(BIN_EXE) | sort -n | xargs -n 6 | column -t
	@echo
	@du -k */*.o */*.a | sort -n | xargs -n 6 | column -t
	@echo
	@echo

$(LIB_LIB): $(LIB_OBJ)
	ar $(AR_FLAGS) $@ $(LIB_OBJ)

$(BIN_ASM): START:=

$(BIN_EXE): %: %.o $(START) $(LIB_LIB) cxxflags cppflags ld_flags
	$(LD) -static $(START) $<  $(LIB_LIB) -o $@

#    $(LIB_LIB): $(patsubst %, $(LIB_LIB)(%), $(LIB_OBJ))
#    	touch $@

%.o: %.S
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

#    bin/fmt.o: bin/fmt.ii
#    	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -S $<            -o $(<:.ii=.s)
#    	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(<:.ii=.s)   -o $@

%.o: %.cc cxxflags cppflags
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
