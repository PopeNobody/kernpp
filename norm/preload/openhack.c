#define _GNU_SOURCE
#include <assert.h>
#include <ctype.h>
#include <dlfcn.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

typedef int fd_t;
typedef const char* istr_t;
typedef char* ostr_t;

// clang-format off
#define  fn_list(x)     \
	x(abort) \
	x(__fxstat) \
	x(__xstat) \
	x(__lxstat) \
	x(__fxstatat) \
	x(__fxstat64) \
	x(__xstat64) \
	x(__lxstat64) \
	x(__fxstatat64) \
         x(access)      \
         x(chdir)       \
         x(chmod)       \
         x(chown)       \
         x(creat)       \
         x(faccessat)   \
         x(fchmodat)    \
         x(fchownat)    \
         x(lchown)      \
         x(link)        \
         x(linkat)      \
         x(mkdir)       \
         x(mkdirat)     \
         x(open)        \
         x(openat)      \
         x(readlink)    \
         x(readlinkat)  \
         x(rename)      \
         x(renameat)    \
         x(rmdir)       \
         x(symlink)     \
         x(symlinkat)   \
         x(truncate)    \
         x(unlink)      \
         x(unlinkat)
// clang-format on


#define rep_decl( x ) typeof( &x ) d_##x;
#define rep_init( x ) d_##x = xdlsym( RTLD_NEXT, #x );
#define xxx dprintf( 2, "d_%s = %p\n", #x, d_##x );
#undef xxx

fn_list( rep_decl );

void abort()
{
  dprintf( 2, "about to abort\n" );
  d_abort();
};
void* xdlsym( void* handle, const char* symbol )
{
  void* res = dlsym( handle, symbol );
  if ( !res )
    dprintf( 2, "dlsym(%p,%s)=>%p %s\n", handle, symbol, res, dlerror() );
  return res;
};

void _init( void )
{
  dprintf( 2, "entering '%s'\n", __PRETTY_FUNCTION__ );
  fn_list( rep_init );
}
#undef rep_decl
#undef rep_init
#undef fn_list

char fix1[ 4096 ];
char fix2[ 4096 ];

char* fixpath( const char* src, char* dst )
{
  char* cp = dst;
  *cp = 0;
  if ( !src )
    return 0;
  if ( strlen( src ) > 4096 )
    return (char*)src;
  char ch;
  while ( ( ch = *src++ ) )
  {
    if ( isspace( ch ) )
      *cp++ = '_';
    else
      *cp++ = ch;
  };
  *cp = 0;
  return dst;
};
int creat( const char* path, mode_t mode )
{
  assert( d_creat );
  path = fixpath( path, fix1 );
  dprintf( 2, "creat(%s,%d)=>", path, mode );
  int res = d_creat( path, mode );
  dprintf( 2, "%d\n", res );
  return res;
};
int renameat( fd_t odir, istr_t opath, fd_t ndir, istr_t npath )
{
  assert( d_renameat );
  opath = fixpath( opath, fix1 );
  npath = fixpath( npath, fix2 );
  dprintf( 2,
           "renameat(%d, \"%s\", %d, \"%s\")=>",
           odir,
           opath,
           ndir,
           npath );
  int res = d_renameat( odir, opath, ndir, npath );
  dprintf( 2, "%d\n", res );
  return res;
};
int rename( istr_t opath, istr_t npath )
{
  assert( d_rename );
  opath = fixpath( opath, fix1 );
  npath = fixpath( npath, fix2 );
  dprintf( 2, "rename(\"%s\", \"%s\")=>", opath, npath );
  int res = d_rename( opath, npath );
  dprintf( 2, "%d\n", res );
  return res;
};
int openat( int dirfd, const char* path, int flags, ... )
{
  assert( d_openat );
  va_list vl;
  va_start( vl, flags );
  int i = va_arg( vl, int );
  va_end( vl );
  int res;
  path = fixpath( path, fix1 );
  dprintf( 2, "openat(%d,\"%s\",%d,%o)=>", dirfd, path, flags, i );
  res = d_openat( dirfd, path, flags, i );
  dprintf( 2, "%d\n", res );
  return res;
};
int open( const char* path, int flags, ... )
{
  assert( d_open );
  va_list vl;
  va_start( vl, flags );
  int i = va_arg( vl, int );
  va_end( vl );
  int res;
  path = fixpath( path, fix1 );
  dprintf( 2, "open(\"%s\",%d,%o)=>", path, flags, i );
  res = d_open( path, flags, i );
  dprintf( 2, "%d\n", res );
  return res;
};

void _fini( void )
{
  dprintf( 2, "entering '%s'\n", __PRETTY_FUNCTION__ );
};

int access( istr_t path, int mode )
{
  if ( !d_access )
    return 1;
  assert( d_access );
  int res;
  path = fixpath( path, fix1 );
  dprintf( 2, "access(%s,%d)=>", path, mode );
  res = d_access( path, mode );
  dprintf( 2, "%d\n", res );
  return res;
};
int chdir( istr_t path )
{
  assert( d_chdir );
  int res;
  path = fixpath( path, fix1 );
  dprintf( 2, "chdir(%s)=>", path );
  res = d_chdir( path );
  dprintf( 2, "%d\n", res );
  return res;
};
int chmod( istr_t path, mode_t mode )
{
  assert( d_chmod );
  int res;
  path = fixpath( path, fix1 );
  dprintf( 2, "chmod(%s,%d)=>", path, mode );
  res = d_chmod( path, mode );
  dprintf( 2, "%d\n", res );
  return res;
};
int chown( istr_t path, uid_t user, gid_t group )
{
  assert( d_chown );
  int res;
  path = fixpath( path, fix1 );
  dprintf( 2, "chown(%s,%d,%d)=>", path, user, group );
  res = d_chown( path, user, group );
  dprintf( 2, "%d\n", res );
  return res;
};
int faccessat( fd_t dfd, istr_t path, int type, int flag )
{
  assert( d_faccessat );
  int res;
  path = fixpath( path, fix1 );
  dprintf( 2, "faccessat(%d,%s,%d,%d)=>", dfd, path, type, flag );
  res = d_faccessat( dfd, path, type, flag );
  dprintf( 2, "%d\n", res );
  return res;
};
int fchmodat( fd_t dfd, istr_t path, mode_t mode, int flag )
{
  assert( d_fchmodat );
  int res;
  path = fixpath( path, fix1 );
  dprintf( 2, "fchmodat(%d,%s,%d,%d)=>", dfd, path, mode, flag );
  res = d_fchmodat( dfd, path, mode, flag );
  dprintf( 2, "%d\n", res );
  return res;
};
int fchownat( fd_t dfd, istr_t path, uid_t user, gid_t group, int flag )
{
  assert( d_fchownat );
  int res;
  path = fixpath( path, fix1 );
  dprintf( 2, "fchownat(%d,%s,%d,%d,%d)=>", dfd, path, user, group, flag );
  res = d_fchownat( dfd, path, user, group, flag );
  dprintf( 2, "%d\n", res );
  return res;
};
int lchown( istr_t path, uid_t user, gid_t group )
{
  assert( d_lchown );
  int res;
  path = fixpath( path, fix1 );
  dprintf( 2, "lchown(%s,%d,%d)=>", path, user, group );
  res = d_lchown( path, user, group );
  dprintf( 2, "%d\n", res );
  return res;
};
int link( istr_t opath, istr_t npath )
{
  assert( d_link );
  int res;
  opath = fixpath( opath, fix1 );
  npath = fixpath( npath, fix2 );
  dprintf( 2, "link(%s,%s)=>", opath, npath );
  res = d_link( opath, npath );
  dprintf( 2, "%d\n", res );
  return res;
};
int linkat( fd_t oldfd, istr_t opath, fd_t newfd, istr_t npath, int flags )
{
  int res;
  assert( d_linkat );
  opath = fixpath( opath, fix1 );
  npath = fixpath( npath, fix2 );
  dprintf( 2,
           "linkat(%d,%s,%d,%s,%d)=>",
           oldfd,
           opath,
           newfd,
           npath,
           flags );
  res = d_linkat( oldfd, opath, newfd, npath, flags );
  dprintf( 2, "%d\n", res );
  return res;
};
int mkdir( istr_t path, mode_t mode )
{
  int res;
  assert( d_mkdir );
  path = fixpath( path, fix1 );
  dprintf( 2, "mkdir(%s,%d)=>", path, mode );
  res = d_mkdir( path, mode );
  dprintf( 2, "%d\n", res );
  return res;
};
int mkdirat( fd_t dfd, istr_t path, mode_t mode )
{
  int res;
  assert( d_mkdirat );
  path = fixpath( path, fix1 );
  dprintf( 2, "mkdirat(%d,%s,%d)=>", dfd, path, mode );
  res = d_mkdirat( dfd, path, mode );
  dprintf( 2, "%d\n", res );
  return res;
};
ssize_t readlink( istr_t path, ostr_t buf, size_t bufsiz )
{
  int res;
  assert( d_readlink );
  path = fixpath( path, fix1 );
  dprintf( 2, "readlink(%s,%p,%lu)=>", path, buf, bufsiz );
  res = d_readlink( path, buf, bufsiz );
  dprintf( 2, "%d\n", res );
  return res;
};
ssize_t readlinkat( fd_t dfd, istr_t path, ostr_t buf, size_t bufsiz )
{
  ssize_t res;
  assert( d_readlinkat );
  path = fixpath( path, fix1 );
  dprintf( 2, "readlinkat(%d,%s,%p,%lu)=>", dfd, path, buf, bufsiz );
  res = d_readlinkat( dfd, path, buf, bufsiz );
  dprintf( 2, "%ld\n", res );
  return res;
};
int rmdir( istr_t path )
{
  int res;
  assert( d_rmdir );
  path = fixpath( path, fix1 );
  dprintf( 2, "rmdir(%s)=>", path );
  res = d_rmdir( path );
  dprintf( 2, "%d\n", res );
  return res;
};
int symlink( istr_t opath, istr_t npath )
{
  int res;
  assert( d_symlink );
  opath = fixpath( opath, fix1 );
  npath = fixpath( npath, fix2 );
  dprintf( 2, "symlink(%s,%s)=>", opath, npath );
  res = d_symlink( opath, npath );
  dprintf( 2, "%d\n", res );
  return res;
};
int symlinkat( istr_t opath, fd_t newfd, istr_t npath )
{
  int res;
  assert( d_symlinkat );
  opath = fixpath( opath, fix1 );
  npath = fixpath( npath, fix2 );
  dprintf( 2, "symlinkat(%s,%d,%s)=>", opath, newfd, npath );
  res = d_symlinkat( opath, newfd, npath );
  dprintf( 2, "%d\n", res );
  return res;
};
int truncate( istr_t path, ssize_t length )
{
  int res;
  assert( d_truncate );
  path = fixpath( path, fix1 );
  dprintf( 2, "truncate(%s,%ld)=>", path, length );
  res = d_truncate( path, length );
  dprintf( 2, "%d\n", res );
  return res;
};
int unlink( istr_t path )
{
  int res;
  assert( d_unlink );
  path = fixpath( path, fix1 );
  dprintf( 2, "unlink(%s)=>", path );
  res = d_unlink( path );
  dprintf( 2, "%d\n", res );
  return res;
};
int unlinkat( fd_t dfd, istr_t path, int flag )
{
  int res;
  assert( d_unlinkat );
  path = fixpath( path, fix1 );
  dprintf( 2, "unlinkat(%d,%s,%d)=>", dfd, path, flag );
  res = d_unlinkat( dfd, path, flag );
  dprintf( 2, "%d\n", res );
  return res;
};
int __xstat( int v, const char* path, struct stat* buf )
{
  int res = -1;
  path = fixpath( path, fix1 );
  dprintf( 2, "__xstat(%d,%s,%p)=>", v, path, buf );
  //res = d___xstat( v, path, buf );
  dprintf( 2, "%d\n", res );
  return res;
};
extern int __lxstat( int v, const char* path, struct stat* buf )
{
  int res = -1;
  path = fixpath( path, fix1 );
  dprintf( 2, "__lxstat(%d,%s,%p)=>", v, path, buf );
  res = d___lxstat( v, path, buf );
  dprintf( 2, "%d\n", res );
  return res;
};
extern int __fxstatat( int ver,
                       int dfd,
                       const char* path,
                       struct stat* statbuf,
                       int flag )
{
  int res;
  assert( d___fxstatat );
  path = fixpath( path, fix1 );
  dprintf( 2,
           "fxstatat(%d,%d,%s,%p,%d)=>",
           ver,
           dfd,
           path,
           statbuf,
           flag );
  res = d___fxstatat( ver, dfd, path, statbuf, flag );
  dprintf( 2, "%d\n", res );
  return res;
};
int __xstat64( int v, const char* path, struct stat64* buf )
{
  int res = -1;
  path = fixpath( path, fix1 );
  dprintf( 2, "__xstat64(%d,%s,%p)=>", v, path, buf );
  res = d___xstat64( v, path, buf );
  dprintf( 2, "%d\n", res );
  return res;
};
extern int __lxstat64( int v, const char* path, struct stat64* buf )
{
  int res = -1;
  path = fixpath( path, fix1 );
  dprintf( 2, "__lxstat64(%d,%s,%p)=>", v, path, buf );
  res = d___lxstat64( v, path, buf );
  dprintf( 2, "%d\n", res );
  return res;
};
extern int __fxstatat64( int ver,
                         int dfd,
                         const char* path,
                         struct stat64* statbuf,
                         int flag )
{
  int res;
  assert( d___fxstatat64 );
  dprintf( 2,
           "__fxstatat64(%d,%d,%s,%p,%d)=>",
           ver,
           dfd,
           path,
           statbuf,
           flag );
  res = d___fxstatat64( ver, dfd, path, statbuf, flag );
  dprintf( 2, "%d\n", res );
  return res;
};
