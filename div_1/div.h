#include "../list.h"
#include "../sfolds/sfolds.h"

#pragma once

template<auto X, auto... Xs>
requires (is_unityped(X, Xs...))
constexpr auto list_max(List<X, Xs...> l) {
  return max_helper<X>(l);
}

void max_test();

template<auto M, auto X>
constexpr auto max_helper(List<X>) {
  if constexpr (X > M) {
    return X;
  } else {
    return M;
  }
}

template<auto M, auto X, auto... Xs>
constexpr auto max_helper(List<X, Xs...> l) {
  if constexpr (X > M) {
    return max_helper<X>(l);
  } else {
    return max_helper<M>(l);
  }
}

template<auto X, auto... Xs>
requires (is_unityped(X, Xs...))
constexpr auto list_min(List<Xs...> l) {
  return min_helper(l, X);
}

void min_test();

template<auto X>
constexpr auto min_helper(List<X> l, auto m) {
  if constexpr (X < m) {
    return X;
  } else {
    return m;
  }
}

template<auto X, auto... Xs>
constexpr auto min_helper(List<X, Xs...> l, auto m) {
  if constexpr (X < m) {
    return min_helper(l, X);
  } else {
    return min_helper(l, m);
  }
}

template<auto... Xs>
requires (is_unityped(Xs...) && 0 < sizeof... (Xs))
constexpr auto list_sum(List<Xs...> l) {
  return foldl([](auto sum, auto x) { return sum + x; }, 0, l);
}

void sum_test();

template<auto... Xs>
requires (is_unityped(Xs...) && 0 < sizeof... (Xs))
constexpr auto list_product(List<Xs...> l) {
  return foldl([](auto sum, auto x) { return sum * x; }, 1, l);
}

void product_test();