#include "list.h"
#include <stdlib.h>

#pragma once

template<std::size_t _>
constexpr auto take(List<> l);

template<std::size_t n, auto X, auto... Xs>
constexpr auto take(List<X, Xs...> _);
