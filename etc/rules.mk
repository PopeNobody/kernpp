
$(lib/lib): $(lib/obj)
	ar -r "$@" $(lib/obj) $(lib/xxx)

%: %.oo sbin/link etc/ld_flags $(lib/lib)
	ld -o "$@" $< $(lib/lib)

%.ii: %.cc sbin/prec etc/cppflags
	rm -f $*.ii $*.oo $*.S
	g++ -E -o "$@" $< @etc/cppflags

%.S: %.ii sbin/comp etc/cxxflags
	rm -f $*.S $*.oo
	g++ -S -o "$@" $< @etc/cxxflags

%.oo: %.S sbin/casm etc/asmflags
	as -o "$@" $< @etc/asmflags


