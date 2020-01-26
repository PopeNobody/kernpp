#!/bin/bash

g++ @cxxflags -static -I. -g    proc_file.s  -lstuff -o proc_file   -fPIC
