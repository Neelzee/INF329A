#include "../list.h"

template<auto N, auto X, auto... Xs>
requires (is_unityped(X, Xs...) && IsNumeric<decltype(N)>)
constexpr auto iterateN(List<X, Xs...> l) {
  if constexpr (N <= 0) {
    return List<>();
  } else {
    return List<X>().append(iterateN<N - 1>(l));
  }
}
