#!/usr/bin/perl
$|++;
use strict;
use warnings;
use Data::Dumper;
use FindBin;
our(%calls);
my $dump="$FindBin::Bin/syscall.pl";
require $dump or die "$@";
my @keys = qw(code name impl args ret);

##
## Put the code to modify the %calls hash here, and the modified version
## Will appear in syscall.pl.new
##
$\="\n";
$,=" ";
our(%call);
our(@args);
sub fmt() {
	my $name=$call{name};
	@_=@{$call{args}};
	for(@_){
		$_=join(" ", @$_);
	};
	return "$name(",join(",",@_),")";
};
for(keys %calls){
	local *call=$calls{$_};
	next unless $call{impl};
	for(@{$call{args}}){
		if( $_->[0] eq "struct stat *"){
			$_->[0] = "stat_p";
		};
	};
};
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
