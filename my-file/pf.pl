#!/usr/bin/perl
$|++;
use autodie qw(:all);
use strict;
use warnings;
BEGIN {
  use FindBin qw($RealBin);
  print STDERR "running from: $RealBin\n";
  use lib "$RealBin";
};

my ($fn) =
    "data/mirror.clarkson.edu_ubuntu_dists_bionic-updates_Contents-amd64";

my $cnt=0;
open(STDIN,"<$fn");
while(<STDIN>){
  chomp;
  my ($path,$pkg,$xxx) = split;
  die "($_)\n" if defined $xxx;
  ++$cnt;
};
close(STDIN);

print "$cnt lines\n";
