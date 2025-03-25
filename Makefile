MAKEFLAGS+= -rR
SHELL:=/bin/bash
all: lib bin tst

include etc/resolve.mk
include etc/rules.mk
clean_asm:=$(if $(wildcard */*.S),$(wildcard */*.S),*/*.S)
clean_asm:=$(filter-out $(bin/src/asm),$(clean_asm))
clean_asm:=$(filter-out $(lib/src/asm),$(clean_asm))
clean_asm:=$(filter-out $(tst/src/asm),$(clean_asm))
clean:
	rm -f $(if $(wildcard */*.ii),$(wildcard */*.ii),*/*.ii)
	echo rm -f $(clean_asm)
	rm -f $(if $(wildcard */*.ii.d),$(wildcard */*.ii.d),*/*.ii.d)

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
