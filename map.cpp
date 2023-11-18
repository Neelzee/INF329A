#include "map.h"

template<typename F>
constexpr auto map(List<> l, F _) {
    return l;
}

template<typename F, auto X, auto... Xs>
constexpr auto map(List<X, Xs...> _, F f) {
    return List<f(X)>().prepend(map(List<Xs...>(), f));
}
