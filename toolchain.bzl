load(
    "@bazel_tools//tools/build_defs/cc:action_names.bzl",
    "ACTION_NAMES",
)
load(
    "@bazel_tools//tools/cpp:cc_toolchain_config_lib.bzl",
    "artifact_name_pattern",
    "feature",
    "flag_group",
    "flag_set",
    "tool_path",
    "with_feature_set",
)

def _tool_path(path):
    return "tools/{}".format(path)

def _sysroot_path(ctx, path):
    prefix = ""
    if ctx.label.workspace_name == "":
        # Support for using the toolchain for compiling its own libraries
        prefix = "sysroot"
    else:
        prefix = "external/{}/sysroot".format(ctx.label.workspace_name)

    if path:
        return "{}/{}".format(prefix, path)
    else:
        return prefix

def _wasm_toolchain_config_impl(ctx):
    include_stdlib = True

    cc_tool_path = _tool_path("clang")
    cpp_tool_path = _tool_path("clang++")
    ld_tool_path = _tool_path("wasm-ld")
    ar_tool_path = _tool_path("llvm-ar")

    tool_paths = [
        tool_path(name = "gcc", path = cc_tool_path),
        tool_path(name = "cpp", path = cpp_tool_path),
        tool_path(name = "ld", path = ld_tool_path),
        tool_path(name = "ar", path = ar_tool_path),
        tool_path(name = "nm", path = "false"),
        tool_path(name = "objdump", path = "false"),
        tool_path(name = "strip", path = "false"),
    ]

    cxx_builtin_include_directories = []
    if include_stdlib:
        cxx_builtin_include_directories = [
            _sysroot_path(ctx, "include"),
        ]

    artifact_name_patterns = [
        artifact_name_pattern(
            category_name = "executable",
            prefix = "",
            extension = ".wasm",
        ),
    ]

    all_link_actions = [
        ACTION_NAMES.cpp_link_executable,
        ACTION_NAMES.cpp_link_dynamic_library,
        ACTION_NAMES.cpp_link_nodeps_dynamic_library,
    ]
    all_assemble_actions = [
        ACTION_NAMES.assemble,
        ACTION_NAMES.preprocess_assemble,
    ]
    c_compile_actions = [
        ACTION_NAMES.linkstamp_compile,
        ACTION_NAMES.c_compile,
        ACTION_NAMES.lto_backend,
    ]
    cpp_compile_actions = [
        ACTION_NAMES.cpp_compile,
        ACTION_NAMES.cpp_header_parsing,
        ACTION_NAMES.cpp_module_compile,
        ACTION_NAMES.cpp_module_codegen,
    ]
    all_compile_actions = c_compile_actions + cpp_compile_actions

    link_flags = []
    if include_stdlib:
        link_flags = [
            "-L" + _sysroot_path(ctx, "lib"),
            "-lc",
            "-lc++",
            "-ldlmalloc",
        ]
    default_linker_flags = feature(
        name = "default_linker_flags",
        enabled = True,
        flag_sets = [
            flag_set(
                actions = all_link_actions,
                flag_groups = ([
                    flag_group(
                        flags = link_flags + [
                            "--target=wasm32-unknown-unknown",
                            "-Wl,--no-entry",
                            "-Wl,--export-table",
                            "--no-standard-libraries",
                            "-Wl,--allow-undefined",
                        ],
                    ),
                ]),
            ),
        ],
    )

    c_sys_hdrs = []
    cpp_sys_hdrs = []
    if include_stdlib:
        c_sys_hdrs = [
            "-isystem",
            _sysroot_path(ctx, "include/compat"),
            "-isystem",
            _sysroot_path(ctx, "include"),
        ]
        cpp_sys_hdrs = [
            "-isystem",
            _sysroot_path(ctx, "include/c++/v1"),
        ]
    default_compile_flags = feature(
        name = "default_compile_flags",
        enabled = True,
        flag_sets = [
            flag_set(
                actions = all_link_actions + all_assemble_actions + all_compile_actions,
                flag_groups = [
                    flag_group(
                        flags = [
                            "--target=wasm32-unknown-unknown",
                            "-D__wasm__=1",
                            "-D__wasm32__=1",
                            # Fake being exmpscripten, as there is better support for emscripten
                            # in existing libraries, compared to being completely platformless.
                            "-D__EMSCRIPTEN__=1",
                        ],
                    ),
                ],
            ),
            flag_set(
                actions = all_assemble_actions,
                flag_groups = [
                    flag_group(
                        flags = [
                            "-fno-canonical-system-headers",
                        ],
                    ),
                ],
            ),
            flag_set(
                actions = cpp_compile_actions,
                flag_groups = [
                    flag_group(
                        flags = [
                            "-nostdinc++",
                            "-std=c++20",
                            "-fno-rtti",
                            "-fno-exceptions",
                        ] + cpp_sys_hdrs,
                    ),
                ],
            ),
            flag_set(
                actions = c_compile_actions + cpp_compile_actions,
                flag_groups = [
                    flag_group(
                        flags = [
                            "-nostdinc",
                        ] + c_sys_hdrs,
                    ),
                ],
            ),
            flag_set(
                actions = all_link_actions + all_assemble_actions + all_compile_actions,
                flag_groups = [
                    flag_group(flags = [
                        "-glldb",
                        "-O0",
                    ]),
                ],
                with_features = [with_feature_set(features = ["dbg"])],
            ),
            flag_set(
                actions = all_link_actions + all_assemble_actions + all_compile_actions,
                flag_groups = [
                    flag_group(flags = [
                        "-glldb",
                        "-gline-tables-only",
                        "-O1",
                    ]),
                ],
                with_features = [with_feature_set(features = ["fastbuild"])],
            ),
            flag_set(
                actions = all_link_actions + all_assemble_actions + all_compile_actions,
                flag_groups = [
                    flag_group(
                        flags = [
                            "-g0",
                            "-Os",
                            "-flto",
                            "-DNDEBUG",
                        ],
                    ),
                ],
                with_features = [with_feature_set(features = ["opt"])],
            ),
        ],
    )

    user_compile_flags = feature(
        name = "user_compile_flags",
        enabled = True,
        flag_sets = [
            flag_set(
                actions = all_assemble_actions + all_compile_actions,
                flag_groups = [
                    flag_group(
                        flags = ["%{user_compile_flags}"],
                        iterate_over = "user_compile_flags",
                        expand_if_available = "user_compile_flags",
                    ),
                ],
            ),
        ],
    )

    include_paths = feature(
        name = "include_paths",
        enabled = True,
        flag_sets = [
            flag_set(
                actions = c_compile_actions + cpp_compile_actions,
                flag_groups = [
                    flag_group(
                        flags = ["-iquote", "%{quote_include_paths}"],
                        iterate_over = "quote_include_paths",
                    ),
                    flag_group(
                        flags = ["-I%{include_paths}"],
                        iterate_over = "include_paths",
                    ),
                    flag_group(
                        flags = ["-isystem", "%{system_include_paths}"],
                        iterate_over = "system_include_paths",
                    ),
                ],
            ),
        ],
    )

    unfiltered_compile_flags = feature(
        name = "unfiltered_compile_flags",
        enabled = True,
        flag_sets = [
            flag_set(
                actions = all_assemble_actions + all_compile_actions,
                flag_groups = [
                    flag_group(
                        flags = [
                            # Do not resolve our symlinked resource prefixes to real paths.
                            "-no-canonical-prefixes",
                            # "-fno-canonical-system-headers",
                            # Reproducibility
                            "-Wno-builtin-macro-redefined",
                            "-D__DATE__=\"redacted\"",
                            "-D__TIMESTAMP__=\"redacted\"",
                            "-D__TIME__=\"redacted\"",
                        ],
                    ),
                ],
            ),
        ],
    )

    features = [
        feature(name = "dbg"),
        feature(name = "opt"),
        feature(name = "fastbuild"),
        default_linker_flags,
        default_compile_flags,
        user_compile_flags,
        include_paths,
        unfiltered_compile_flags,
    ]

    return cc_common.create_cc_toolchain_config_info(
        ctx = ctx,
        features = features,
        artifact_name_patterns = artifact_name_patterns,
        cxx_builtin_include_directories = cxx_builtin_include_directories,
        toolchain_identifier = "wasm32-toolchain",
        host_system_name = "local",
        target_system_name = "wasm32",
        target_cpu = "wasm32",
        target_libc = "unknown",
        compiler = "clang",
        abi_version = "unknown",
        abi_libc_version = "unknown",
        tool_paths = tool_paths,
    )

wasm_toolchain_config = rule(
    implementation = _wasm_toolchain_config_impl,
    attrs = {},
    provides = [CcToolchainConfigInfo],
)
