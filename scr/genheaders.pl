#!/usr/bin/env perl

use strict;
use warnings;
use autodie qw(:all);
use FindBin;
use lib "$FindBin::Bin";

our (%calls);
require "syscall.pl";

sub code_sort {
    return $calls{$a}{code} <=> $calls{$b}{code};
}

say q(#file __FILE__);
say q(#line __LINE__);
say q(extern "C" {);

for my $name (sort { code_sort } keys %calls) {
    our (%call);
    local *call = $calls{$name};
    next unless $call{impl};

    my @args = @{ $call{args} };
    my @decl_args = map { join(" ", @$_) } @args;
    push @decl_args, "errhand_t hand=err_log";

    my $args_str = join(", ", @decl_args);
    my $rtype = $call{ret};
    my $code = $call{code};
    my $sysname = $call{name};

    say "// __NR__ $sysname = $code";
    say "inline $rtype $name($args_str) __attribute__((__always_inline__));";

    say "inline $rtype $name($args_str) {";
    say "  uint64_t res = 0xfeebdaed;";
    say "  asm(\"\\tsyscall;\\n\"";
    say "      : \"=a\"(res)";

    my @regs = ('D', 'S', 'd', 'r10', 'r8', 'r9');
    my @arg_regs;
    for my $i (0 .. $#args) {
        my $reg = $regs[$i] // "";
        my $argname = $args[$i][1];
        push @arg_regs, "\"$reg\"($argname)" if $reg;
    }
    unshift @arg_regs, "\"0\"($code)";
    my $inputs = join(", ", @arg_regs);

    say "      : $inputs";
    say "      : \"rcx\", \"r11\", \"memory\");";
    say "  return chk_return<$rtype>(res, hand);";
    say "}";
}

say q(});
