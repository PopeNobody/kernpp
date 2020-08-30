#!/usr/bin/perl

my (@lines) = <>;
chomp(@lines);

my (%deps);
for(@lines)
{
  s{\s*$}{};
  s{$}{\n} unless s{\\$}{ };
};

for( split(/\n+/, join("", @lines)) )
{
  my ( $p1, $p2 ) = m{^([^:]*):(.*)};
  my ( @p1 ) = map { split } $p1;
  my ( @p2 ) = map { split } $p2;
  for(@p1)
  {
    push(@{$deps{$_}}, @p2);
  };
};

for my $tar (sort keys %deps)
{
  for( sort @{$deps{$tar}} )
  {
    print "$tar: $_\n";
  };
  print "\n";
};
__DATA__
print Dumper(\%deps);
use Data::Dumper;
