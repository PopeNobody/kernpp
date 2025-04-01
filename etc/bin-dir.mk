
ifeq ($(sub),)
$(error include $(MAKEFILE) with $(sub) set to a dir)
endif

$(sub)/c++:=$(wildcard $(sub)/*.cc)
$(sub)/asm:=$(wildcard $(sub)/*.SS)
$(sub)/obj:=$($(sub)/asm:.SS=.oo) $($(sub)/c++:.cc=.oo)
$(sub)/exe:=$($(sub)/obj:.oo=)

all/exe+=$($(sub)/exe)

include etc/rules.mk


#$(warning $(sub) $($(sub)/c++))
#$(warning $(sub) $($(sub)/asm))
#$(warning $(sub) $($(sub)/obj))
#$(warning $(sub) $($(sub)/exe))

#$(warning $($(sub)/exe))


