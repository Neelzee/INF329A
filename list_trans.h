#include "list.h"
#include <tuple>

#pragma once

template<typename F>
constexpr auto map(List<> l, F _);

template<typename F, auto X, auto... Xs>
constexpr auto map(List<X, Xs...> _, F f);

template<auto... Xs, auto... Ys>
constexpr auto zip(List<Xs...> a, List<Ys...> b);

template<auto... Xs, auto... Ys, auto... Zs>
constexpr auto zip3(List<Xs...> a, List<Ys...> b, List<Zs...> c);
