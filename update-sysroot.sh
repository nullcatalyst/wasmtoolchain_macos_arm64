#! /usr/bin/env bash

# Stop on error
set -e

if [ ! -f tools/clang ]; then
    echo "Please run update-tools.sh first"
    exit 1
fi

# The following commands expect the toolchain to be built successfully, since it is used to actually
# compile the libraries

# Build the standard libraries
bazel build -c opt --copt=-Os --platforms=:wasm //src/c
bazel build -c opt --copt=-Os --platforms=:wasm //src/dlmalloc:dl
bazel build -c opt --copt=-Os --platforms=:wasm //src/math:m

# Copy the libraries to the right place
cp bazel-bin/src/c/libc.a           sysroot/lib/libc.a
cp bazel-bin/src/dlmalloc/libdl.a   sysroot/lib/libdl.a
cp bazel-bin/src/math/libm.a        sysroot/lib/libm.a
