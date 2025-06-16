var/VV:=$(.VARIABLES)
c++=ii dd SS oo
asm=oo
beg=c++ asm
c++/cc:=$(wildcard */*.cc)
c++/ii:=$(c++/cc:=.cc.ii)
c++/dd:=$(c++/cc:=.cc.dd)
c++/SS:=$(c++/cc:=.cc.ii)
c++/oo:=$(c++/cc:=.cc.oo)
cxx/--:=$(foreach x,$(c++),$$(c++/$x))
asm/SS:=$(wildcard */*.SS)
asm/oo:=$(asm/SS:=.SS.oo);
var/NN:=$(filter-out $(var/VV),$(.VARIABLES))
show=$(eval $$(warning $($1)))
$(warning $show)
#    $(foreach x,$(var/nn),$(call show, 
#v:=asm
#$(eval $$(warning $v=$$($v)))

tst:;
