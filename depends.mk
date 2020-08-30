bin/cat.o: /usr/include/stdc-predef.h
bin/cat.o: bin/cat.cc
bin/cat.o: include/c_str.hh
bin/cat.o: include/errno.hh
bin/cat.o: include/fmt.hh
bin/cat.o: include/getopt.hh
bin/cat.o: include/stdlib.hh
bin/cat.o: include/syscall.hh
bin/cat.o: include/types.hh

bin/echo.o: /usr/include/stdc-predef.h
bin/echo.o: bin/echo.cc
bin/echo.o: include/errno.hh
bin/echo.o: include/stdlib.hh
bin/echo.o: include/syscall.hh
bin/echo.o: include/types.hh

bin/ls.o: /usr/include/stdc-predef.h
bin/ls.o: bin/ls.cc
bin/ls.o: include/c_str.hh
bin/ls.o: include/errno.hh
bin/ls.o: include/fmt.hh
bin/ls.o: include/getopt.hh
bin/ls.o: include/new.hh
bin/ls.o: include/stdlib.hh
bin/ls.o: include/syscall.hh
bin/ls.o: include/types.hh

bin/report.o: /usr/include/stdc-predef.h
bin/report.o: bin/report.cc
bin/report.o: include/c_str.hh
bin/report.o: include/errno.hh
bin/report.o: include/fmt.hh
bin/report.o: include/getopt.hh
bin/report.o: include/stdlib.hh
bin/report.o: include/syscall.hh
bin/report.o: include/types.hh

bin/string_view.o: /usr/include/stdc-predef.h
bin/string_view.o: bin/string_view.cc
bin/string_view.o: include/string_view.hh

bin/usleep.o: /usr/include/stdc-predef.h
bin/usleep.o: bin/usleep.cc
bin/usleep.o: include/c_str.hh
bin/usleep.o: include/errno.hh
bin/usleep.o: include/fmt.hh
bin/usleep.o: include/getopt.hh
bin/usleep.o: include/stdlib.hh
bin/usleep.o: include/syscall.hh
bin/usleep.o: include/types.hh

lib/abi.o: /usr/include/stdc-predef.h
lib/abi.o: include/errno.hh
lib/abi.o: include/stdlib.hh
lib/abi.o: include/syscall.hh
lib/abi.o: include/types.hh
lib/abi.o: lib/abi.cc

lib/c_str.o: /usr/include/stdc-predef.h
lib/c_str.o: include/c_str.hh
lib/c_str.o: include/errno.hh
lib/c_str.o: include/stdlib.hh
lib/c_str.o: include/syscall.hh
lib/c_str.o: include/types.hh
lib/c_str.o: lib/c_str.cc

lib/delete.o: /usr/include/stdc-predef.h
lib/delete.o: include/errno.hh
lib/delete.o: include/new.hh
lib/delete.o: include/stdlib.hh
lib/delete.o: include/syscall.hh
lib/delete.o: include/types.hh
lib/delete.o: lib/delete.cc

lib/dyncast.o: /usr/include/stdc-predef.h
lib/dyncast.o: include/cxxabi.hh
lib/dyncast.o: include/errno.hh
lib/dyncast.o: include/stdlib.hh
lib/dyncast.o: include/syscall.hh
lib/dyncast.o: include/tinfo.hh
lib/dyncast.o: include/typeinfo.hh
lib/dyncast.o: include/types.hh
lib/dyncast.o: lib/dyncast.cc

lib/errno.o: /usr/include/stdc-predef.h
lib/errno.o: include/c_str.hh
lib/errno.o: include/errno.hh
lib/errno.o: include/fmt.hh
lib/errno.o: include/stdlib.hh
lib/errno.o: include/syscall.hh
lib/errno.o: include/types.hh
lib/errno.o: include/write_buf.hh
lib/errno.o: lib/errno.cc

lib/getopt.o: /usr/include/stdc-predef.h
lib/getopt.o: include/errno.hh
lib/getopt.o: include/getopt.hh
lib/getopt.o: include/stdlib.hh
lib/getopt.o: include/syscall.hh
lib/getopt.o: include/types.hh
lib/getopt.o: lib/getopt.cc

lib/init_array.o: /usr/include/stdc-predef.h
lib/init_array.o: include/errno.hh
lib/init_array.o: include/stdlib.hh
lib/init_array.o: include/syscall.hh
lib/init_array.o: include/types.hh
lib/init_array.o: lib/init_array.cc

lib/mm.o: /usr/include/stdc-predef.h
lib/mm.o: include/c_str.hh
lib/mm.o: include/errno.hh
lib/mm.o: include/fmt.hh
lib/mm.o: include/stdlib.hh
lib/mm.o: include/syscall.hh
lib/mm.o: include/types.hh
lib/mm.o: include/write_buf.hh
lib/mm.o: lib/mm.cc

lib/new.o: /usr/include/stdc-predef.h
lib/new.o: include/errno.hh
lib/new.o: include/new.hh
lib/new.o: include/stdlib.hh
lib/new.o: include/syscall.hh
lib/new.o: include/types.hh
lib/new.o: lib/new.cc

lib/stdlib.o: /usr/include/stdc-predef.h
lib/stdlib.o: include/stdlib.hh
lib/stdlib.o: include/types.hh
lib/stdlib.o: lib/stdlib.cc

lib/strerror_list.o: /usr/include/stdc-predef.h
lib/strerror_list.o: include/c_str.hh
lib/strerror_list.o: include/errno.hh
lib/strerror_list.o: include/stdlib.hh
lib/strerror_list.o: include/syscall.hh
lib/strerror_list.o: include/types.hh
lib/strerror_list.o: lib/strerror_list.cc

lib/type_info.o: /usr/include/stdc-predef.h
lib/type_info.o: include/cxxabi.hh
lib/type_info.o: include/errno.hh
lib/type_info.o: include/stdlib.hh
lib/type_info.o: include/syscall.hh
lib/type_info.o: include/tinfo.hh
lib/type_info.o: include/typeinfo.hh
lib/type_info.o: include/types.hh
lib/type_info.o: lib/type_info.cc

lib/unistd.o: /usr/include/stdc-predef.h
lib/unistd.o: include/errno.hh
lib/unistd.o: include/stdlib.hh
lib/unistd.o: include/syscall.hh
lib/unistd.o: include/types.hh
lib/unistd.o: lib/unistd.cc

lib/write_buf.o: /usr/include/stdc-predef.h
lib/write_buf.o: include/c_str.hh
lib/write_buf.o: include/errno.hh
lib/write_buf.o: include/fmt.hh
lib/write_buf.o: include/stdlib.hh
lib/write_buf.o: include/syscall.hh
lib/write_buf.o: include/types.hh
lib/write_buf.o: include/write_buf.hh
lib/write_buf.o: lib/write_buf.cc

