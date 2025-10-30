// stupid_ptr.h
#include "syscall.hh"
#include "template-glue.hh"
#pragma once
//   #include <cstddef>
//   #include <cstdint>
//   #include <new>
//   #include <type_traits>
//   #include <utility>

namespace std {
  template<class T>
    struct is_void : integral_constant<bool,false> {
    };
  template< class T >
    constexpr bool is_void_v = is_void<T>::value;
  template<class T>
    struct is_object : integral_constant<bool,false> {
    };
  template< class T >
    constexpr bool is_object_v = is_object<T>::value;
  template< bool B >
    using bool_constant = integral_constant<bool, B>;
      
};
namespace ptr {
  template<class T, std::size_t bits>
    struct stupid_ptr {
      static_assert(std::is_object_v<T> && !std::is_void_v<T>,
          "T must be an object type");
      static_assert(bits > 0 && bits < (sizeof(uintptr_t) * 8),
          "bits must be in 1..pointer_bits-1");

      using value_type = T;

      static constexpr std::size_t tag_bits = bits;
      static constexpr uintptr_t   tag_mask = (uintptr_t(1) << tag_bits) - 1;
      static constexpr std::size_t align    = std::size_t(1) << tag_bits;

      static_assert((align & (align - 1)) == 0, "align must be power of two");
      static_assert(align >= alignof(T),        "align must not under-align T");

      // layout: (aligned_end_pointer | size_tag)
      // note: aligned_end_pointer has its low `bits` zero.
      uintptr_t end_plus_tag = 0;

      // --- helpers -------------------------------------------------------------

      static constexpr std::size_t
        round_up(std::size_t n, std::size_t a) {
          return (n + (a - 1)) & ~(a - 1);
        }

      static constexpr std::size_t
        round_up_elems(std::size_t n_elems) {
          // bytes needed for n_elems
          const std::size_t bytes = n_elems * sizeof(T);
          // round up to alignment, convert back to elems (may pad)
          return round_up(bytes, align) / sizeof(T);
        }

      static T* mask_ptr(uintptr_t x) {
        return reinterpret_cast<T*>(x & ~tag_mask);
      }

      static uintptr_t unmask_ptr(const T* p) {
        return (reinterpret_cast<uintptr_t>(p) & ~tag_mask);
      }

      // --- observers -----------------------------------------------------------

      bool empty() const { return size() == 0; }

      std::size_t size() const {
        return static_cast<std::size_t>(end_plus_tag & tag_mask);
      }

      T* end_ptr() const { // aligned end-of-capacity pointer (one past last slot)
        return mask_ptr(end_plus_tag);
      }

      T* begin() const {
        return end_ptr() - size();
      }

      T* end() const {
        return end_ptr();
      }

      T& operator[](std::size_t i) const {
        return begin()[i]; // bounds are your problem (this is the "stupid" part)
      }

      explicit operator bool() const { return end_plus_tag != 0; }

      // expose raw pointer to first element
      T* get() const { return begin(); }

      // --- construction / destruction -----------------------------------------

      // default: null
      stupid_ptr() = default;

      // allocate and default-construct n elements
      static stupid_ptr make(std::size_t n) {
        stupid_ptr sp;
        if (n == 0) return sp;

        // pick a capacity whose *end* lands on alignment boundary
        const std::size_t cap = round_up_elems(n);

        // over-aligned allocation
        void* raw = ::operator new[](cap * sizeof(T), std::align_val_t(align));
        T* base   = static_cast<T*>(raw);

        // default-construct only the logical size (not the padding)
        std::size_t i = 0;
        try {
          for (; i < n; ++i) ::new (static_cast<void*>(base + i)) T();
        } catch (...) {
          // roll back constructed elements
          while (i--) (base + i)->~T();
          ::operator delete[](raw, std::align_val_t(align));
          throw;
        }

        // compute aligned end pointer
        T* aligned_end = base + cap;

        // store tag
        sp.end_plus_tag = unmask_ptr(aligned_end) | uintptr_t(n);
        return sp;
      }

      // adopt an existing buffer [p, p+n) with capacity padded so that (p+cap) is aligned.
      // caller guarantees the memory was allocated with align and that cap==round_up_elems(n).
      static stupid_ptr adopt(T* base, std::size_t n) {
        stupid_ptr sp;
        if (!base || n == 0) return sp;
        const std::size_t cap = round_up_elems(n);
        T* aligned_end = base + cap;
        sp.end_plus_tag = unmask_ptr(aligned_end) | uintptr_t(n);
        return sp;
      }

      // move only (copy would be thorny unless we define a policy)
      stupid_ptr(stupid_ptr&& other) noexcept : end_plus_tag(other.end_plus_tag) {
        other.end_plus_tag = 0;
      }
      stupid_ptr& operator=(stupid_ptr&& other) noexcept {
        if (this == &other) return *this;
        destroy();
        end_plus_tag = other.end_plus_tag;
        other.end_plus_tag = 0;
        return *this;
      }

      stupid_ptr(const stupid_ptr&) = delete;
      stupid_ptr& operator=(const stupid_ptr&) = delete;

      // destroy elements and free
      void destroy() {
        if (!end_plus_tag) return;

        T* e   = end_ptr();
        T* beg = begin();

        // destruct only the logical size
        for (T* p = beg; p != beg + size(); ++p) {
          p->~T();
        }

        // recover base via capacity = (e - base). We don't know it directly,
        // but delete[] doesn't need it; we just pass the base pointer.
        // base = e - cap. cap = round_up_elems(size()). Because we chose cap deterministically
        // from size(), e - cap == base.
        T* base = e - round_up_elems(size());
        ::operator delete[](base, std::align_val_t(align));

        end_plus_tag = 0;
      }

      ~stupid_ptr() { destroy(); }
    };
}
