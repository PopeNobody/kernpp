#!/usr/bin/perl
use strict;
use warnings;
use autodie qw(:all);

@ARGV=qw(/proc/pstree);
my %proc;
while(<>) {
  my ($p,@c)=split;
  die "wtf? '$_'" unless @c==1;
  push(@{$proc{$p}{children}}, @c);
  for my $c (@c) {
    die if defined $proc{$c}{parent};
    $proc{$c}{parent}=$p;
  };
};
use Data::Dumper;
print Dumper(\%proc);

my $pid=$$;
while($pid) {
  my $ppid=$proc{$pid}{parent};
  my @cmdline=
  print "pid: $pid ppid: $ppid cmd: \n";
  $pid=$ppid;
};
