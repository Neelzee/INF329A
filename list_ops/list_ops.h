/**
 * List Operations
 */

#include "../list.h"
#include <tuple>

#pragma once

template<typename F, auto X>
constexpr auto map(List<X>, F f) {
  return List<f(X)>();
}

template<typename F, auto... Xs>
requires (sizeof... (Xs) > 0 && (InvocableWith<F, decltype(Xs)> && ...) && is_unityped(Xs...))
constexpr auto map(List<Xs...> l, F f) {
  return List<f(head(l))>().append(map(tail(l), f));
}

void test_map();

template<typename F, auto X>
requires (InvocableWith<F, decltype(X)>)
constexpr auto filter(List<X>, F f) {
  if constexpr (f(X)) {
    return List<X>();
  } else {
    return List<>();
  }
}

template<typename F, auto X, auto... Xs>
requires (sizeof... (Xs) > 0 && InvocableWith<F, decltype(X)> && is_unityped(X, Xs...))
constexpr auto filter(List<X, Xs...>, F f) {
  if constexpr (f(X)) {
    return List<X>().append(filter(List<Xs...>(), f));
  } else {
    return filter(List<Xs...>(), f);
  }
}

void test_filter();

template<auto X, auto... Xs>
requires (is_unityped(X, Xs...))
constexpr auto head(List<X, Xs...>) {
  return X;
}

void test_head();

template<auto X>
constexpr auto last(List<X>) {
  return X;
}

template<auto... Xs>
requires (0 <= sizeof...(Xs)) && (is_unityped(Xs...))
constexpr auto last(List<Xs...> l) {
  return last(tail(l));
}

void test_last();

template<auto X, auto... Xs>
requires (is_unityped(X, Xs...))
constexpr auto tail(List<X, Xs...>) {
  return List<Xs...>();
}

void test_tail();


constexpr bool null(List<>) {
  return true;
}

template<auto... Xs>
requires (is_unityped(Xs...))
constexpr bool null(List<Xs...>) {
  return false;
}

void test_null();

template<std::size_t n, auto... Xs>
requires (n <= sizeof...(Xs) && is_unityped(Xs...))
constexpr auto get(List<Xs...> l) {
  if constexpr (n == 0) {
    return head(l);
  } else {
    return get<n - 1>(tail(l));
  }
}

void get_test();

constexpr auto reverse(List<> l) {
  return l;
}

void reverse_test();

template<auto X, auto... Xs>
requires (sizeof... (Xs) + 1 > 0 && is_unityped(X, Xs...))
constexpr auto reverse(List<X, Xs...> l) {
  return cons_append<X>(reverse(tail(l)));
}


void test_list_ops();