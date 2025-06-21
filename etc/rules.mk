
$(lib/lib): $(lib/obj)
	sbin/ar $@ $(lib/obj) $(lib/xxx)

$(all/exe): %: %.cc.oo etc/ld_flags $(lib/lib)
	sbin/ld $@ $< $(lib/lib)

$(all/cpp): %.cc.ii: %.cc  etc/cppflags
	sbin/g++ $@ $< @etc/cppflags -MD -MT $@ -MF $@.dd

$(gen/asm): %.SS: %.ii  etc/cxxflags
	sbin/g++ $@ $< @etc/cxxflags -MD -MT $@ -MF $@.dd

$(all/obj): %.oo: %.SS  etc/asmflags
	sbin/as $@ $< @etc/asmflags


%/run: %
	./$<

%: %.c
	gcc -o $@ $<

/dev/null:;
%.mk:;
Makefile:;
