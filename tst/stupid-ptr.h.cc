#include "stupid-ptr.hh"

extern "C" {
int main() {
//       using arr = stupid_ptr<int, 4>; // 16-byte align → 4 tag bits (sizes 0..15)
//       auto p = arr::make(10);         // logical size 10, capacity padded so end is 16B aligned
//   
//       for (std::size_t i = 0; i < p.size(); ++i) p[i] = int(i * 3);
//   
//       std::printf("size=%zu, first=%d, last=%d\n",
//                   p.size(), p[0], p[p.size()-1]);

    // dtor frees
    return 0;
}
};
