#include "list.h"

#pragma once

template<auto Y>
constexpr bool elem(List<>);

template<auto Y, auto X, auto... Xs>
constexpr bool elem(List<X, Xs...> _);

