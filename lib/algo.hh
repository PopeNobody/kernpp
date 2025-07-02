//   #pragma once
//   template<class it1, class it2>
//   size_t copy(const it1 s1, it1 e1, it2 b2, it2 e2)
//   {
//     it1 b1(s1);
//     while(b1!=e1){
//       *b2++=*b1++;
//       if(b2==e2)
//         abort();
//     };
//     return b1-s1;
//   }
//   size_t copy(c_str src, c_str dst)
//   {
//     return copy(src.begin(),src.end(),dst.begin(),dst.end());
//   }
