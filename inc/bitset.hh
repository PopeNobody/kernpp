#pragma once

#include "fmt.hh"
namespace collect {
  template <size_t N>
    struct bitset_t {
      typedef uint16_t word_t;
      static constexpr size_t BITS = N;
      static constexpr size_t WORD_BITS = sizeof(word_t)*8;
      static constexpr size_t WORDS = (N + WORD_BITS - 1) / WORD_BITS;

      uint64_t vals[WORDS] = {};

      void check_bit(size_t bit)const;
      constexpr void set(size_t bit) {
        check_bit(bit);
        vals[bit / WORD_BITS] |= (word_t(1) << (bit % WORD_BITS));
      }

      constexpr void clear(size_t bit) {
        check_bit(bit);
        vals[bit / WORD_BITS] &= ~(word_t(1) << (bit % WORD_BITS));
      }
      constexpr bool is_set(size_t bit) const {
        return test(bit);
      };
      constexpr bool get(size_t bit) const {
        return test(bit);
      };
      constexpr bool test(size_t bit) const {
        check_bit(bit);
        return vals[bit / WORD_BITS] & (word_t(1) << (bit % WORD_BITS));
      }

      constexpr void reset() {
        for (size_t i = 0; i < WORDS; ++i) {
          vals[i] = 0;
        }
      }

      constexpr bool any() const {
        for (size_t i = 0; i < WORDS; ++i) {
          if (vals[i] != 0) return true;
        }
        return false;
      }

      constexpr bool none() const {
        return !any();
      }

      int find_highest() const {
        for (size_t i = WORDS; i-- > 0;) {
          if (vals[i] != 0) {
#if defined(__GNUC__) || defined(__clang__)
            int leading_zeros = __builtin_clzll(vals[i]);
            int bit_index = 63 - leading_zeros;
#else
            int bit_index = -1;
            uint64_t v = vals[i];
            while (v) {
              v >>= 1;
              ++bit_index;
            }
#endif
            return int(i * WORD_BITS + bit_index);
          }
        }
        return -1;
      }
      char* format(char* b, char* e, char zero_char = '0', char one_char = '1') const {
        if ((e - b) > ptrdiff_t(N)) {

          for (size_t i = 0; i < N; ++i) {
            *b++ = test(N - 1 - i) ? one_char : zero_char;  // MSB first
          }

          *b = '\0';
          return b;
        } else {
          *b=0;
          return 0;
        };
      }
    };
}
namespace sys {
  struct fdset_t : public collect::bitset_t<32> {
    fdset_t select(timeval_t);
    fdset_t( fd_t fd1=fd_t(), fd_t fd2=fd_t(), fd_t fd3=fd_t(),
        fd_t fd4=fd_t(), fd_t fd5=fd_t(), fd_t fd6=fd_t(),
        fd_t fd7=fd_t(), fd_t fd8=fd_t(), fd_t fd9=fd_t()
        );

  };
};
