#!/usr/bin/env perl

use common::sense;
use autodie;
use Nobody::Util;
use FindBin;
use lib "$FindBin::Bin";

our (%calls);
require "syscall.pl";

sub code_sort { $calls{$a}{code} <=> $calls{$b}{code} }
say "#include \"syscall.low.hh\"";
say "namespace sys {";
say "";
say "// Auto-generated syscall wrappers";

for my $name (sort { code_sort } keys %calls) {
    our (%call);
    local *call = $calls{$name};
    next unless $call{impl};

    my @args = @{ $call{args} };
    my @decl_args = map { join(" ", @$_) } @args;
    push @decl_args, "errhand_t hand";
    my $args_str_with_default = join(", ", @decl_args);
    my $args_str = join(", ", map { join(" ", @$_) } @args);
    my $args_err = "errhand_t hand";
    my $rtype = $call{ret};
    my $code = $call{code};
    my $sysname = $call{name};

    my $attr = "__attribute__((__always_inline__))";
    if ($call{noreturn}) {
        $attr = "__attribute__((__always_inline__, __noreturn__))";
    }

    my $arity = scalar(@args);
    $arity = 6 if $arity > 6;

    my @arg_names = map { $_->[1] } @args;
    my $arg_list = join(", ", map { "(uint64_t)$_" } @arg_names);
    for($arg_list) {
      $_=", $_" if length;
    };
    for($args_str) {
      $_=length?"$_, $args_err":$args_err;
    };
    say "";
    say "";
    say "// __NR__ $sysname = $code";
    say "inline $rtype $name($args_str_with_default = err_log)";
    say "  $attr;";
    say "";
    say "";
    say "inline $rtype $name($args_str) {";
    say "  uint64_t res = syscall$arity($code $arg_list);";
    say "";
    say "";

    if ($call{noreturn}) {
        say "  __builtin_unreachable();";
    } else {
        say "  return chk_return<$rtype>(res, hand);";
    }
    say "}";
}

say "";
say "} // namespace sys";
