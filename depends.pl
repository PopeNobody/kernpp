#!/usr/bin/perl
use strict;
use warnings;
use autodie qw(:all);
use Data::Dumper;

die "usage: $0 <files>" unless @ARGV;
#    open(my $DEBUG,">debug.log.new");
#    unlink("debug.log") if -e "debug.log";
#    link("debug.log.new","debug.log");
#    unlink("debug.log.new");

my (@lines) = <>;
chomp(@lines);

my (@deps);
my (%deps);
for(@lines)
{
  s{$}{\n} unless s{\s*\\\s*$}{ };
};
#    $DEBUG->print(Data::Dumper->Dump([\@lines], [qw(*lines)]));
@lines=split(/\n+/, join("", @lines));
#    $DEBUG->print(Data::Dumper->Dump([\@lines], [qw(*lines)]));

for( @lines ) 
{
#      $DEBUG->print(Data::Dumper->Dump([\$_], [qw(*_)]));
  my ( $p1, $p2 ) = m{^([^:]*):(.*)};
#      $DEBUG->print(Data::Dumper->Dump([\$p1,\$p2], [qw(*p1 *p2)]));
  my ( @p1 ) = map { split } $p1;
  my ( @p2 ) = map { split } $p2;
  for(@p1)
  {
    push(@{$deps{$_}}, @p2);
  };
};

#$DEBUG->print(Data::Dumper->Dump([\%deps], [qw(*deps)]));

for my $tar (sort keys %deps)
{
  for( sort @{$deps{$tar}} )
  {
    print "$tar: $_\n";
  };
  print "\n";
};
