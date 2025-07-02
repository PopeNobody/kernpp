MAKEFLAGS+= -rR -j1
#export override PATH:=$(PWD)/sbin:$(PATH)
DISTCC_HOSTS:=localhost/1 10.1.3.102/24
SHELL:=/bin/bash -e
all: lib bin tst
CXX:=$(HOME)/bin/dist-clang++
lib/lib:=lib/libkernpp.aa
tgt/all:=$(lib/lib)
show= $(warning $1: $($1))
deps:= $(sort $(wildcard */*.d) $(wildcard */*.dd))
cxxs:= $(sort $(wildcard */*.cc))
objs:= $(sort $(wildcard */*.oo))
include /dev/null $(wildcard $(deps))
$(deps):;

c++/src:=$(wildcard */*.cc)
c++/obj:=$(c++/src:.cc=.cc.oo)
c++/exe:=$(filter bin/% tst/%,$(c++/src:.cc=))
c++/lib:=$(filter lib/%,$(c++/obj))
#$(foreach x,src obj exe lib,$(call show,c++/$x))

asm/src:=$(wildcard */*.S)
asm/obj:=$(asm/src:.S=.S.o)
asm/lib:=$(filter lib/%,$(asm/obj))
asm/exe:=$(filter bin/%,$(asm/src:.S=))

all: $(c++/exe) $(asm/exe) $(lib/lib)

obj: $(c++/obj) $(asm/obj)
lib: $(lib/lib)

$(lib/lib): $(asm/lib) $(c++/lib)
	ar r $@ $(asm/lib) $(c++/lib)
	ranlib $@

all/obj:= $(c++/obj) $(asm/obj)

$(asm/obj): %.S.o: %.S etc/asmflags
	as -o $@ $< @etc/asmflags

$(asm/exe): %: %.S.o etc/ld_flags $(lib/lib)
	$(CXX) -o $@ -Wl,--start-group $< $(lib/lib) @etc/ld_flags -Wl,--end-group
#    	$< $(lib/lib) @etc/ld_flags 



$(c++/obj): %.cc.oo: %.cc  etc/cxxflags etc/cppflags
	$(CXX)  -o $@ -c $< @etc/cxxflags @etc/cppflags

$(c++/cpp): %.cc.ii: %.cc  etc/cxxflags etc/cppflags
	$(CXX)  -o $@ -E $< @etc/cxxflags @etc/cppflags

all: $(c++/obj)


$(c++/exe): %: %.cc.oo etc/ld_flags $(lib/lib)
	$(CXX) -o $@ -Wl,--start-group $< $(lib/lib) @etc/ld_flags -Wl,--end-group


/dev/null:;
%.mk:;
Makefile:;

clean:
	rm -f $(c++/exe) $(asm/exe) $(lib/lib)
	rm -f $(c++/obj) $(asm/obj)
	rm -f $(c++/asm) $(c++/cpp)

all: $(tgt/all)
	@echo made all
	@printf '%s\n' $(asm/exe) $(c++/exe) | sort .gitignore -u -o .gitignore -
