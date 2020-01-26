MAKEFLAGS= -rR

all:

AR_FLAGS = rU
DEPFLAGS= -MF $<.d -MT $@ -MD

cxx_exe:= proc_file
cxx_src:= $(wildcard *.cc)
cxx_lib:= $(filter-out $(patsubst %,%.cc,$(cxx_exe)), $(cxx_src))
obj_lib:= $(patsubst %.cc, %.o, $(cxx_lib))


libstuff.a: $(obj_lib)
	ar $(AR_FLAGS) $@.new $(obj_lib)
	mv $@.new $@
.PHONY:

all: $(cxx_exe)

%.o: %.cc cxxflags
	g++ @cxxflags -static -I. -g -E $<   -o $@.i -fPIC $(DEPFLAGS)
	g++ @cxxflags -static -I. -g -S $@.i -o $@.s -fPIC
	g++ @cxxflags -static -I. -g -c $@.s -o $@         -fPIC

$(cxx_exe): %: %.o cxxflags libstuff.a
	g++ @cxxflags -static -I. -g    $<  -o $@   -fPIC -L. -lstuff

clean:
	rm -f $(cxx_exe)
	rm -f *.[isoa]

