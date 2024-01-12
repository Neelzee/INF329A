#include "../list.h"
#include "../list_ops/list_ops.h"

#pragma once

template<auto ACC, typename F>
constexpr auto scanl(F, List<>) {
  return List<ACC>();
}

template<auto ACC, typename F, auto... Xs>
requires (is_unityped(Xs...))
constexpr auto scanl(F f, List<Xs...> l) {
  constexpr auto newAcc = f(ACC, head(l));
  return List<ACC>().append(scanl<newAcc>(f, tail(l)));
}

void test_scanl();

template<typename F, auto... Xs>
requires (is_unityped(Xs...))
constexpr auto scanl1(F f, List<Xs...> l) {
  return scanl<head(l)>(f, tail(l));
}

void test_scanl1();

template<auto ACC, typename F>
constexpr auto scanr(F, List<>) {
  return List<ACC>();
}

template<auto ACC, typename F, auto... Xs>
requires (is_unityped(Xs...))
constexpr auto scanr(F f, List<Xs...> l) {
  constexpr auto newAcc = f(ACC, last(l));
  return List<ACC>().append(scanr<newAcc>(f, init(l)));
}

void test_scanr();

template<typename F, auto... Xs>
requires (is_unityped(Xs...))
constexpr auto scanr1(F f, List<Xs...> l) {
  return scanr<last(l)>(f, init(l));
}

void test_scanr1();

void test_scans();