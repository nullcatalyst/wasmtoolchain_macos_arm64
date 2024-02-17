#! /usr/bin/env bash

# Stop on error
set -e

# Build the LLVM tools that we need
bazel build -c opt --copt=-Os @llvm-project//clang
bazel build -c opt --copt=-Os @llvm-project//lld
bazel build -c opt --copt=-Os @llvm-project//llvm:llvm-ar

# Only do the following after successfully compiling all tools, to avoid a partial update / version
# mismatch

# Copy the tools to the right place
cp bazel-bin/external/llvm-project~override/clang/clang   tools/clang
cp bazel-bin/external/llvm-project~override/lld/lld       tools/lld
cp bazel-bin/external/llvm-project~override/llvm/llvm-ar  tools/llvm-ar

cd tools
ln -s clang clang++
ln -s lld wasm-ld
