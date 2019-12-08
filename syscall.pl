#!/usr/bin/perl

use XML::Tiny::DOM;

my $doc = XML::Tiny::DOM->new( "list.html" );

use Data::Dumper;

my @tr = $doc->tr('*');
print Dumper(\@tr);
