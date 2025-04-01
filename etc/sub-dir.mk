MAKEFLAGS:= -rR

sub:=kernpp
include etc/lib-dir.mk
sub:=linux
include etc/lib-dir.mk
sub:=lib
include etc/lib-dir.mk
sub:=tst
include etc/bin-dir.mk
sub:=1ea
include etc/bin-dir.mk
