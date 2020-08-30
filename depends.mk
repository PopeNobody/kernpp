bin/cat.o: bin/cat.cc /usr/include/stdc-predef.h include/fmt.hh \
 include/syscall.hh include/errno.hh include/types.hh include/stdlib.hh \
 include/c_str.hh include/getopt.hh
bin/echo.o: bin/echo.cc /usr/include/stdc-predef.h include/syscall.hh \
 include/errno.hh include/types.hh include/stdlib.hh
bin/ls.o: bin/ls.cc /usr/include/stdc-predef.h include/syscall.hh \
 include/errno.hh include/types.hh include/stdlib.hh include/new.hh \
 include/fmt.hh include/c_str.hh include/getopt.hh
bin/report.o: bin/report.cc /usr/include/stdc-predef.h include/errno.hh \
 include/types.hh include/fmt.hh include/syscall.hh include/stdlib.hh \
 include/c_str.hh include/getopt.hh
bin/string_view.o: bin/string_view.cc /usr/include/stdc-predef.h \
 include/string_view.hh
bin/usleep.o: bin/usleep.cc /usr/include/stdc-predef.h include/syscall.hh \
 include/errno.hh include/types.hh include/stdlib.hh include/fmt.hh \
 include/c_str.hh include/getopt.hh
lib/abi.o: lib/abi.cc /usr/include/stdc-predef.h include/syscall.hh \
 include/errno.hh include/types.hh include/stdlib.hh
lib/c_str.o: lib/c_str.cc /usr/include/stdc-predef.h include/c_str.hh \
 include/syscall.hh include/errno.hh include/types.hh include/stdlib.hh
lib/delete.o: lib/delete.cc /usr/include/stdc-predef.h include/syscall.hh \
 include/errno.hh include/types.hh include/stdlib.hh include/new.hh
lib/dyncast.o: lib/dyncast.cc /usr/include/stdc-predef.h include/tinfo.hh \
 include/syscall.hh include/errno.hh include/types.hh include/stdlib.hh \
 include/typeinfo.hh include/cxxabi.hh
lib/errno.o: lib/errno.cc /usr/include/stdc-predef.h include/errno.hh \
 include/types.hh include/syscall.hh include/stdlib.hh \
 include/write_buf.hh include/c_str.hh include/fmt.hh
lib/getopt.o: lib/getopt.cc /usr/include/stdc-predef.h include/syscall.hh \
 include/errno.hh include/types.hh include/stdlib.hh include/getopt.hh
lib/init_array.o: lib/init_array.cc /usr/include/stdc-predef.h \
 include/types.hh include/syscall.hh include/errno.hh include/stdlib.hh
lib/mm.o: lib/mm.cc /usr/include/stdc-predef.h include/syscall.hh \
 include/errno.hh include/types.hh include/stdlib.hh include/fmt.hh \
 include/c_str.hh include/write_buf.hh
lib/new.o: lib/new.cc /usr/include/stdc-predef.h include/syscall.hh \
 include/errno.hh include/types.hh include/stdlib.hh include/new.hh
lib/stdlib.o: lib/stdlib.cc /usr/include/stdc-predef.h include/stdlib.hh \
 include/types.hh
lib/strerror_list.o: lib/strerror_list.cc /usr/include/stdc-predef.h \
 include/c_str.hh include/syscall.hh include/errno.hh include/types.hh \
 include/stdlib.hh
lib/type_info.o: lib/type_info.cc /usr/include/stdc-predef.h \
 include/tinfo.hh include/syscall.hh include/errno.hh include/types.hh \
 include/stdlib.hh include/typeinfo.hh include/cxxabi.hh
lib/unistd.o: lib/unistd.cc /usr/include/stdc-predef.h include/syscall.hh \
 include/errno.hh include/types.hh include/stdlib.hh
lib/write_buf.o: lib/write_buf.cc /usr/include/stdc-predef.h \
 include/write_buf.hh include/c_str.hh include/syscall.hh \
 include/errno.hh include/types.hh include/stdlib.hh include/fmt.hh
