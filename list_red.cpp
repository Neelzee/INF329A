#include "list_red.h"

template<typename F>
constexpr auto foldl(F, auto acc, List<>) {
    return acc;
}

template<typename F, auto... Xs>
constexpr auto foldl(F f, auto acc, List<Xs...> l) {
    auto x = f(head(l));
    acc += x;
    return foldl(f, acc, tail(l));
}

template<typename F>
constexpr auto foldr(F, auto acc, List<>) {
    return acc;
}

template<typename F, auto... Xs>
constexpr auto foldr(F f, auto acc, List<Xs...> l) {
    acc = f(drop(l, sizeof... (Xs) - 1), acc);
    return foldr(f, acc, take(l, sizeof... (Xs) - 1));
}