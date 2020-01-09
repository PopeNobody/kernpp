MAKEFLAGS= -rR

all:

cxx_exe:= wordexp_ex powers strerror
cxx_src:= $(wildcard *.cc)
cxx_lib:= # $(filter-out $(patsubst %,%.cc,$(cxx_exe)), $(cxx_src))

.PHONY:

all: $(cxx_exe)

$(cxx_exe): %: %.cc
	g++ -static -g -E $@.cc -o $@.i -fPIC -dD
	g++ -static -g -S $@.i -o $@.s -fPIC
	g++ -static -g -c $@.s -o $@.o -fPIC
	g++ -static -g    $@.o -o $@ -fPIC

clean:
	rm -f $(cxx_exe)
	rm -f *.[isoa]

