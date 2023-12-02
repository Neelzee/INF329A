#include "list.h"
#include <cstdlib>

#pragma once

constexpr auto nil();

template<auto X, auto... Xs>
constexpr auto cons(List<Xs...>);

template<std::size_t n, auto X, auto... Xs>
requires (n <= sizeof...(Xs))
constexpr auto get(List<X, Xs...>);

template<auto X, auto... Xs>
constexpr auto head(List<X, Xs...> _);

template<auto X, auto... Xs>
constexpr auto tail(List<X, Xs...>);

template<auto X>
constexpr auto last(List<X>);

template<auto... Xs>
requires (0 <= sizeof...(Xs))
constexpr auto last(List<Xs...> l);

template<auto... Xs>
constexpr auto init(List<Xs...> l);

constexpr auto reverse(List<> l);

template<auto X, auto... Xs>
constexpr auto reverse(List<X, Xs...> l);