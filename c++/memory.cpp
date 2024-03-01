#include <memory>

_LIBCPP_BEGIN_NAMESPACE_STD

__shared_count::~__shared_count() {}

__shared_weak_count::~__shared_weak_count() {}

#if defined(_LIBCPP_SHARED_PTR_DEFINE_LEGACY_INLINE_FUNCTIONS)
void __shared_count::__add_shared() noexcept {
    __libcpp_atomic_refcount_increment(__shared_owners_);
}

bool __shared_count::__release_shared() noexcept {
    if (__libcpp_atomic_refcount_decrement(__shared_owners_) == -1) {
        __on_zero_shared();
        return true;
    }
    return false;
}

void __shared_weak_count::__add_shared() noexcept { __shared_count::__add_shared(); }

void __shared_weak_count::__add_weak() noexcept {
    __libcpp_atomic_refcount_increment(__shared_weak_owners_);
}

void __shared_weak_count::__release_shared() noexcept {
    if (__shared_count::__release_shared()) __release_weak();
}
#endif  // _LIBCPP_SHARED_PTR_DEFINE_LEGACY_INLINE_FUNCTIONS

void __shared_weak_count::__release_weak() noexcept {
    // NOTE: The acquire load here is an optimization of the very
    // common case where a shared pointer is being destructed while
    // having no other contended references.
    //
    // BENEFIT: We avoid expensive atomic stores like XADD and STREX
    // in a common case.  Those instructions are slow and do nasty
    // things to caches.
    //
    // IS THIS SAFE?  Yes.  During weak destruction, if we see that we
    // are the last reference, we know that no-one else is accessing
    // us. If someone were accessing us, then they would be doing so
    // while the last shared / weak_ptr was being destructed, and
    // that's undefined anyway.
    //
    // If we see anything other than a 0, then we have possible
    // contention, and need to use an atomicrmw primitive.
    // The same arguments don't apply for increment, where it is legal
    // (though inadvisable) to share shared_ptr references between
    // threads, and have them all get copied at once.  The argument
    // also doesn't apply for __release_shared, because an outstanding
    // weak_ptr::lock() could read / modify the shared count.
    // if (__libcpp_atomic_load(&__shared_weak_owners_, _AO_Acquire) == 0) {
    if (__shared_weak_owners_ == 0) {
        // no need to do this store, because we are about
        // to destroy everything.
        //__libcpp_atomic_store(&__shared_weak_owners_, -1, _AO_Release);
        __on_zero_shared_weak();
    // } else if (__libcpp_atomic_refcount_decrement(__shared_weak_owners_) == -1)
    } else if ((__shared_weak_owners_ -= 1) == -1)
        __on_zero_shared_weak();
}

__shared_weak_count* __shared_weak_count::lock() noexcept {
    // long object_owners = __libcpp_atomic_load(&__shared_owners_);
    // while (object_owners != -1) {
    //     if (__libcpp_atomic_compare_exchange(&__shared_owners_, &object_owners, object_owners + 1))
    //         return this;
    // }
    // return nullptr;
    __shared_weak_owners_ += 1;
    return this;
}

const void* __shared_weak_count::__get_deleter(const type_info&) const noexcept { return nullptr; }

_LIBCPP_END_NAMESPACE_STD
