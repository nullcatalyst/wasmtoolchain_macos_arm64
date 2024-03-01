"""
This file is used to define wrappers for cc_library and cc_binary rules.

These wrappers are used to generate build rules for C/C++ targets, that only pass the srcs to be
compiled when targetting WebAssembly.

This is useful because it creates empty builds for non-WebAssembly targets, so that they can still
be included in the list of deps without affecting non-WebAssembly builds.
"""

def wasm_cc_library(name, srcs = [], **kwargs):
    native.cc_library(
        name = name,
        srcs = select({
            # Only compile the srcs if the target is being built for WebAssembly
            "@platforms//cpu:wasm32": srcs,
            "//conditions:default": [],
        }),
        **kwargs
    )

def wasm_cc_binary(name, srcs = [], **kwargs):
    native.cc_binary(
        name = name,
        srcs = select({
            # Only compile the srcs if the target is being built for WebAssembly
            "@platforms//cpu:wasm32": srcs,
            "//conditions:default": [],
        }),
        **kwargs
    )
