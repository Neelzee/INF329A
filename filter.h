#include "list.h"

#pragma once

template<typename F>
constexpr auto filter(List<> l, F f);

template<typename F, auto X, auto... Xs>
constexpr auto filter(List<X, Xs...> _, F f);
