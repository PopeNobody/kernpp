MAKEFLAGS+= -rR
SHELL:=/bin/bash
all: lib bin tst

include etc/resolve.mk
include etc/rules.mk

clean:
	@echo rm -f $(wildcard $(tst/all))

all:
	@echo made all
