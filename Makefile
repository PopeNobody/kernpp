test:
all:
include etc/vars.mk etc/util.mk
etc/multi.mk etc/cxxflags etc/ld_flags etc/cppflags etc/asmflags:;
all: lib bin tst

test: all

lib/lib:=lib/libkernpp.aa
abi/lib:=abi/libabi.aa

show= $(warning $1: $($1))

c++/src:=$(wildcard */*.cc)
c++/dep:=$(c++/src:.cc=.cc.dd)
c++/obj:=$(c++/src:.cc=.cc.oo)

c++/asm:=$(c++/src:.cc=.cc.SS)
c++/cpp:=$(c++/src:.cc=.cc.ii)
c++/dep:=$(c++/src:.cc=.cc.dd)
c++/exe:=$(filter bin/% tst/%,$(c++/src:.cc=))
c++/tst:=$(filter tst/%,$(c++/obj:.cc.oo=))
c++/lib:=$(filter lib/%,$(c++/obj))
c++/abi:=$(filter abi/%,$(c++/obj))
all: $(c++/exe) $(asm/exe)


asm/src:=$(wildcard */*.S)
asm/obj:=$(asm/src:.S=.S.oo)
asm/lib:=$(filter lib/%,$(asm/obj))
asm/exe:=$(filter bin/%,$(asm/src:.S=))
asm/abi:=$(filter abi/%,$(asm/obj))
$(c++/exe) $(asm/exe): $(lib/lib)
scr/genheaders.pl:;

$(c++/dep): clean-dep
include $(wildcard $(c++/dep))

all: $(c++/exe) $(asm/exe) lib

$(c++/cpp): inc/syscall.gen.hh abi/syscall.gen.cc

obj: $(c++/obj) $(asm/obj) 
lib: $(lib/lib) $(abi/lib)

all/obj:= $(c++/obj) $(asm/obj)

all/exe:=$(c++/exe) $(c++/tst) $(asm/exe)
#    
all: $(all/exe)

FORCE:

.PHONY: FORCE

inc/syscall.gen.hh abi/syscall.gen.cc: scr/genheaders.pl
	vi-perl scr/genheaders.pl
	mv gen/syscall.gen.hh inc/syscall.gen.hh
	mv gen/syscall.gen.cc abi/syscall.gen.cc

include etc/multi.mk
xtr/dep:=$(filter-out $(c++/dep),$(wildcard */*.dd))
clean-dep:
	$(if $(wildcard $(extra)),rm -f $(wildcard $(extra)))
clean: clean-dep
	$(foreach v,c++/obj c++/cpp c++/asm,$(if $(wildcard $v),rm -f $(wildcard $v)))

.PHONY: clean clean-dep
all:
	@echo made all
	@cp .gitignore .gitignore.old
	@printf '%s\n' $(all/exe) | sort .gitignore -u -o .gitignore -
	@report cmp -s .gitignore .gitignore.old || echo ".gitignore changed"
