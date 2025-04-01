ifeq ($(sub),)
$(error include $(MAKEFILE) with $(sub) set to a dir)
endif

$(sub)/c++:=$(wildcard $(sub)/*.cc)
$(sub)/asm:=$(wildcard $(sub)/*.SS)
$(sub)/obj:=$($(sub)/asm:.SS=.oo) $($(sub)/c++:.cc=.oo)
$(sub)/lib:=lib/lib$(sub).a
all/lib+=$($(sub)/lib)

.SECONDEXPANSION:

include etc/rules.mk
