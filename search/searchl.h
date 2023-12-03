#include "../list.h"
#include "../list_ops/list_ops.h"

#pragma once


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

void test_elem();

template<typename F, auto... Xs>
requires (sizeof... (Xs) > 0)
constexpr auto find(List<Xs...> l, F f) {
    auto fl = filter(l, f);
    if constexpr (fl.length() == 0) {
        return;
    } else {
        return head(fl);
    }
}

void test_find();

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

void test_find_index();

template<auto>
constexpr auto lookup(List<>) {
    return;
}

template<auto X, std::pair... Xs>
constexpr auto lookup(List<Xs...> l) {
    if constexpr (head(l).first == X) {
        return head(l).second;
    } else {
        return lookup<X>(tail(l));
    }
}

void test_lookup();