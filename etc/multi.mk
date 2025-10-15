
$(c++/obj): %.cc.oo: %.cc.SS  etc/asmflags etc/cppflags
	$(CXX)  @etc/asmflags -o $@ -c $<

$(c++/obj:.oo=.SS): %.cc.SS: %.cc.ii etc/cxxflags
	$(CXX)  @etc/cxxflags -o $@ -S $< 

$(c++/obj:.oo=.ii): %.cc.ii: %.cc    etc/cppflags
	$(CXX)  @etc/cppflags -o $@ -E $< -MMD -MF $<.dd -MT $@

$(lib/lib): $(sort $(asm/lib) $(c++/lib))
	$(AR) r $@ $(asm/lib) $(c++/lib)
	$(RANLIB) $@

$(asm/obj): %.S.oo: %.S etc/asmflags
	$(CXX) -o $@ $< @etc/aflags -c

$(asm/exe): %: %.S.oo etc/ld_flags $(lib/lib)
	$(CXX) -o $@ -Wl,--start-group $< $(lib/lib) @etc/ld_flags -Wl,--end-group
