#!/usr/bin/perl
# vim: ts=2 sw=2 ft=perl
eval 'exec perl -x -wS $0 ${1+"$@"}'
  if 0;
$|++;
use common::sense;
use lib "scr/lib/";
use autodie;
use Nobody::Util;
use Nobody::PP;
our(@VERSION) = qw( 0 1 0 );

#testing decomm.
#
#Giving it zero, or one bytes should give back what you gave.

my($rand);
open(STDIN,"</dev/random");
sysread(STDIN,$rand,1024);
close(STDIN);
open(STDIN,"</dev/null");
