MAKEFLAGS+= -rR
SHELL:=/bin/bash
all: lib bin tst

lib/lib:=lib/libkernpp.aa
include etc/resolve.mk
include etc/rules.mk
clean_asm:=$(filter-out $(all/src/asm),$(all/mod/c++:=.S))
clean:
	rm -f */*.ii */*.oo */*.aa
	rm -f $(clean_asm)
	rm -f $(all/exe)
	ls -l $(all/src)

all:
	@echo made all

deps= $(sort $(wildcard */*.ii.d))
cxxs= $(sort $(wildcard */*.cc))
cpps= $(cxxs:.cc=.ii)
xtra= $(filter-out $(cpps:=.d),$(deps)) $(filter-out $(deps:.d=),$(wildcard */*.ii))
#show= $(foreach v,$1,$(warning SHOW $v=$($v)))
#$(call show,deps cpps xtra intr)
$(shell rm -f $(xtra))
include /dev/null  $(filter-out $(xtra),$(wildcard */*.d))
