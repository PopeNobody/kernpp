
$(asm/obj): %.S.oo: %.S etc/asmflags
	$(CXX)  @etc/asmflags -o $@ -c $<

$(c++/obj): %.cc.oo: %.cc.SS  etc/asmflags etc/cppflags
	$(CXX)  @etc/asmflags -o $@ -c $<

$(c++/obj:.oo=.SS): %.cc.SS: %.cc.ii etc/cxxflags
	$(CXX)  @etc/cxxflags -o $@ -S $< 

$(c++/obj:.oo=.ii): %.cc.ii: %.cc    etc/cppflags
	$(CXX)  @etc/cppflags -o $@ -E $< 

