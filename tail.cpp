#include "tail.h"

template<auto X, auto... Xs>
constexpr auto tail(List<X, Xs...>)
{
    return List<Xs...>();
}

