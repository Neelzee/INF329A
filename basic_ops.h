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


