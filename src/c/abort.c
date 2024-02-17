#include <stdlib.h>

#include "src/wasm.h"

WASM_IMPORT("env", "abort")
_Noreturn void _abort_impl();

_Noreturn void abort() { _abort_impl(); }
