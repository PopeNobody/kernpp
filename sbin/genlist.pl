#/usr/bin/perl

use strict;
use warnings;
use Data::Dumper;
$|++;
our(%calls);
use FindBin;
use lib "$FindBin::Bin";
require "syscall.pl" or die "$@";

sub code_sort {
	return $calls{$a}{code} <=> $calls{$b}{code};
};
$\="\n";
$,=" ";

print q(#file script/genheaders.pl);
print q(#line 1);
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
