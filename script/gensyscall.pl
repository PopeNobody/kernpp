#!/usr/bin/perl
$|++;
use strict;
use warnings;
use Data::Dumper;

$\="\n";
$"=", ";
my @keys = qw(code name args ret);
for(@list) {
	my @item=@$_;
	my %item;
	$_=\%item;
	$item{code}=shift @item;
	$item{name}=shift @item;
	$item{name}=~s/^sys_//;
	$item{ret}="int";
	if(@item != 1) {
		my @args;
		$item{args}=\@args;
		die "this is odd!" if @item%2;
		while(@item){
			push(@args, [ splice @item, 0, 2 ]);
		};
	} else {
		$item{args}=undef;
	};
	
};
my %call = map { $_->{name}, $_ } @list;
my $call=\%call;
my @call = sort { $call{$a}{code} <=> $call{$b}{code} } keys %call;
local $Data::Dumper::Sortkeys=sub
{
	if( $_[0] eq $call ) {
		return \@call;
	} else {
		return \@keys;
	};
};
local $Data::Dumper::Indent=1;
print Data::Dumper->Dump([\%call],[qw(*call)]);
BEGIN{
	open(STDOUT,"|tee xlist.pl");
};
#    for(my $i=0;$i<@list;$i++){
#    	$list[$i][0]="unsigned long";
#    	for(@{$list[$i]}){
#    		s/ *struct \+/ /g;
#    		s/ *__user \+/ /g;
#    		next unless /unsigned long/;
#    		next if /^unsigned long/;
#    		print;
#    	}
#    }
END{
	close(STDOUT);
};
