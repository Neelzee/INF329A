#include "list_search.h"

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

template<typename>
constexpr auto find(List<>) {
    return;
}

template<typename F, auto... Xs>
constexpr auto find(List<Xs...> l, F f) {
    auto fl = filter(l, f);
    if constexpr (fl.length() == 0) {
        return;
    } else {
        return head(fl);
    }
}

template<auto>
constexpr std::size_t findIndex(List<>) {
    return -1;
}

template<auto Y, auto X, auto... Xs>
constexpr std::size_t findIndex(List<X, Xs...>) {
    if constexpr (X == Y) {
        return 0;
    } else {
        return 1 + findIndex<Y>(List<Xs...>());
    }
}