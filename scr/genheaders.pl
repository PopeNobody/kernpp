#!/usr/bin/env perl

use common::sense;
use autodie;
use Nobody::Util;
use FindBin;
use lib "$FindBin::Bin";

our (%calls);
require "syscall.pl";
path("gen")->mkdir;
sub code_sort { $calls{$a}{code} <=> $calls{$b}{code} }
our(@header,@source);
push(@header,"// Auto-generated syscall wrappers");
push(@source,"// Auto-generated syscall wrappers");
push(@header,"#pragma once");
push(@header,"");
push(@header,"namespace sys {");
#push(@header,"  namespace impl {");
push(@source,"#include \"syscall.hh\"");
push(@source,"#include \"syscall.low.hh\"");
push(@source,"");
push(@source,"namespace sys {");
#    push(@source,"using sys::errhand_t;");
#    for(0 .. 6) {
#      push(@source,"using sys::syscall$_;");
#    };
#    push(@source,"using sys::fdset_t;");
#    push(@source,"using sys::fdset_p;");


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

    my $attr = "";
    if ($call{noreturn}) {
        $attr = "__attribute__((__noreturn__))";
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
    my $inline="";
    #$inline="inline ";
    push @header, "";
    push @header, "";
    push @header, "// __NR__ $sysname = $code";
    push @header, "$inline$rtype $name($args_str_with_default = err_log)";
    push @header, "  $attr;";
    push @header, "";
    push @header, "";
    push @source, "$inline$rtype $name($args_str) {";
    push @source, "  uint64_t res = syscall$arity($code $arg_list);";

    if ($call{noreturn}) {
        push @source, "  __builtin_unreachable();";
    } else {
        push @source, "  return chk_return<$rtype>(res, hand);";
    }
    push @source, "}";
}
push(@source,"} // namespace sys {");

push @header, "";
#push @header, "  } // namespace impl";
push @header, "} // namespace sys";

path("gen/syscall.gen.hh")->spew(map { "$_\n" } @header);
path("gen/syscall.gen.cc")->spew(map { "$_\n" } @source);
