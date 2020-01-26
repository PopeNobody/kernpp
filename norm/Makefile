MAKEFLAGS= -rR

all:

cxx_exe:= wordexp_ex powers strerror proc_file
cxx_src:= $(wildcard *.cc)
cxx_lib:= # $(filter-out $(patsubst %,%.cc,$(cxx_exe)), $(cxx_src))

.PHONY:

all: $(cxx_exe)

$(cxx_exe): %: %.cc cxxflags
	g++ @cxxflags -static -I. -g -E $@.cc -o $@.i -fPIC -dD
	g++ @cxxflags -static -I. -g -S $@.i  -o $@.s -fPIC
	g++ @cxxflags -static -I. -g    $@.s  -o $@   -fPIC

clean:
	rm -f $(cxx_exe)
	rm -f *.[isoa]

