ifeq ($(sub),)
$(error include $(MAKEFILE) with $(sub) set to a dir)
endif

lib-$(sub)/asm:=$(wildcard $(sub)/*.SS)
lib-$(sub)/c++:=$(wildcard $(sub)/*.cc)
lib-$(sub)/obj := $(lib-$(sub)/asm:=.oo) $(lib-$(sub)/c++:=.oo)
lib-$(sub)/lib := $(lib-$(sub)/lib)

lib-$(sub)/lib := lib/lib$(sub).a
all/lib+=$($(sub)/lib)
include etc/rules.mk

#$(warning sub:=$(sub))
#$(warning $(sub)/asm:=$($(sub/asm)))

.SECONDEXPANSION:

