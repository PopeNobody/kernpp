// forward example
#include <utility>      // std::forward
#include <iostream>     // std::cout

// function with lvalue and rvalue reference overloads:
void overloaded (const int& x) {std::cout << "[lvalue]";}
void overloaded (int&& x) {std::cout << "[rvalue]";}

// function template taking rvalue reference to deduced type:
template <class T> void fn (T&& x) {
  overloaded (x);                   // always an lvalue
  overloaded (std::forward<T>(x));  // rvalue if argument is rvalue
}
using namespace std;
template<typename T>
void test_rr(T && x)
{
  cout << __PRETTY_FUNCTION__ << endl;
};
template<typename T>
void test_r(T & x)
{
  cout << __PRETTY_FUNCTION__ << endl;
};
template<typename T>
void test_v(T x)
{
  cout << __PRETTY_FUNCTION__ << endl;
};
int main () {
  int a;

  std::cout << "calling fn with lvalue: ";
  fn (a);
  std::cout << '\n';

  std::cout << "calling fn with rvalue: ";
  fn (0);
  std::cout << '\n';

  int &x(a);

  int r[5];

  test_rr(0);
  test_v(0);

  test_r(a);
  test_rr(a);
  test_v(a);

  test_r(x);
  test_rr(x);
  test_v(x);

  test_r(r);
  test_rr(r);
  test_v(r);
  return 0;
}
