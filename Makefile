MAKEFLAGS+= -rR
SHELL:=/bin/bash
all: lib bin tst

include etc/resolve.mk
include etc/rules.mk

clean:
	rm -f $(wildcard $(all))

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
