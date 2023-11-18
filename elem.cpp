#include "elem.h"


template<auto Y>
constexpr bool elem(List<>) {
    return false;
}

template<auto Y, auto X, auto... Xs>
constexpr bool elem(List<X, Xs...>) {
    if constexpr (Y == X) {
        return true;
    } else {
        return elem<Y>(List<Xs...>());
    }
}

