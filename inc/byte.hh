#pragma once

namespace std {

  enum class byte : unsigned char {};

  template<class Integer>
    constexpr Integer to_integer(byte b) noexcept {
      static_assert(__is_integral(Integer), 
          "to_integer<T>: T must be an integral type");
      return static_cast<Integer>(static_cast<unsigned char>(b));
    }

  // bitwise
  constexpr byte operator~(byte b) noexcept {
    return static_cast<byte>(~static_cast<unsigned char>(b));
  }
  constexpr byte operator|(byte l, byte r) noexcept {
    return static_cast<byte>(static_cast<unsigned char>(l) | static_cast<unsigned char>(r));
  }
  constexpr byte operator&(byte l, byte r) noexcept {
    return static_cast<byte>(static_cast<unsigned char>(l) & static_cast<unsigned char>(r));
  }
  constexpr byte operator^(byte l, byte r) noexcept {
    return static_cast<byte>(static_cast<unsigned char>(l) ^ static_cast<unsigned char>(r));
  }

  // compound assignment
  constexpr byte& operator|=(byte& l, byte r) noexcept { return l = (l | r); }
  constexpr byte& operator&=(byte& l, byte r) noexcept { return l = (l & r); }
  constexpr byte& operator^=(byte& l, byte r) noexcept { return l = (l ^ r); }

  // shifts: count must be an integral type
  template<class Integer>
    constexpr byte operator<<(byte b, Integer s) noexcept {
      static_assert(__is_integral(Integer), "shift count must be integral");
      return static_cast<byte>(static_cast<unsigned char>(b) << s);
    }
  template<class Integer>
    constexpr byte operator>>(byte b, Integer s) noexcept {
      static_assert(__is_integral(Integer), "shift count must be integral");
      return static_cast<byte>(static_cast<unsigned char>(b) >> s);
    }
  template<class Integer>
    constexpr byte& operator<<=(byte& b, Integer s) noexcept { return b = (b << s); }
  template<class Integer>
    constexpr byte& operator>>=(byte& b, Integer s) noexcept { return b = (b >> s); }

  // optional: hash support (useful even in freestanding)
  struct hash_byte {
    constexpr size_t operator()(byte b) const noexcept {
      return static_cast<size_t>(static_cast<unsigned char>(b));
    }
  };

} // namespace std

static_assert(sizeof(std::byte) == 1, "std::byte must be one octet");
