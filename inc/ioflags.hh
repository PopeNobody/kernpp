#pragma once
namespace sys
{
#define linux_dirent64 linux_dirent
  enum open_mode
  {
    o_default= 0664
  };
  enum open_flags
  {
    o_rdonly   = 0000,
    o_wronly   = 0001,
    o_rdwr     = 0002,
    o_mask     = 0003,
    o_creat    = 00000100,
    o_excl     = 00000200,
    o_noctty   = 00000400,
    o_trunc    = 00001000,
    o_append   = 00002000,
    o_nonblock = 00004000,
    o_dsync    = 00010000,
    o_fasync   = 00020000,
    o_direct   = 00040000,
    o_largefile= 00100000,
    o_directory= 00200000,
    o_nofollow = 00400000,
    o_noatime  = 01000000,
    o_cloexec  = 02000000,
  };
  inline open_flags operator|(open_flags lhs, open_flags rhs)
  {
    return open_flags(int(lhs) | int(rhs));
  }
  inline open_flags operator&(open_flags lhs, open_flags rhs)
  {
    return open_flags(int(lhs) & int(rhs));
  }
} // namespace sys
