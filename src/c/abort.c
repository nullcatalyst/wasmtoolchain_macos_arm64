#include <stdlib.h>

#include "src/wasm.h"

WASM_IMPORT("env", "abort")
_Noreturn void _abort_impl();

_Noreturn void abort() { _abort_impl(); }

// std::terminate called by C++ unwinding code
void _ZSt9terminatev() { abort(); }

// std::unexpected called by C++ unwinding code
void _ZSt10unexpectedv() { abort(); }
