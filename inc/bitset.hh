#pragma once

//   #include <cstddef>
//   #include <cstdint>
namespace collect {
  template <size_t N>
    struct bitset_t {
      typedef uint64_t word_t;
      static constexpr size_t BITS = N;
      static constexpr size_t WORD_BITS = sizeof(word_t)*8;
      static constexpr size_t WORDS = (N + WORD_BITS - 1) / WORD_BITS;

      uint64_t vals[WORDS] = {};

      constexpr void set(size_t bit) {
        vals[bit / WORD_BITS] |= uint64_t(1) << (bit % WORD_BITS);
      }

      constexpr void clear(size_t bit) {
        vals[bit / WORD_BITS] &= ~(uint64_t(1) << (bit % WORD_BITS));
      }

      constexpr bool test(size_t bit) const {
        return vals[bit / WORD_BITS] & (uint64_t(1) << (bit % WORD_BITS));
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
