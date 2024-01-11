#include "../list.h"

template<auto N, auto X>
requires (IsNumeric<decltype(N)>)
constexpr auto iterateN() {
  if constexpr (N <= 0) {
    return List<>();
  } else {
    return List<X>().append(iterateN<N - 1, X>());
  }
}

void iterateN_test();