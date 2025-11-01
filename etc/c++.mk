c++/src:=$(wildcard */*.cc)
c++/dep:=$(c++/src:.cc=.cc.dd)
c++/obj:=$(c++/src:.cc=.cc.oo)

c++/asm:=$(c++/src:.cc=.cc.SS)
c++/cpp:=$(c++/src:.cc=.cc.ii)
c++/dep:=$(c++/src:.cc=.cc.dd)
c++/exe:=$(filter bin/% tst/%,$(c++/src:.cc=))
c++/tst:=$(filter tst/%,$(c++/obj:.cc.oo=))
c++/lib:=$(filter lib/%,$(c++/obj))
c++/abi:=$(filter abi/%,$(c++/obj))

all/exe+=$(c++/exe)
all/tmp+=$(c++/obj) $(c++/asm) $(c++/cpp) $(c++/dep)
all/tgt+=$(c++/exe)

$(c++/obj): %.cc.oo: %.cc.SS  etc/asmflags etc/cppflags
	$(CXX)  @etc/asmflags -o $@ -c $<

$(c++/obj:.oo=.SS): %.cc.SS: %.cc.ii etc/cxxflags
	$(CXX)  @etc/cxxflags -o $@ -S $< 

$(c++/obj:.oo=.ii): %.cc.ii: %.cc    etc/cppflags
	$(CXX)  @etc/cppflags -o $@ -E $< -MMD -MF $<.dd -MT $@

$(c++/exe): %: %.cc.oo etc/ld_flags $(lib/lib) $(abi/lib)
	$(CXX) -o $@ -Wl,--start-group $< $(lib/lib) $(abi/lib) @etc/ld_flags -Wl,--end-group
