MAKEFLAGS+= -rR -j1
#export override PATH:=$(PWD)/sbin:$(PATH)
DISTCC_HOSTS:=localhost/1 10.1.3.102/24
SHELL:=/bin/bash -xe
all: lib bin tst
CXX:=$(HOME)/bin/dist-clang++
tgt/lib:=lib/libkernpp.aa
lib/lib:=lib/libkernpp.aa

deps:= $(sort $(wildcard */*.d))
cxxs:= $(sort $(wildcard */*.cc))
objs:= $(sort $(wildcard */*.oo))
include etc/resolve.mk
include etc/rules.mk
include $(wildcard $(deps))
$(deps):;

src/c++:=$(wildcard */*.cc)
c++/obj:=$(src/c++:.cc=.cc.oo)
c++/exe:=$(filter bin/%,$(c++/obj:.cc.oo=))
c++/lib:=$(filter lib/%,$(c++/obj))

all: $(c++/exe) $(asm/exe) $(lib/lib)

src/asm:=$(wildcard */*.S)
asm/obj:=$(src/asm:.S=.oo)
asm/lib:=$(filter lib/%,$(asm/obj))


lib: $(lib/lib)

$(lib/lib): $(asm/lib) $(c++/lib)
	ar r $@ $(asm/lib) $(c++/lib)
	ranlib $@

all/obj:= $(c++/obj) $(asm/obj)

$(asm/obj): %.oo: %.S etc/asmflags
	as -o $@ $< @etc/asmflags


$(c++/obj): %.cc.oo: %.cc  etc/cxxflags etc/cppflags
	$(CXX)  -o $@ -c $< @etc/cxxflags @etc/cppflags -MD

%.cc.ii: %.cc  etc/cxxflags etc/cppflags
	$(CXX)  -o $@ -E $< @etc/cxxflags @etc/cppflags -MD

all: $(c++/obj)


$(c++/exe): %: %.cc.oo etc/ld_flags lib
	$(CXX) -o $@ $< $(lib/lib) @etc/ld_flags


/dev/null:;
%.mk:;
Makefile:;

clean:
	rm -f $(c++/exe) $(asm/exe) $(lnk/exe)
	rm -f $(c++/obj) $(asm/obj)

all: $(tgt/all)
	@echo made all
	@printf '%s\n' $(bin/exe) | sort bin/.gitignore -u -o bin/.gitignore -
