MAKEFLAGS+= -rR -j1
export override PATH:=$(PWD)/sbin:$(PATH)
SHELL:=/bin/bash -xe
all: lib bin tst

lib/lib:=lib/libkernpp.aa
include etc/resolve.mk
include etc/rules.mk
include $(wildcard $(all/dep))
clean_asm:=$(filter-out $(src/asm),$(all/asm))
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
include /dev/null  $(filter-out $(xtra),$(wildcard */*.d))
