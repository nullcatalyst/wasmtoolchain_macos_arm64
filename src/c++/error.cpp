#include <system_error>

_LIBCPP_BEGIN_NAMESPACE_STD

error_category::~error_category() noexcept {}

error_condition error_category::default_error_condition(int ev) const noexcept {
    return error_condition(ev, *this);
}

bool error_category::equivalent(int code, const error_condition& condition) const noexcept {
    return default_error_condition(code) == condition;
}

bool error_category::equivalent(const error_code& code, int condition) const noexcept {
    return *this == code.category() && code.value() == condition;
}

string error_code::message() const { return __cat_->message(__val_); }

class _LIBCPP_HIDDEN __generic_error_category : public __do_message {
  public:
    virtual const char* name() const noexcept;
    virtual string      message(int ev) const;
};

const char* __generic_error_category::name() const noexcept { return "generic"; }

string __generic_error_category::message(int ev) const {
// #ifdef _LIBCPP_ELAST
//     if (ev > _LIBCPP_ELAST) return string("unspecified generic_category error");
// #endif  // _LIBCPP_ELAST
//     return __do_message::message(ev);
    return string("unspecified generic_category error");
}

const error_category& generic_category() noexcept {
    static __generic_error_category s;
    return s;
}

class _LIBCPP_HIDDEN __system_error_category : public __do_message {
  public:
    virtual const char*     name() const noexcept;
    virtual string          message(int ev) const;
    virtual error_condition default_error_condition(int ev) const noexcept;
};

const char* __system_error_category::name() const noexcept { return "system"; }

string __system_error_category::message(int ev) const {
// #ifdef _LIBCPP_ELAST
//     if (ev > _LIBCPP_ELAST) return string("unspecified system_category error");
// #endif  // _LIBCPP_ELAST
//     return __do_message::message(ev);
    return string("unspecified system_category error");
}

error_condition __system_error_category::default_error_condition(int ev) const noexcept {
#ifdef _LIBCPP_ELAST
    if (ev > _LIBCPP_ELAST) return error_condition(ev, system_category());
#endif  // _LIBCPP_ELAST
    return error_condition(ev, generic_category());
}

const error_category& system_category() noexcept {
    static __system_error_category s;
    return s;
}

_LIBCPP_END_NAMESPACE_STD
