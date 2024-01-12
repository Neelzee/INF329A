#include "../list.h"
#include "../sfolds/sfolds.h"

#pragma once

template<auto X>
constexpr auto list_max(List<X>) {
  return X;
}

template <auto X, auto... Xs>
requires (is_unityped(X, Xs...))
constexpr auto list_max(List<X, Xs...> l) {
  return list_max(drop_while([](auto Y){ return X > Y; }, l));
}

void max_test();

template<auto X>
constexpr auto list_min(List<X>) {
  return X;
}

template <auto X, auto... Xs>
requires (is_unityped(X, Xs...))
constexpr auto list_min(List<X, Xs...> l) {
  return list_min(drop_while([](auto Y){ return X < Y; }, l));
}

void min_test();


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