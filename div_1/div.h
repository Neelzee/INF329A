#include "../list.h"
#include "../sfolds/sfolds.h"

#pragma once

template<auto X, auto... Xs>
requires (is_unityped(X, Xs...))
constexpr auto max(List<Xs...> l) {
  return max_helper(l, X);
}

template<auto X>
constexpr auto max_helper(List<X> l, auto m) {
  if constexpr (X > m) {
    return X;
  } else {
    return m;
  }
}

template<auto X, auto... Xs>
constexpr auto max_helper(List<X, Xs...> l, auto m) {
  if constexpr (X > m) {
    return max_helper(l, X);
  } else {
    return max_helper(l, m);
  }
}


template<auto X, auto... Xs>
requires (is_unityped(X, Xs...))
constexpr auto min(List<Xs...> l) {
  return min_helper(l, X);
}

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
constexpr auto sum(List<Xs...> l) {
  return foldl([](auto sum, auto x) { return sum + x; }, l);
}

template<auto... Xs>
requires (is_unityped(Xs...) && 0 < sizeof... (Xs))
constexpr auto product(List<Xs...> l) {
  return foldl([](auto sum, auto x) { return sum * x; }, l);
}