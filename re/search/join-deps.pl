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
my (@cmd);
my (%text);
$DB::single=1;
BEGIN {
  if(0) {
  system("rm -f */*.ii");
  system("make");
  open(OUT,"|tee out.txt");
  open(STDOUT,">&OUT");
  open(STDERR,">&STDOUT");
  STDOUT->autoflush;
  STDERR->autoflush;
  print STDERR "out.txt:1:xxx\n";
};
};
END {
  close(STDERR);
  close(STDOUT);
  close(OUT);
};
my ( @pre ) = qw(
/usr/include
/usr/include/c++/12
/usr/include/x86_64-linux-gnu
/usr/include/x86_64-linux-gnu/c++/12
/usr/lib/gcc/x86_64-linux-gnu/12/include
);
@pre=map { [ length, $_ ] } @pre;
@pre=sort { $a->[0] <=> $b->[1] } @pre;
@pre=map { qr($_) } map { $_->[1] } @pre;
@ARGV=glob('*/*.dd') unless @ARGV;
my ($text,%text);
sub main(@) {
  my ($i)=" ";
  for (@_) {
    my ($path)=path($_);
    for($text{$path}) {
      $_=join("",$path->slurp);
      s{\\\n}{ }g;
      $_=[split(m{\n+},$_)];
      for(@$_) {
        $_=[ split m{:} ];
        $_ = { "tgts", shift @$_, "deps", shift @$_ };
      };
      for my $rule ( @$_ ) {
        my (@rule) = @{$_};
        for(@rule) {
          ddx( $_ )

      };
    };
  }
};

#        for( $text{$path}=[split m{\n}, $text] ) {
#          local(*_)=$text{$path};
#          for(@_){
#            local(*_)=[ split(m{:}) ];
#            for(@_){
#              $_=[split];
#            };      
#          };
#        };
main(@ARGV);
