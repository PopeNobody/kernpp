
$(lib/lib): $(lib/obj)
	ar -r $@ $(lib/obj) $(lib/xxx)

$(all/exe): %: %.oo etc/ld_flags $(lib/lib)
	ld -o $@ $< $(lib/lib)

$(all/cpp): %.ii: %.cc  etc/cppflags
	g++ -E -o $@ $< @etc/cppflags -MD -MT $@ -MF $@.dd

$(gen/asm): %.SS: %.ii  etc/cxxflags
	g++ -S -o $@ $< @etc/cxxflags -MD -MT $@ -MF $@.dd

$(all/obj): %.oo: %.SS  etc/asmflags
	as -o $@ $< @etc/asmflags


%/run: %
	./$<

%: %.c
	gcc -o $@ $<

/dev/null:;
%.mk:;
Makefile:;
