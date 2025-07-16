#!/usr/bin/env perl
use strict;
use warnings;
use common::sense;
use Nobody::Util;
my %defines;
my @output;
my @cond_stack = (1);  # current "truth" of conditional inclusion
@ARGV=qw(fuck.c) unless @ARGV;
my @pri_dirs = qw(.);
my @pub_dirs = qw(
 /usr/lib/gcc/x86_64-linux-gnu/12/include
 /usr/local/include
 /usr/include/x86_64-linux-gnu
 /usr/include
);
sub find_file;
sub cpp {
  local(@_)=@_;
  local(*ARGV)=\@_;
  while (<>) {
    chomp;
    if (/^\s*#\s*define\s+(\w+)\s+(.*)/) {
      $defines{$1} = $2 if $cond_stack[-1];
    }
    elsif (/^\s*#\s*undef\s+(\w+)/) {
      delete $defines{$1} if $cond_stack[-1];
    }
    elsif (/^\s*#\s*ifdef\s+(\w+)/) {
      push @cond_stack, ($cond_stack[-1] && exists $defines{$1}) ? 1 : 0;
    }
    elsif (/^\s*#\s*ifndef\s+(\w+)/) {
      push @cond_stack, ($cond_stack[-1] && !exists $defines{$1}) ? 1 : 0;
    }
    elsif (/^\s*#\s*else\b/) {
      die "#else without matching #if[n]def at $ARGV line $.\n" if @cond_stack < 2;
      $cond_stack[-1] = $cond_stack[-2] && !$cond_stack[-1];
    }
    elsif (/^\s*#\s*endif\b/) {
      pop @cond_stack;
    }
    elsif (/^\s*#\s*include\s*([<"])([^">]+)([">])(.*)/) {
      my ($type);
      if($1 == '<' and $3 eq '>') {
        $type="public";
      } elsif ( $1 eq '"' and $3 eq '"' ) {
        $type="private";
      } else {
        die "need <...> or \"...\"\n";
      };
      my ($name)=$2;
      my ($file)=find_file($type,$name);
      eex( { name=>$name, file=>$file } );
      cpp($file);
    }
    elsif ($cond_stack[-1]) {
      # perform simple macro substitution
      print STDERR "macro\n";
      s/\b(\w+)\b/exists $defines{$1} ? $defines{$1} : $1/ge;
      print "$_\n";
    }
  }
}
sub find_file {
  my ($type,$name)=@_;
  my (@dirs)=@pub_dirs;
  unshift(@dirs,".",@pri_dirs) if $type eq "private";
  for(map { "$_/$name" } @dirs) {
    return $_ if -e;
  };
  die "could not locate $name in any of:\n",
      map { "\t$_\n" } @dirs,
      "sorry.  :(\n\n";
};
cpp(@ARGV);
