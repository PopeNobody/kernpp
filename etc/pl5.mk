pl5/src:=$(wildcard tst/*.pl)
pl5/tst:=$(pl5/src:.pl=)
all/exe+=$(pl5/tst)
tst: $(pl5/tst)

$(pl5/tst): %: %.pl
	cp $< $@

$(pl5/exe): %: %.pl
	cp -f $< $@ && chmod -w $@
