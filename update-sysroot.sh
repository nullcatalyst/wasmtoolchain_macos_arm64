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
bazel build -c opt --platforms=:wasm //src:libs

# Copy the libraries to the right place
cp -f bazel-bin/src/c/libc.a               sysroot/lib/libc.a
cp -f bazel-bin/src/c++/libc++.a           sysroot/lib/libc++.a
cp -f bazel-bin/src/dl/libdl.a             sysroot/lib/libdl.a
cp -f bazel-bin/src/dlmalloc/libdlmalloc.a sysroot/lib/libdlmalloc.a
cp -f bazel-bin/src/m/libm.a               sysroot/lib/libm.a
cp -f bazel-bin/src/rt/librt.a             sysroot/lib/librt.a
