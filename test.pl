#!/usr/bin/perl

$\="\n";

our(%fixup);
$fixup{false}=sub { unshift @ARGV, qw(not); };
$fixup{cat}=sub { push(@ARGV,qw(/dev/null)); };
$fixup{report}=sub { push(@ARGV,qw(/bin/echo this is a test)); };
$fixup{usleep}=sub { push(@ARGV,qw(-s 1)); };

sub test {
  print "testing $_";
  local (@ARGV);
  push(@ARGV,$_);
  s{.*/}{};

  for($fixup{$_}) {
    $_->() if defined;
  };

  print "cmd: (@ARGV)";
  system(@ARGV);
  print "\$?=$?";
};

for(@ARGV) {
  test();
};
