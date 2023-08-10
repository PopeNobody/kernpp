#!/usr/bin/perl
$|++;
use strict;
use warnings;
use autodie qw(:all);
use Data::Dumper;
use FindBin;
our(%calls);
my $dump="$FindBin::Bin/syscall.pl";
require $dump or die "$@";
my @keys = qw(code name impl args ret);

BEGIN {
  open(STDERR,"|less -FS");
  open(STDOUT,">&STDERR");
};
END {
  close(STDOUT);
  close(STDERR) or warn "less returned non zero\n";
};
##
## Put the code to modify the %calls hash here, and the modified version
## Will appear in syscall.pl.new
##
$\="\n";
$,=" ";
our(%call);
sub fmt() {
	my $name=$call{name};
	@_=@{$call{args}};
	for(@_){
		$_=join(" ", @$_);
	};
	return "$name(",join(",",@_),")";
};
my %args;
#print Dumper \%calls;
for(keys %calls){
  local *call=$calls{$_};
  next unless $call{impl};
  for(@{$call{args}}){
    next unless ($_->[0] eq "istr_t") || ($_->[0] eq "ostr_t");
    if( $_->[1] eq "oldname" ) {
      $_->[1] = "opath";
    } elsif ( $_->[1] eq "newname" ) {
      $_->[1] = "npath";
    };
  };
};
#print Dumper \%calls;
##
## Don't change the code after this.
##
{
	my $calls=\%calls;
	open(STDOUT,">$dump.new") or die "open:$!";
	my @calls = sort { $calls{$a}{code} <=> $calls{$b}{code} } keys %calls;
	local $Data::Dumper::Sortkeys=sub
	{
		if( $_[0] eq $calls ) {
			return \@calls;
		} else {
			return [ grep { exists $_[0]->{$_} } @keys ];
		};
	};
	local $Data::Dumper::Indent=1;
	print Data::Dumper->Dump([\%calls],[qw(*calls)]);
	system("mv $dump $dump.old");
	system("mv $dump.new $dump");
}
