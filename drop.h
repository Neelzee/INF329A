#include "list.h"
#include <stdlib.h>

#pragma once


template<std::size_t>
constexpr auto drop(List<> l);

template<std::size_t n, auto X, auto... Xs>
constexpr auto drop(List<X, Xs...> l);
