#!/usr/bin/perl

use XML::Tiny::DOM;

my $doc = XML::Tiny::DOM->new( "list.html" );
open(STDOUT,"|tee syscall.out") or die "open:tee:$!";
use Data::Dumper;

my @tr = map { [ $_->td('*') ] } $doc->tr('*');
print Dumper(\@tr);
