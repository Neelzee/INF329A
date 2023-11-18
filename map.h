#include "list.h"

#pragma once

template<typename F>
constexpr auto map(List<> l, F _);

template<typename F, auto X, auto... Xs>
constexpr auto map(List<X, Xs...> _, F f);

