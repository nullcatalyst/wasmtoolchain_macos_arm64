#include <__config>
#include <thread>

_LIBCPP_BEGIN_NAMESPACE_STD

unsigned thread::hardware_concurrency() _NOEXCEPT { return 0; }

thread::~thread() {}

void thread::join() {}

void thread::detach() {}

namespace this_thread {

void sleep_for(const chrono::nanoseconds& ns) {}

}  // namespace this_thread

// __thread_specific_ptr<__thread_struct>& __thread_local_data() { return nullptr; }

// __thread_struct_imp

template <class T>
class _LIBCPP_HIDDEN __hidden_allocator {
  public:
    typedef T value_type;

    T*   allocate(size_t __n) { return static_cast<T*>(::operator new(__n * sizeof(T))); }
    void deallocate(T* __p, size_t) { ::operator delete(static_cast<void*>(__p)); }

    size_t max_size() const { return size_t(~0) / sizeof(T); }
};

class _LIBCPP_HIDDEN __thread_struct_imp {
    typedef vector<__assoc_sub_state*, __hidden_allocator<__assoc_sub_state*> > _AsyncStates;
    typedef vector<pair<condition_variable*, mutex*>,
                   __hidden_allocator<pair<condition_variable*, mutex*> > >
        _Notify;

    // _AsyncStates async_states_;
    // _Notify notify_;

    __thread_struct_imp(const __thread_struct_imp&);
    __thread_struct_imp& operator=(const __thread_struct_imp&);

  public:
    __thread_struct_imp() {}
    ~__thread_struct_imp();

    void notify_all_at_thread_exit(condition_variable* cv, mutex* m);
    void __make_ready_at_thread_exit(__assoc_sub_state* __s);
};

__thread_struct_imp::~__thread_struct_imp() {}

void __thread_struct_imp::notify_all_at_thread_exit(condition_variable* cv, mutex* m) {}

void __thread_struct_imp::__make_ready_at_thread_exit(__assoc_sub_state* __s) {}

// __thread_struct

__thread_struct::__thread_struct() {}

__thread_struct::~__thread_struct() {}

void __thread_struct::notify_all_at_thread_exit(condition_variable* cv, mutex* m) {}

void __thread_struct::__make_ready_at_thread_exit(__assoc_sub_state* __s) {}

__thread_specific_ptr<__thread_struct>&
__thread_local_data() {
  // Even though __thread_specific_ptr's destructor doesn't actually destroy
  // anything (see comments there), we can't call it at all because threads may
  // outlive the static variable and calling its destructor means accessing an
  // object outside of its lifetime, which is UB.
  alignas(__thread_specific_ptr<__thread_struct>) static char __b[sizeof(__thread_specific_ptr<__thread_struct>)];
  static __thread_specific_ptr<__thread_struct>* __p = new (__b) __thread_specific_ptr<__thread_struct>();
  return *__p;
}

_LIBCPP_END_NAMESPACE_STD
