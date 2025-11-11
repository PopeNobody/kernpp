asm/src:=$(wildcard */*.S)
asm/obj:=$(asm/src:.S=.S.o)
asm/lib:=$(filter lib/%,$(asm/obj))
asm/exe:=$(filter bin/%,$(asm/src:.S=))
asm/abi:=$(filter abi/%,$(asm/obj))
asm/tst:=$(filter tst/%,$(asm/obj:.S.o=))
all/tst+=$(asm/tst)

$(asm/obj): %.S.o: %.S etc/asmflags
	$(CXX) -o $@ $< @etc/aflags -c

$(asm/tst) $(asm/exe): %: %.S.o etc/ld_flags $(lib/lib) $(abi/lib)
	$(CXX) -o $@ -Wl,--start-group $<  $(abi/lib) $(lib/lib) @etc/ld_flags -Wl,--end-group
