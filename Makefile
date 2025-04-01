#all: lib bin tst
all:

etc/makflags:;
include etc/makflags
etc/resolv.mk:;
etc/rules.mk:;
Makefile:;
GNUmakefile:;

include etc/resolve.mk
include etc/rules.mk

#show = $1
#ifeq (a,b)
#clean_asm:=$(filter-out $(all/src/asm),$(all/mod/c++:=.S))
clean:
	rm -f $(if $(wildcard */*.ii),$(wildcard */*.ii),*/*.ii)
	rm -f $(if $(wildcard */*.oo),$(wildcard */*.oo),*/*.oo)
	rm -f $(if $(wildcard */*.dd),$(wildcard */*.dd),*/.dd)
#
all:
	@echo made all
#
deps= $(sort $(wildcard */*.ii.d))
cxxs= $(sort $(wildcard */*.cc))
cpps= $(cxxs:.cc=.ii)
xtra= $(filter-out $(cpps:=.d),$(deps)) $(filter-out $(deps:.d=),$(wildcard */*.ii))
#show= $(foreach v,$1,$(info SHOW $v=$($v)))
#$(call show,deps cpps xtra intr)
$(shell /bin/rm -f $(xtra))
deps=$(wildcard */*.dd)
ifneq ($(deps),)
include $(deps)
endif
