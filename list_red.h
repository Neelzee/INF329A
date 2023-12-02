#include "list.h"
#include <cstdlib>
#include <tuple>

#pragma once

template<typename F>
constexpr auto foldl(F, auto acc, List<>);

template<typename F, auto... Xs>
constexpr auto foldl(F f, auto acc, List<Xs...> l);

template<typename F>
constexpr auto foldr(F, auto acc, List<>);

template<typename F, auto... Xs>
constexpr auto foldr(F f, auto acc, List<Xs...> l);

template<std::size_t _>
constexpr auto take(List<> l);

template<std::size_t n, auto X, auto... Xs>
constexpr auto take(List<X, Xs...> _);

template<std::size_t>
constexpr auto drop(List<> l);

template<std::size_t n, auto X, auto... Xs>
constexpr auto drop(List<X, Xs...> l);

template<std::size_t n, auto... Xs>
constexpr auto splitAt(List<Xs...> l);

template<typename F>
constexpr auto filter(List<> l, F f);

template<typename F, auto X, auto... Xs>
constexpr auto filter(List<X, Xs...> _, F f);

template<typename F, auto... Xs>
constexpr auto partition(List<Xs...> l, F f);
