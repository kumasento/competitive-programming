#include <functional>
#include <iostream>

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html

template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

  template <class... Args> decltype(auto) operator()(Args &&... args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int main() {

#if 0
  std::function<int(int, int)> gcd = [&](int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  };
  std::cout << gcd(20, 30) << std::endl;
#endif

  auto almost_gcd = [](auto gcd, int a, int b) -> int {
    return b == 0 ? a : gcd(b, a % b);
  };
  auto gcd = y_combinator(std::ref(almost_gcd));
  std::cout << gcd(20, 30) << std::endl;
}
