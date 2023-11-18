#include "list.h"

#pragma once

constexpr auto filter(List<> l, auto f);

template<auto X, auto... Xs>
constexpr auto filter(List<X, Xs...> _, auto f)
{
    if constexpr (f(X)) {
        return List<X>().prepend(filter(List<Xs...>(), f));
    }
    return filter(List<Xs...>(), f);
}

