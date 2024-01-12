#include "../list.h"
#include "../list_ops/list_ops.h"
#include <iostream>
#include <tuple>

#pragma once

constexpr auto zip(List<> a, List<> b) {
  return List<>();
}

template<auto... Xs>
requires (is_unityped(Xs...))
constexpr auto zip(List<Xs...> a, List<> b) {
  return List<>();
}

template<auto... Ys>
requires (is_unityped(Ys...))
constexpr auto zip(List<> a, List<Ys...> b) {
  return List<>();
}

template<auto... Xs, auto... Ys> requires (
std::is_literal_type_v<decltype(Xs)> && ...) && (std::is_literal_type_v<decltype(Ys)> && ...) && (is_unityped(Xs..., Ys...))
constexpr auto zip(List<Xs...> a, List<Ys...> b) {
  using FirstType = decltype(head(a));
  using SecondType = decltype(head(b));

  return cons<std::pair<FirstType, SecondType>(head(a), head(b))>(List<>())
          .append(zip(tail(a), tail(b)));
}

template<std::pair... Xs>
requires (sizeof... (Xs) > 0)
constexpr auto unzip(List<Xs...> l) {
  if constexpr (l.length() > 1) {
    auto rem = unzip(tail(l));
    return std::make_pair(cons<head(l).first>(rem.first), cons<head(l).second>(rem.second));
  } else {
    return std::make_pair(List<head(l).first>(), List<head(l).second>());
  }
}

template<typename F>
constexpr auto zip_with(F, List<>, List<>) {
  return List<>();
}

template<auto... Xs, auto... Ys, typename F>
requires (sizeof... (Xs) == sizeof... (Ys)) && (is_unityped(Xs..., Ys...))
constexpr auto zip_with(F f, List<Xs...> a, List<Ys...> b) {
  return List<f(head(a), head(b))>().append(zip_with(f, tail(a), tail(b)));
}


void test_zip();

void test_unzip();

void test_zip_with();

void test_zip3();

void test_zip_main();