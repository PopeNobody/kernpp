set -exv

g++ @cxxflags -static -I. -g -E proc_file.cc   -o proc_file.o.i -fPIC -MF proc_file.cc.d -MT proc_file.o -MD
g++ @cxxflags -static -I. -g -S proc_file.o.i -o proc_file.o.s -fPIC
g++ @cxxflags -static -I. -g -c proc_file.o.s -o proc_file.o         -fPIC
g++ @cxxflags -static -I. -g -E debug.cc   -o debug.o.i -fPIC -MF debug.cc.d -MT debug.o -MD
g++ @cxxflags -static -I. -g -S debug.o.i -o debug.o.s -fPIC
g++ @cxxflags -static -I. -g -c debug.o.s -o debug.o         -fPIC
g++ @cxxflags -static -I. -g -E errno.cc   -o errno.o.i -fPIC -MF errno.cc.d -MT errno.o -MD
g++ @cxxflags -static -I. -g -S errno.o.i -o errno.o.s -fPIC
g++ @cxxflags -static -I. -g -c errno.o.s -o errno.o         -fPIC
g++ @cxxflags -static -I. -g -E write_buf.cc   -o write_buf.o.i -fPIC -MF write_buf.cc.d -MT write_buf.o -MD
g++ @cxxflags -static -I. -g -S write_buf.o.i -o write_buf.o.s -fPIC
g++ @cxxflags -static -I. -g -c write_buf.o.s -o write_buf.o         -fPIC
g++ @cxxflags -static -I. -g -E c_str.cc   -o c_str.o.i -fPIC -MF c_str.cc.d -MT c_str.o -MD
g++ @cxxflags -static -I. -g -S c_str.o.i -o c_str.o.s -fPIC
g++ @cxxflags -static -I. -g -c c_str.o.s -o c_str.o         -fPIC
g++ @cxxflags -static -I. -g -E check_print.cc   -o check_print.o.i -fPIC -MF check_print.cc.d -MT check_print.o -MD
g++ @cxxflags -static -I. -g -S check_print.o.i -o check_print.o.s -fPIC
g++ @cxxflags -static -I. -g -c check_print.o.s -o check_print.o         -fPIC
ar rU libstuff.a.new  debug.o  errno.o  write_buf.o  c_str.o  check_print.o
mv libstuff.a.new libstuff.a
g++ @cxxflags -static -I. -g    proc_file.o  -o proc_file   -fPIC -L. -lstuff
