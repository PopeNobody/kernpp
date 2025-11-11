$(abi/lib): $(sort $(asm/abi) $(c++/abi))
	$(AR) r $@ $(asm/abi) $(c++/abi)
	$(RANLIB) $@

$(lib/lib): $(sort $(asm/lib) $(c++/lib))
	$(AR) r $@ $(asm/lib) $(c++/lib)
	$(RANLIB) $@

