#pragma once

namespace sys {
  template<class T>
    void clear(T&) {
      memset(&T,0,sizeof(T));
    }
};
