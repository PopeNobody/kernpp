MAKEFLAGS= -rR

all:

CXX:=clang++

cxx_exe:= wordexp_ex powers strerror proc_file regex forward xtest
cxx_exe+= auto_ex

cxx_src:= $(wildcard *.cc)
cxx_lib:= # $(filter-out $(patsubst %,%.cc,$(cxx_exe)), $(cxx_src))

.PHONY:

all: $(cxx_exe)

$(cxx_exe): %: %.cc cxxflags
	$(CXX) @cxxflags -static  -g -E $@.cc -o $@.i -fPIC -dD
	$(CXX) @cxxflags -static  -g -S $@.i  -o $@.s -fPIC
	$(CXX) @cxxflags -static  -g    $@.s  -o $@   -fPIC

clean:
	rm -f $(cxx_exe)
	rm -f *.[isoa]

