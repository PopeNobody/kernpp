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
use AptPkg::Config '$_config';
use Cwd;
use Data::Dumper;
use File::Path qw(mkpath rmtree);
use IO::Pipe;
use IO::Select;
use List::MoreUtils qw/any none uniq/;

$\="\n";
sub debug{
  print STDERR "$$:@_"; 
};
debug("starting");
use Capture::Tiny ':all'; 
my @key = qw( IDENTIFIER ARCHITECTURE ORIGIN SUITE CODENAME FILENAME );
my %arch = map { $_, 1 } qw( all amd64 $(ARCHITECTURE));
if(!open(STDIN,"-|")) {
  debug("running apt-get");
  my $fmt=join("\x1F",map { '$('.$_.')' } @key);
  my @cmd=( qw(apt-get indextargets --format), $fmt );
  exec(@cmd);
  die "exec failed!";
};
my @idx;
debug("waiting for index targets");
while(<STDIN>){
  my %r;
  @r{@key}=split(/\x1f/);
  next unless $r{IDENTIFIER} eq 'Contents-deb';
  next unless $arch{$r{ARCHITECTURE}};
  push(@idx,\%r);
};
{
  no autodie;
  close(STDIN);
  debug("index created.  child returned $?");
  open(STDIN,"</dev/null");
};
if(grep({ /^--dump$/ } @ARGV ))
{
  print Dumper(\@idx);
  exit(0);
};
my $max_procs=4;
sub do_one_index($$);
my %proc;

for(@idx) {
  my ($fn) = $_->{FILENAME};
  my ($of) = map { "data/$_" } map { m{^.*/(.*).lz4$} } $fn;
  $_->{UC_FILENAME}=$of;
  if(my $pid=fork) {
    $proc{$pid}=$_;
    debug("started child $pid");
  } else {
    do_one_index($fn,$of);
    die "do_one_index() returned!";
  }
};
debug("started @{[scalar(keys %proc)]} children");
while((my $pid=wait)!=-1){
  print STDERR "pid $pid returned $?";
};
exit(0);
sub do_one_index($$) 
{
  my ($fn,$of) = (shift, shift);
  mkpath("data") unless -d "data";
  open(STDOUT,"> $of.new");
  my $stime = time;
  open(STDIN,"< $fn");
  system("lz4cat");
  if($?) {
    warn("lz4cat returned $?");
    unlink("$of.new");
    exit(1);
  } else {
    rename("$of.new","$of");
    exit(0);
  };
  die "exec:lz4cat:$!";
};
sub process_some_lines {
  my $sel;
  die;
  my @can=$sel->can_read();
  for my $fh (@can)
  {
    my $lines=0;
    while(<$fh>){
      last if ++$lines>1000*1000;
    };
    unless($lines) {
      $sel->remove($fh);
      no autodie;
      close($fh) or warn("child returned $?");
    };
    debug("processed $lines lines") if $lines;
  };
};
