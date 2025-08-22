
#define ERR_LIST(X) \
X(  EPERM,    1,   "Operation_not_permitted"              ) \
X(  ENOENT,   2,   "No_such_file_or_directory"            ) \
X(  ESRCH,    3,   "No_such_process"                      ) \
X(  EINTR,    4,   "Interrupted_system_call"              ) \
X(  EIO,      5,   "I/O_error"                            ) \
X(  ENXIO,    6,   "No_such_device_or_address"            ) \
X(  E2BIG,    7,   "Argument_list_too_long"               ) \
X(  ENOEXEC,  8,   "Exec_format_error"                    ) \
X(  EBADF,    9,   "Bad_file_number"                      ) \
X(  ECHILD,   10,  "No_child_processes"                   ) \
X(  EAGAIN,   11,  "Try_again"                            ) \
X(  ENOMEM,   12,  "Out_of_memory"                        ) \
X(  EACCES,   13,  "Permission_denied"                    ) \
X(  EFAULT,   14,  "Bad_address"                          ) \
X(  ENOTBLK,  15,  "Block_device_required"                ) \
X(  EBUSY,    16,  "Device_or_resource_busy"              ) \
X(  EEXIST,   17,  "File_exists"                          ) \
X(  EXDEV,    18,  "Cross-device_link"                    ) \
X(  ENODEV,   19,  "No_such_device"                       ) \
X(  ENOTDIR,  20,  "Not_a_directory"                      ) \
X(  EISDIR,   21,  "Is_a_directory"                       ) \
X(  EINVAL,   22,  "Invalid_argument"                     ) \
X(  ENFILE,   23,  "File_table_overflow"                  ) \
X(  EMFILE,   24,  "Too_many_open_files"                  ) \
X(  ENOTTY,   25,  "Not_a_typewriter"                     ) \
X(  ETXTBSY,  26,  "Text_file_busy"                       ) \
X(  EFBIG,    27,  "File_too_large"                       ) \
X(  ENOSPC,   28,  "No_space_left_on_device"              ) \
X(  ESPIPE,   29,  "Illegal_seek"                         ) \
X(  EROFS,    30,  "Read-only_file_system"                ) \
X(  EMLINK,   31,  "Too_many_links"                       ) \
X(  EPIPE,    32,  "Broken_pipe"                          ) \
X(  EDOM,     33,  "Math_argument_out_of_domain_of_func"  ) \
X(  ERANGE,   34,  "Math_result_not_representable"        )
#define X(s,n,m) s = n, \

namespace std {
  enum errno_t : int32_t {
    ERR_LIST(X)
      EWOULDBLOCK=EAGAIN
  };
};

#undef X
#undef ERR_LIST
