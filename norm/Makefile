MAKEFLAGS= -rR

all:

CXX:=clang++

cxx_exe:= wordexp_ex powers strerror proc_file regex forward xtest
cxx_exe+= auto_ex

cxx_src:= $(wildcard *.cc)
cxx_lib:= # $(filter-out $(patsubst %,%.cc,$(cxx_exe)), $(cxx_src))

.PHONY:

all: $(cxx_exe)

$(cxx_exe): %: %.cc cxxflags cppflags asmflags
	$(CXX) @cppflags -static  -g -E $@.cc -o $@.ii -fPIC -dD
	$(CXX) @cxxflags -static  -g -S $@.ii -o $@.sx -fPIC
	$(CXX) @asmflags -static  -g    $@.ss -o $@    -fPIC

clean:
	rm -f $(cxx_exe)
	rm -f *.[isoa] *.[isoa][isoa]

