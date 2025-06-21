
$(tgt/lib): $(lib/obj)
	sbin/ar $@ $(lib/obj)

$(tgt/exe): %: %.cc.oo etc/ld_flags $(lib/lib)
	sbin/ld $@ $< $(lib/lib) @etc/ldflags

$(tgt/cpp): %.cc.ii: %.cc  etc/cppflags
	sbin/g++ $@ $< @etc/cppflags 

$(tgt/asm): %.SS: %.ii  etc/cxxflags
	sbin/g++ $@ $< @etc/cxxflags

$(tgt/obj): %.oo: %.SS  etc/asmflags
	sbin/as $@ $< @etc/asmflags


/dev/null:;
%.mk:;
Makefile:;
$(wildcard etc/*flags):
