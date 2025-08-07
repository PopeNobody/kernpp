#export override PATH:=$(PWD)/sbin:$(PATH)
include etc/vars.mk
all: lib bin tst
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

TRS/dep:=$(filter-out $(c++/dep),$(wildcard */*.cc.dd))
ifneq ($(TRS/dep),)
$(foreach f,$(wildcard $(lib/lib) $(TRS/dep)),$(warning reap: $f)$(shell rm -f $f))
endif
include /dev/null $(wildcard */*.cc.dd)

all: $(c++/exe) $(asm/exe) $(lib/lib) bin/printenv

bin/printenv: bin/echo
	ln -f $< $@

obj: $(c++/obj) $(asm/obj)
lib: $(lib/lib)

$(lib/lib): $(asm/lib) $(c++/lib)
	ar r $@ $(asm/lib) $(c++/lib)
	ranlib $@

all/obj:= $(c++/obj) $(asm/obj)

all/exe:=$(c++/exe) $(c++/tst) $(asm/exe)

all: $(all/exe) inc/syscall.gen.hh


inc/syscall.gen.hh: scr/genheaders.pl scr/syscall.pl
	vi-perl scr/genheaders.pl > $@.new
	mv $@.new $@

#    include etc/one-step.mk
include etc/multi.mk

$(asm/obj): %.S.oo: %.S etc/asmflags
	$(CXX) -o $@ $< @etc/aflags -c

$(asm/exe): %: %.S.oo etc/ld_flags $(lib/lib)
	$(CXX) -o $@ -Wl,--start-group $< $(lib/lib) @etc/ld_flags -Wl,--end-group
#    	$< $(lib/lib) @etc/ld_flags 


all: $(c++/obj)


$(c++/exe): %: %.cc.oo etc/ld_flags $(lib/lib)
	$(CXX) -o $@ -Wl,--start-group $< $(lib/lib) @etc/ld_flags -Wl,--end-group


/dev/null:;
%.mk:;
Makefile:;

clean:
	@rm -f $(asm/exe)
	@rm -f $(asm/obj)
	@rm -f $(c++/asm)
	@rm -f $(c++/cpp)
	@rm -f $(c++/dep)
	@rm -f $(c++/exe)
	@rm -f $(c++/obj)
	@rm -f $(lib/lib)

all: $(all/exe) $(tgt/all)
	@echo made all
	@printf '%s\n' $(asm/exe) $(c++/exe) | sort .gitignore -u -o .gitignore -
