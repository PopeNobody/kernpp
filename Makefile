#export override PATH:=$(PWD)/sbin:$(PATH)
test:
all:
include etc/vars.mk
etc/multi.mk:;
etc/cxxflags:;
etc/ld_flags:;
etc/cppflags:;
etc/asmflags:;

all: lib bin tst

test: all

#CXX:=/opt/bin/clang++
lib/lib:=lib/libkernpp.aa
tgt/all:=$(lib/lib)
show= $(warning $1: $($1))
$(deps):;

c++/src:=$(wildcard */*.cc)
c++/obj:=$(c++/src:.cc=.cc.oo)

c++/asm:=$(c++/src:.cc=.cc.SS)
c++/cpp:=$(c++/src:.cc=.cc.ii)
c++/dep:=$(c++/src:.cc=.cc.dd)
c++/exe:=$(filter bin/% tst/%,$(c++/src:.cc=))
c++/tst:=$(filter tst/%,$(c++/obj:.cc.oo=))
c++/lib:=$(filter lib/%,$(c++/obj))
#$(foreach x,src obj exe lib,$(call show,c++/$x))

all: $(c++/exe) $(asm/exe) $(lib/lib)

asm/src:=$(wildcard */*.S)
asm/obj:=$(asm/src:.S=.S.oo)
asm/lib:=$(filter lib/%,$(asm/obj))
asm/exe:=$(filter bin/%,$(asm/src:.S=))

scr/genheaders.pl:;

#$(c++/cpp) $(asm/obj): inc/syscall.gen.hh lib/syscall.gen.cc

TRS/dep:=$(filter-out $(c++/dep),$(wildcard */*.cc.dd))
ifneq ($(TRS/dep),)
$(foreach f,$(wildcard $(lib/lib) $(TRS/dep)),$(warning reap: $f)$(shell rm -f $f))
endif
include /dev/null $(wildcard */*.cc.dd)

all: $(c++/exe) $(asm/exe) $(lib/lib) bin/printenv

bin/printenv: bin/echo
	ln -f $< $@

$(c++/cpp): inc/syscall.gen.hh lib/syscall.gen.cc

obj: $(c++/obj) $(asm/obj) 
lib: $(lib/lib)

$(lib/lib): $(asm/lib) $(c++/lib)
	ar r $@ $(asm/lib) $(c++/lib)
	ranlib $@

all/obj:= $(c++/obj) $(asm/obj)

all/exe:=$(c++/exe) $(c++/tst) $(asm/exe)

all: $(all/exe)

FORCE:

.PHONY: FORCE

scr/syscall.gen.hh scr/syscall.gen.cc: scr/genheaders.pl
	vi-perl scr/genheaders.pl

lib/syscall.gen.cc: scr/syscall.gen.cc
	cp $< $@
	ls -l $@

inc/syscall.gen.hh: scr/syscall.gen.hh
	cp $< $@
	ls -l $@

include etc/multi.mk

$(asm/obj): %.S.oo: %.S etc/asmflags
	$(CXX) -o $@ $< @etc/aflags -c

$(asm/exe): %: %.S.oo etc/ld_flags $(lib/lib)
	$(CXX) -o $@ -Wl,--start-group $< $(lib/lib) @etc/ld_flags -Wl,--end-group
#    	$< $(lib/lib) @etc/ld_flags 


all: $(c++/obj)


$(c++/exe): %: %.cc.oo etc/ld_flags $(lib/lib)
	$(CXX) -o $@ -Wl,--start-group $< $(lib/lib) @etc/ld_flags -Wl,--end-group

c++/gen:= inc/syscall.gen.hh lib/syscall.gen.cc

/dev/null:;
%.mk:;
Makefile:;

clean:
	rm -f $(c++/gen)  $(warning $(c++/gen))
	@rm -f $(asm/exe)
	@rm -f $(asm/obj)
	@rm -f $(c++/asm)
	@rm -f $(c++/cpp)
	@rm -f $(c++/dep)
	@rm -f $(c++/exe)
	@rm -f $(c++/obj)
	@rm -f $(lib/lib)
T:=
all: $(all/exe) $(tgt/all)
	$(if $T, env LDFLAGS=-static CFLAGS=-ggdb3\ -O0 CXXFLAGS=-ggdb3\ -O0\ -std=c++23 MAKEFLAGS= make -f /dev/null $T)
	@echo made all
	@printf '%s\n' $(asm/exe) $(c++/exe) | sort .gitignore -u -o .gitignore -
