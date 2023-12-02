#include "list.h"
#include <cstdlib>

#pragma once

template<auto Y>
constexpr bool elem(List<>);

template<auto Y, auto X, auto... Xs>
constexpr bool elem(List<X, Xs...> _);

template<typename>
constexpr auto find(List<>);

template<typename F, auto... Xs>
constexpr auto find(List<Xs...> l, F f);

template<auto>
constexpr std::size_t findIndex(List<>);

template<auto Y, auto X, auto... Xs>
constexpr std::size_t findIndex(List<X, Xs...>);