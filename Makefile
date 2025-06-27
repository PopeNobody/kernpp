MAKEFLAGS+= -rR -j1
#export override PATH:=$(PWD)/sbin:$(PATH)
SHELL:=/bin/bash -e
all: lib bin tst
CXX:=/opt/bin/clang++
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
c++/tst:=$(filter tst/%,$(c++/obj:.cc.oo=))
c++/lib:=$(filter lib/%,$(c++/obj))

all: $(c++/exe) $(asm/exe) $(lib/lib)

src/asm:=$(wildcard */*.S)
asm/obj:=$(src/asm:.S=.S.oo)
asm/lib:=$(filter lib/%,$(asm/obj))

c++/obj: $(c++/obj)

asm/obj: $(asm/obj)

tst/obj: $(tst/obj)

obj: $(c++/obj)
lib: $(lib/lib)

$(lib/lib): $(asm/lib) $(c++/lib)
	ar r $@ $(asm/lib) $(c++/lib)
	ranlib $@

all/obj:= $(c++/obj) $(asm/obj)

all/exe:=$(c++/exe) $(c++/tst) $(asm/exe)

all: $(all/exe)

#    include etc/one-step.mk
include etc/multi.mk

bin/_start: lib/lib:=

$(c++/tst): %: %.cc.oo etc/ld_flags lib
	$(CXX) -o $@ $< -Wl,--start-group $(lib/lib) @etc/ld_flags -Wl,--end-group

$(c++/exe): %: %.cc.oo etc/ld_flags lib
	$(CXX) -o $@ $< -Wl,--start-group $(lib/lib) @etc/ld_flags -Wl,--end-group


/dev/null:;
%.mk:;
Makefile:;

clean:
	rm -f $(c++/exe) $(asm/exe) $(lnk/exe)
	rm -f $(c++/obj) $(asm/obj)
$(warning $(all/exe))
all: $(all/exe) $(tgt/all)
	echo made all
	printf '%s\n' $(all/exe) | sort .gitignore -u -o .gitignore -
