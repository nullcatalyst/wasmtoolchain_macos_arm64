#include <locale>

_LIBCPP_BEGIN_NAMESPACE_STD

locale::locale() _NOEXCEPT { __builtin_trap(); }

locale::locale(locale const&) _NOEXCEPT { __builtin_trap(); }

locale::~locale() { __builtin_trap(); }

const locale::facet* locale::use_facet(id& x) const { __builtin_trap(); }

_LIBCPP_END_NAMESPACE_STD
