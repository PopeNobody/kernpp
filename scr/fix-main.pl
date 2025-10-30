#!/usr/bin/perl
# vim: ts=2 sw=2 ft=perl
eval 'exec perl -x -wS $0 ${1+"$@"}'
  if 0;
$|++;
use common::sense;
use autodie;
use Nobody::Util;
use Nobody::PP;
our(@VERSION) = qw( 0 1 0 );
open(STDERR,">&STDOUT");
use Digest::MD5;

for my $ARGV( glob("*/*.cc") ) {
  local($_)=$ARGV;
  open(STDOUT,">$_.new");
  open(STDIN,"<$_");
  while(<STDIN>){
    if((@_=split(m{^\s*(int\s+main\s*\(.*\))\s*}))>1){
      $_[1]="int main(int argc,char *const*argv,char *const*envp)";
      @_=grep { defined && length } @_;
      $_="@_";
    };
    print;
  };
  close(STDIN);
  open(STDIN,"</dev/null");
  close(STDOUT);
  open(STDOUT,">&STDERR");
  for($ARGV) {
    system("diff $_ $_.new");
    if($?) {
      system("mv $_.new $_");
    } else {
      system("rm $_.new");
    };
  };
};
