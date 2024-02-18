#include <stdlib.h>

#include "src/wasm.h"

WASM_IMPORT("env", "exit")
_Noreturn void _exit_impl(int);

_Noreturn void exit(int exit_code) { _exit_impl(exit_code); }
_Noreturn void _exit(int exit_code) { _exit_impl(exit_code); }
