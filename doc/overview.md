# Project overview

This repository is an experiment in building a very small C++ runtime that relies only on Linux system calls. The build avoids the usual standard library and libc, producing static binaries that run directly on the kernel.

## Layout
- `bin/` – example utilities (printenv, touch, usleep, ...)
- `cni/` – minimal replacements for standard headers like `string_view`
- `doc/` – generated syscall tables and help text
- `etc/` – build flags and makefile fragments
- `inc/` – headers shared by the library and examples
- `lib/` – implementation of the runtime (startup code, syscalls, buffering)
- `sbin/` – helper scripts
- `tst/` – small test programs

## Key points
The library exposes Linux syscalls through inline assembly (`syscall.hh`) and provides simple I/O helpers such as `write_buf.hh`. Static constructors and atexit handlers are handled manually in `lib/init_array.cc`. The resulting executables show how to write C++ programs without the normal runtime support.

## Next steps
Those new to the project might look at:
1. `inc/syscall.hh` and `cni/syscall.hh` to see how syscalls are wrapped.
2. The build rules in `etc/` to understand the freestanding compilation model.
3. Programs in `bin/` and `tst/` to experiment with the environment.
