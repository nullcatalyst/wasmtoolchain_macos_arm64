# wasmtoolchain_macos_arm64

A minimal toolchain to compile C/C++ to WebAssembly on macOS

(The below was tested using bazel version 7.0.2)

## Adding the toolchain

Add the following to your `MODULE.bazel` file in order to use the included WebAssembly C/C++
toolchain.

```
bazel_dep(name = "wasm_toolchain", version = "0.0.1")

_WASM_TOOLCHAIN_COMMIT = "a566bdb3c9d1cddf489364b5ee24c1be8d62c4ba"
archive_override(
    module_name = "wasm_toolchain",
    urls = [
        "https://github.com/nullcatalyst/wasmtoolchain_macos_arm64/archive/{}.tar.gz".format(_WASM_TOOLCHAIN_COMMIT)
    ],
    integrity = "sha256-tqTvy2Z8/RuLgQNvTsleTlv7PFDHbIB9K42jMPhf/ek=",
    strip_prefix = "wasmtoolchain_macos_arm64-{}".format(_WASM_TOOLCHAIN_COMMIT),
)

register_toolchains(
    "@wasm_toolchain//:toolchain",
)
```

## Compiling using the toolchain

The toolchain will automatically be used when targeting a platform that has a wasm32 cpu, and no OS.
A platform matching these requirements is provided in the repo, at `@wasm_toolchain//:wasm`.

This means that this toolchain will automatically be used for the following command:

```
bazel build //path/to/my:target --platforms=@wasm_toolchain//:wasm
```

This can be a pain to type, so an alternative is to create the file `.bazelrc` beside your
`MODULE.bazel` file (if one wasn't already created), and add:

```
# WebAssembly specific configuration
build:wasm --platforms=@wasm_toolchain//:wasm
```

Which will allow passing the flag `--config wasm` to any build command instead. This is far easier
to both remember, and to type.

```
bazel build //path/to/my:target --config wasm
```
