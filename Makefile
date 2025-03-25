MAKEFLAGS+= -rR
SHELL:=/bin/bash
all: lib bin tst

include etc/resolve.mk
include etc/rules.mk

clean:
	rm -f $(wildcard $(all))

all:
	@echo made all
