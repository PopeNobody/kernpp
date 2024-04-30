#/usr/bin/perl

use strict;
use warnings;
use autodie qw(:all);
use Data::Dumper;
$|++;
use FindBin;
use lib "$FindBin::Bin";


our(%calls);
require "syscall.pl" or die "$@";

sub code_sort {
	return $calls{$a}{code} <=> $calls{$b}{code};
};
$\="\n";
$,=" ";

print q(#file __FILE__);
print q(#line __LINE__);
print q(extern "C" {);
for my $name (sort {code_sort} keys %calls) {
	our(%call);
	local *call=$calls{$name};
	next unless $call{impl};
	my @args = @{$call{args}};
	for(@args) {
		$_=join(" ",@$_);
	};
	@args=join(", ", @args);
	my $rtype=$call{ret};
        print "// __NR__", $call{name}, "=", $call{code}, "\n";
	print "inline $rtype $name(@args)";
	print "  __attribute__((__always_inline__));";
};
print q(});
