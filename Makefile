MAKEFLAGS+= -rR
SHELL:=/bin/bash
all: lib bin tst

include etc/resolve.mk
include etc/rules.mk

clean:
	rm -f $(wildcard $(all))

all:
	@echo made all

deps= $(sort $(basename $(wildcard */*.ii.d)))
mods= $(sort $(patsubst %.cc,%.ii,$(wildcard */*.cc)))
xtra= $(filter-out $(mods),$(deps))
show=$(foreach v,$1,$(warning SHOW $v=$($v)))
$(call show,deps mods xtra)
include /dev/null 
