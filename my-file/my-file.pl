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
my $pat="bash";
if(@ARGV) {
  $pat=join("|",@ARGV);
};
my $sel = new IO::Select;
my @lines;
my $max_procs=4;
sub do_one_index($$);
for(@idx) {
  my $pipe = new IO::Pipe;
  if(!fork) {
    do_one_index($pipe->writer,$_->{FILENAME});
    die "do_one_index() returned!";
  }
  my $r=$pipe->reader;
  $sel->add($r);
};
debug("started @{[$sel->count]} children");
while($sel->count){
  process_some_lines();
};
exit(0);
sub do_one_index($$) 
{
  my ($fh,$fn) = (shift, shift);
  # Send output to a pipe.
  open(STDOUT,">&".fileno($fh));
  close($fh);
  my $stime = time;
  open(STDIN,"< ".$_->{FILENAME});
  open(STDIN,"lz4cat|");
  my $match=0;
  while(<STDIN>){
    next unless /$pat/o;
    ++$match;
    print;
  };
  $stime = time-$stime;
  debug("got $. lines in $stime seconds with $match matches");
  exit(0);
};
sub process_some_lines {
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
__DATA__
sub decompress {
  my $fn=shift;
  my $cnt=0;
  system("lz4cat $fn");
  exit($?);
};
my $sel=new IO::Select;
sub check {
  my @can = $sel->can_read();
  print STDERR scalar(@can), " handles ready\n";
  for my $fh (@can) {
    print STDERR "fh ", fileno($fh), "ready\n";
    print STDERR "reading\n";
    my $line=<$fh>;
    print STDERR "read ", defined($line)?"line":"undef", "\n";
  };
};
my (@fhs);
for(@idx) {
  my $pid;
  my $pipe = new IO::Pipe;
  if($pid=fork) {
    my $fh=$pipe->reader();
    print STDERR "$fh done\n";
    push(@fhs, $fh);
  } else {
    my $fh=$pipe->writer();
    open(STDOUT,">&".fileno($fh));
    close($fh);
    sleep(60);
    decompress $_->{FILENAME};
  };
};
{
  my $flags;
  sub nonblock($) {
    for(@_) {
      use Fcntl;
      $flags = "";
      fcntl($_, F_GETFL, $flags) or die "Couldn't get flags for HANDLE: $!\n";
      $flags |= O_NONBLOCK;
      fcntl($_, F_SETFL, $flags) or die "Couldn't set flags for HANDLE: $!\n";
    };
  };
};
my @lines;
nonblock(@fhs);
while(1) {
  my @lines = map { <$_> } @fhs;
  print Dumper(\@lines);
  sleep(1);
};
print STDERR "setup done!\n";
__DATA__

use IO::File;
use IO::Pipe;
$0="MyFile!";
for(@idx) {
  my $fn=$_->{FILENAME};
  print "$$:starting $fn\n";
  decompress($fn);
  print "$$:finished $fn\n";
};
debug("$$:all children started");

while($s->count()){
  while(@can=$s->can_read){
    my $tot=0;
    for(@can) {
      my ($fh,$idx) = @$_;
      my $l=<$fh>;
      if(defined($l)){
        ++$num;
      } else {
        $s->remove($fh);
        ++$x;
      };
    };
  };
};
my @cmd = ( qw(/usr/lib/apt/apt-helper), "cat-file");
