#! /usr/bin/env bash

# Stop on error
set -e

# Build the LLVM tools that we need
bazel build -c opt @llvm-project//clang --copt=-Os
bazel build -c opt @llvm-project//lld --copt=-Os
bazel build -c opt @llvm-project//llvm:llvm-ar --copt=-Os

# Copy the tools to the right place
# Only do this after successfully compiling all tools, to avoid a partial update / version mismatch
cp bazel-bin/external/llvm-project~override/clang/clang tools/clang
cp bazel-bin/external/llvm-project~override/lld/lld tools/lld
cp bazel-bin/external/llvm-project~override/llvm/llvm-ar tools/llvm-ar

