MAKEFLAGS+= -rR -j1
#export override PATH:=$(PWD)/sbin:$(PATH)
SHELL:=/bin/bash -xe
all: lib bin tst

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
	g++  -o $@ -c $< @etc/cxxflags @etc/cppflags -MD

%.cc.ii: %.cc  etc/cxxflags etc/cppflags
	g++  -o $@ -E $< @etc/cxxflags @etc/cppflags -MD

all: $(c++/obj)


$(c++/exe): %: %.cc.oo etc/ld_flags lib
	g++ -o $@ $< $(lib/lib) @etc/ld_flags


/dev/null:;
%.mk:;
Makefile:;

clean:
	rm -f $(tgt/all)

all: $(tgt/all)
	@echo made all
