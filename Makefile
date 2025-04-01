MAKEFLAGS+= -rR
SHELL:=/bin/bash
all: linux lib bin tst
LC_ALL:=
LANG:=
LANGUAGE:=
include etc/resolve.mk
include etc/rules.mk
clean_asm:=$(filter-out $(all/src/asm),$(all/mod/c++:=.S))
clean:
	rm -f $(if $(wildcard */*.ii),$(wildcard */*.ii),*/*.ii)
	rm -f $(if $(wildcard */*.oo),$(wildcard */*.oo),*/*.oo)
	rm -f $(clean_asm)
	rm -f $(if $(wildcard */*.ii.d),$(wildcard */*.ii.d),*/*.ii.d)
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
