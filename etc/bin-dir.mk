
ifeq (lib-$(sub),)
$(error include $(MAKEFILE) with $(sub) set to a dir)
endif

lib-$(sub)/c++:=$(wildcard lib-$(sub)/*.cc)
lib-$(sub)/asm:=$(wildcard lib-$(sub)/*.SS)
lib-$(sub)/obj:=$(lib-$(sub)/asm:.SS=.oo) $(lib-$(sub)/c++:.cc=.oo)
lib-$(sub)/exe:=$(lib-$(sub)/obj:.oo=)

all/exe+=$(lib-$(sub)/exe)

include etc/rules.mk


#$(warning lib-$(sub) $(lib-$(sub)/c++))
#$(warning lib-$(sub) $(lib-$(sub)/asm))
#$(warning lib-$(sub) $(lib-$(sub)/obj))
#$(warning lib-$(sub) $(lib-$(sub)/exe))

#$(warning $(lib-$(sub)/exe))


