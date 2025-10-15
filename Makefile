#export override PATH:=$(PWD)/sbin:$(PATH)
test:
all:
include etc/vars.mk
etc/multi.mk etc/cxxflags etc/ld_flags etc/cppflags etc/asmflags:;
all: lib bin tst

test: all

lib/lib:=lib/libkernpp.aa
lib/lsc:=libsc/libsc.aa
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

all: $(c++/exe) $(asm/exe)


asm/src:=$(wildcard */*.S)
asm/obj:=$(asm/src:.S=.S.oo)
asm/lib:=$(filter lib/%,$(asm/obj))
asm/exe:=$(filter bin/%,$(asm/src:.S=))
asm/lsc:=$(filter libsc/%,$(asm/src:.S=.S.oo))
$(c++/exe) $(asm/exe): $(lib/lib)
scr/genheaders.pl:;

#$(c++/cpp) $(asm/obj): inc/syscall.gen.hh lib/syscall.gen.cc

all_deps:=$(wildcard */*.dd)
c++_deps:=$(foreach s,$(wildcard */*.cc),$(wildcard $s.dd)))
oth_deps:=$(filter-out $(c++_deps),$(all_deps))
#    show=$(warning $1:=$($1))
#    $(foreach v,all_deps c++_deps oth_deps,$(call show,$v))
#    $(if $(oth_deps),$(eval pre-clean+=$(oth_deps)))
#    
#    $(if $(oth_deps),$(eval pre-clean: ; rm -f $(oth_deps)))
#    pre-clean:
#    $(all_deps): pre-clean
include /dev/null $(wildard $(c++_deps))

all: $(c++/exe) $(asm/exe) $(lib/lib) 

#all: bin/printenv

#bin/printenv: bin/echo
#	ln -f $< $@

$(c++/cpp): inc/syscall.gen.hh lib/syscall.gen.cc

obj: $(c++/obj) $(asm/obj) 
lib: $(lib/lib) $(lib/lsc)

$(lib/lsc): $(sort $(asm/lsc))
	ar r $@ $(asm/lsc) $(c++/lsc)
	ranlib $@

$(lib/lib): $(sort $(asm/lib) $(c++/lib))
	ar r $@ $(asm/lib) $(c++/lib)
	ranlib $@

all/obj:= $(c++/obj) $(asm/obj)

all/exe:=$(c++/exe) $(c++/tst) $(asm/exe)

all: $(all/exe)

FORCE:

.PHONY: FORCE

inc/syscall.gen.hh lib/syscall.gen.cc: scr/genheaders.pl
	vi-perl scr/genheaders.pl
	mv gen/syscall.gen.hh inc/syscall.gen.hh
	mv gen/syscall.gen.cc lib/syscall.gen.cc
	rm -f lib/syscall.gen.cc.*


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

#$(warning $(filter c++/%,$(.VARIABLES)) )
#$(warning $(filter asm/%,$(.VARIABLES)) )
#vars := $(foreach l,c++ asc,$(foreach o,cpp asm obj exe,$l/$o))

T:=

all:
	$(if $T, env LDFLAGS=-static CFLAGS=-ggdb3\ -O0 CXXFLAGS=-ggdb3\ -O0\ -std=c++23 MAKEFLAGS= make -f /dev/null $T)
	@echo made all
	@printf '%s\n' $(asm/exe) $(c++/exe) | sort .gitignore -u -o .gitignore -
