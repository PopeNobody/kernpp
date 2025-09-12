#!/usr/bin/perl
# vim: ts=2 sw=2 ft=perl
#
package Nobody::Util;
our ( @EXPORT, @EXPORT_OK, @ISA );
use vars qw(@carp @pp);
use Nobody::Path;
use Nobody::PP;
use Fcntl qw(:seek :mode);
BEGIN {
  @pp=qw( dd ddx ee eex pp ppx qquote quote );
  @carp=( @Carp::EXPORT, @Carp::EXPORT_OK, @Carp::EXPORT_FAIL );
  (sub{return @Carp::EXPORT,@Carp::EXPORT_OK,@Carp::EXPORT_FAIL;})->();
  @carp=grep { uc($_) ne uc("verbose") } @carp;
};
use Carp @carp;
use Nobody::PP @pp;
use FindBin;
use FindBin @FindBin::EXPORT_OK;
use List::Util;
use List::Util grep { !m{any} } @List::Util::EXPORT_OK;
use Scalar::Util;
use Scalar::Util @Scalar::Util::EXPORT_OK;

BEGIN {
  push(@EXPORT_OK,@FindBin::EXPORT_OK);
  push(@EXPORT_OK,@Nobody::PP::EXPORT_OK);
  push(@EXPORT_OK, @carp, @pp, qw{
    QX            WNOHANG   avg          class         deparse
    dirname       file_id   flatten      getcwd        getfds
    getfl         lcmp      lsort        matrix        max
    maybeRef      methods   methods_via  min           mkdir_p
    mkref         nonblock  open_fds     pasteLines    path
    safe_blessed  safe_isa  serdate      serial_maker  setfl
    spit          spit_fh   stdin_sub    stdout_sub    suck
    suckdir       sum       uniq         vcmp          vsort
        }
      );
  push(@EXPORT_OK, @Scalar::Util::EXPORT_OK);
  push(@EXPORT_OK, @List::Util::EXPORT_OK);
  @EXPORT_OK = grep { !m{^(all|uniq)} } @EXPORT_OK;
  push(@EXPORT_OK, @carp, @pp, "basename",
    qw( sum avg max min mkdir_p suckdir getcwd ));
  push(@EXPORT_OK,
    qw( pasteLines serdate class mkref open_fds deparse maybeRef ),
    qw( file_id WNOHANG uniq matrix dirname capture )
  );
}
use strict;
use warnings;
use feature qw(say);
use autodie;
use POSIX qw(strftime mktime );
use Env qw( $HOME $PWD @PATH );
use lib "/opt/lib/perl";
use POSIX ":sys_wait_h";
BEGIN {
  @EXPORT=@EXPORT_OK;
  @ISA=qw(Exporter);
  require Exporter;
  sub import {
    goto &Exporter::import;
  };
}
sub safe_isa {
  my ($ref,$class) = @_;
  return 0 unless ref($ref);
  return 0 unless blessed($ref);
  return 0 unless $ref->isa($class);
  return 1;
};
{
  no strict 'subs';
  sub getfl(*) {
    my($fh)=shift;
    my($val);
    fcntl($fh,F_GETFL,$val);
    return $val;
  };
  sub setfl(*$) {
    my ($fh)=shift;
    my ($val)=shift;
    fcntl($fh,F_SETFL,$val);
  };
  sub nonblock {
    my ($fh)=shift;
    if(!@_ || shift) {
      setfl($fh,getfl($fh)|O_NONBLOCK);
    };
  };
};
sub randomize {
  my (@tmp);
  while(@_){
    push(@tmp,splice(@_,int(rand(@_-1)),1,()));
  };
}
sub basename {
  my ($self)=shift;
  return () unless defined($self);
  $self=path($self) unless ref($self);
  $self->basename;
};
sub flatten {
  my $i=0;
  local(@_)=@_;
  while($i<@_) {
    for($_[$i]){
      if(ref($_) eq 'ARRAY') {
        splice(@_,$i,1,@{$_[$i]});
      } else {
        ++$i;
      };
    };
  };
  return @_;
};
sub dirname {
  my ($self)=shift;
  $self=path($self) unless ref($self);
  $self->dirname;
};
sub stdout_sub(&) {
  my ($sub)=@_;
  my $pid=open(STDOUT,"|-");
  return $pid if $pid;
  eval {
    $sub->();
  };
  my($ret);
  if($ret=!!$@) {
    warn "$@";
  };
  close(STDOUT);
  exit($ret);
};
sub lcmp {
  my ($a,$b) = (
    @_ == 2 ? (shift,shift) :
    @_ ? (undef, undef, warn "Warning:  vcmp wants 2 args or none") :
    ($a,$b)
  );
  my ($r)=(length($a)<=>length($b));
  $r=$r||($a cmp $b);
  $r;
};
sub lsort {
  sort { lcmp } @_;
};
sub stdin_sub(&) {
  my ($sub)=@_;
  my $pid=open(STDIN,"-|");
  return $pid if $pid;
  eval {
    $sub->();
  };
  my($ret);
  if($ret=!!$@) {
    warn "$@";
  };
  close(STDIN);
  exit($ret);
};
sub mkdir_p($;$);
sub QX {
  if(!defined(wantarray)) {
    QX(@_);
    return;
  } elsif( !wantarray ) {
    return join("", "@_");
  } else {
    open(local *STDIN,"-|",@_);
    local(@_)=<STDIN>;
    close(STDIN);
    @_;
  }
};
sub mkdir_p($;$) {
  no autodie qw(mkdir);
  my ($dir,$mode)=@_;
  return 1 if -d $dir;
  $mode=0755 unless defined($mode);
  return 1 if mkdir($dir,$mode);
  die "mkdir:$dir:$!" unless $!{ENOENT};
  my (@dir) = split(m{/+},$dir);
  pop(@dir);
  mkdir_p(join("/",@dir),$mode);
  mkdir($dir,$mode); 
};
sub getfds();
BEGIN {
  sub getfds() {
    opendir(my $dir,"/proc/self/fd");
    my $no = fileno($dir);
    while(readdir($dir)){
      push(@_,$_) unless $_ eq '.' or $_ eq '..' or fileno($dir)==$_;
    };
    closedir($dir);
    @_;
  };
};
sub matrix(){
  my $l;
  while(<>){
    my (@r) = split;
    for(scalar(@r)){
      $l=$_ if $l<$_;
    };
    push(@_,\@r);
  };
  @_;
};
sub open_fds(;$);
BEGIN {
  sub open_fds(;$) {
    my ($dn) = "/proc/self/fd/";
    if(@_ && $_[0]) {
      map { [ $_, readlink "$dn$_" ] } open_fds();
    } else {
      @_ = suckdir($dn);
      @_ = grep { -e } @_;
      @_ = grep { s{.*/}{} || 1 } @_;
    }
  };
  sub getcwd {
    return readlink("/proc/self/cwd");
  };
};
sub avg(@){
  return 0 unless @_;
  return sum(@_)/@_;
};
sub capture(@){
  my(@cmd)=@_;
  unless(open(STDIN,"-|")){
    open(STDERR,">&STDOUT");
    exec(@cmd);
    die "exec: ";
  };;
  @_=map { split } <STDIN>;
  no autodie 'close';
  close(STDIN);
  open(STDIN,"</dev/null");
  return join(" ",@_);
};
sub suckdir {
  return map { my($x); $x=suckdir($_); $x; } @_ unless @_==1;
  my ($path)=path(length?$_:".");
  local(@_)=sort $path->children;
  return wantarray?@_:\@_;
}
use File::stat qw(:FIELDS);

sub file_id {
  die "useless use of file_id in void context" unless defined wantarray;
  local ($_)=shift;
  die "!defined" unless defined;
  stat($_);
  my $file_id=sprintf("%016x:%016x",$st_dev,$st_ino);
  return $file_id;
};
#    sub suck(@){
#      die("useless use of suck in void context") unless defined wantarray;
#      if(@_==1) {
#        if(wantarray){
#          return path($_[0])->lines;
#        } else {
#          return path($_[0])->slurp;
#        }
#      } else {
#        if(wantarray){
#          return map { suck($_) } @_;
#        } else {
#          return join("\n\n",map { $_=suck($_) } @_);
#        }
#      }
#    };
{
  package Null;
};
sub class($){
  return ref||$_||'undef' for shift;
};
sub pasteLines(@) {
  for(join("",@_)){
    s{\\\n?$}{}sm;
  }
  return join("\n",@_) unless wantarray;
  return @_;
}
#    sub spit_fh($@){
#      my($fh)=shift;
#      $fh->print(join("",@_));
#    };
#    sub spit($@){
#      local($\,$/);
#      my ($fn,$fh)=(shift);
#      use autodie qw(open close);
#      if($fn =~ m{^<}){
#        die "error:  output file starts with <";
#      } elsif ( $fn =~ m{^>} ) {
#        # say nothing, act natural
#      } else {
#        $fn=">$fn";
#      };
#      open($fh,"$fn");
#      spit_fh($fh,@_);
#      close($fh);
#    };
sub maybeRef($) {
  carp "use class, not maybeRef";
  goto \&class;
};
sub uri {
  eval 'require URI';
  die "$@" if "$@";
  return URI->new($_);
};
sub vcmp {
  my ($a,$b) = (
    @_ == 2 ? (shift,shift) :
    @_ ? (undef, undef, warn "Warning:  vcmp wants 2 args or none") :
    ($a,$b)
  );

  my (@a)=split m{(\D+)}, $a;
  my (@b)=split m{(\D+)}, $b;
  no warnings;
  while( @a and @b and $a[0] eq $b[0] ) {
    shift @a;
    shift @b;
  };
  return 0 unless @a or @b;
  return @a <=> @b unless @a and @b;
  return $a[0] <=> $b[0] || $a[0] cmp $b[0];  
};
sub vsort {
  return sort { vcmp } @_;
};
my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst);
my @x=qw(sec min hour mday mon year wday yday isdst);
sub serdate(;$)
{
  my $time=@_ ? $_[0] : time;
  return strftime("%Y%m%d-%H%M%S", gmtime($time));
}
our(%caller);
sub deparse {
  eval "use B::Deparse";
  die "$@" if "$@";
  my $deparse = B::Deparse->new("-p", "-sC");
  return join(' ', 'sub{', $deparse->coderef2text(\&func), '}');
};
sub serial_maker(%) {
  my (%arg)=%{$_[0]};
  ddx(\%arg);
  my ($fmt)=$arg{fmt}//die "format is required";
  my ($max)=$arg{max}//1000;
  my ($min)=$arg{min}//0;
  my ($dir)=!!$arg{dir};
  my ($num)=$min;
  return sub {
    local($_);
    my (%res)=( fh=>undef, fn=>undef );
    for(;;){
      return undef if($num>=$max);
      $res{fn}=path(sprintf($fmt,$num));
      $res{fn}->parent->mkdir;
      ddx(\%res);
      no autodie qw(sysopen mkdir);
      if($dir) {
        if(mkdir($res{fn})){
          return \%res;
        } elsif ( $!{EEXIST} ) {
          ++$num;
        } else {
          confess "mkdir:$res{fn}:$!";
        };
      } else {
        if(sysopen($res{fh},$res{fn},Fcntl::O_CREAT|Fcntl::O_EXCL())){
          eex(\%res);
          return \%res 
        } elsif ( $!{EEXIST} ) {
          ++$num;
        } else {
          confess "sysopen:$res{fn}:$!";
        };
      }
    };
  };
};
#unless(caller){
#  use Carp;
#  sub test_date(;$) {
#    $,=" ";
#    $DB::single=1;
#    $DB::single=1;
#    my $time=time;
#    say $time;
#    my (@gm);
#    my $ser=serdate($time);
#    say $ser;
#    $_=$ser;
#    #    ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = 
#    ($year,$mon,$mday,$hour,$min,$sec)=map{int($_)}
#    (m{^(\d\d\d\d)(\d\d)(\d\d)-(\d\d)(\d\d)(\d\d)-gmt});
#    @_=( $sec, $min, $hour, $mday, $mon, $year, $wday, $yday, $isdst );
#    $year-=1900;
#    $mday++;
#    for(0 .. @_) {
#      my $idx="$_";
#      my $val=($_[$_]//-1);
#      my $tag=$x[$_];
#      #ddx([ $idx, $val, $tag ]);
#      #say $_, ($_[$_]//-1), ($x[$_]);
#    };
#    #ddx(\@_);
#  };
#  test_date;
#  exit(0);
#};


sub methods;
sub methods_via;
sub print_methods {
  require mro;
  ddx( methods ( ref($_[0]) ) );
};

use vars qw(%seen);

sub methods {

    # Figure out the class - either this is the class or it's a reference
    # to something blessed into that class.
    my $class = shift;
    $class = ref $class if ref $class;

    local %seen;

    # Show the methods that this class has.
    methods_via( $class, '', 1 );

    # Show the methods that UNIVERSAL has.
    methods_via( 'UNIVERSAL', 'UNIVERSAL', 0 );
} ## end sub methods

=head2 C<methods_via($class, $prefix, $crawl_upward)>

C<methods_via> does the work of crawling up the C<@ISA> tree and reporting
all the parent class methods. C<$class> is the name of the next class to
try; C<$prefix> is the message prefix, which gets built up as we go up the
C<@ISA> tree to show parentage; C<$crawl_upward> is 1 if we should try to go
higher in the C<@ISA> tree, 0 if we should stop.

=cut

sub methods_via {

    # If we've processed this class already, just quit.
    my $class = shift;
    return if $seen{$class}++;

    # This is a package that is contributing the methods we're about to print.
    my $prefix  = shift;
    my $prepend = $prefix ? "via $prefix: " : '';
    my @to_print;

    # Extract from all the symbols in this class.
    my $class_ref = do { no strict "refs"; \%{$class . '::'} };
    while (my ($name, $glob) = each %$class_ref) {
        # references directly in the symbol table are Proxy Constant
        # Subroutines, and are by their very nature defined
        # Otherwise, check if the thing is a typeglob, and if it is, it decays
        # to a subroutine reference, which can be tested by defined.
        # $glob might also be the value -1  (from sub foo;)
        # or (say) '$$' (from sub foo ($$);)
        # \$glob will be SCALAR in both cases.
        if ((ref $glob || ($glob && ref \$glob eq 'GLOB' && defined &$glob))
            && !$seen{$name}++) {
            push @to_print, "$prepend$name\n";
        }
    }

    {
        local $\ = '';
        local $, = '';
        print $_ foreach sort @to_print;
    }

    # If the $crawl_upward argument is false, just quit here.
    return unless shift;

    # $crawl_upward true: keep going up the tree.
    # Find all the classes this one is a subclass of.
    my $class_ISA_ref = do { no strict "refs"; \@{"${class}::ISA"} };
    for my $name ( @$class_ISA_ref ) {

        # Set up the new prefix.
        $prepend = $prefix ? $prefix . " -> $name" : $name;

        # Crawl up the tree and keep trying to crawl up.
        methods_via( $name, $prepend, 1 );
    }
} ## end sub methods_via
1;
=head1 NAME

Nobody::Util - Pretty printing of data structures

=head1 SYNOPSIS

This is a Lazy Bastard package that you probably don't want to use.
Nobody made it because Nobody is as lazy as he is.  It's full of
ugly hacks, but saves him time.

=cut
1;
