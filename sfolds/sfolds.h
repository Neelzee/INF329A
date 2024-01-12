#include "../list.h"
#include "../subl/subl.h"
#include "../list_ops/list_ops.h"

#pragma once

template<typename F>
constexpr auto foldl(F, auto acc, List<>) {
  return acc;
}

template<typename F, auto... Xs>
requires (is_unityped(Xs...))
constexpr auto foldl(F f, auto acc, List<Xs...> l) {
  return foldl(f, f(acc, head(l)), tail(l));
}

void test_foldl();

template<typename F>
constexpr auto foldr(F, auto acc, List<>) {
  return acc;
}

template<typename F, auto... Xs>
requires (is_unityped(Xs...))
constexpr auto foldr(F f, auto acc, List<Xs...> l) {
  return foldr(f, f(acc, last(l)), init(l));
}

void test_foldr();

template<auto... Xs>
requires ((BoolConvertible<decltype(Xs)> && ...) && is_unityped(Xs...))
constexpr bool list_and(List<Xs...> l) {
  return foldr([](auto X, auto Y) { return X && Y; }, true, l);
}

void test_list_and();


template<auto... Xs>
requires ((BoolConvertible<decltype(Xs)> && ...) && is_unityped(Xs...))
constexpr bool list_or(List<Xs...> l) {
  return foldr([](auto X, auto Y) { return X || Y; }, true, l);
}

void test_list_or();

template<auto... Xs>
requires ((BoolConvertible<decltype(Xs)> && ...) && is_unityped(Xs...))
constexpr bool list_any(List<Xs...> l) {
  return filter(l, [](auto X) { return X; }).length() != 0;
}

void test_list_any();

template<List... Xs>
constexpr auto concat(List<Xs...> l) {
  return foldr([](auto acc, auto x) { return acc.append(x); }, List<>(), l);
}

void test_concat();

template<List... Xs, typename F>
constexpr auto concat_map(List<Xs...> l, F f) {
  return map(foldr([f](auto acc, auto x) { return acc.append(x); }, List<>(), l), f);
}

void test_concat_map();

void test_sfolds();