#include "filter.h"

template<typename F>
constexpr auto filter(List<> l, F f) {
    return l;
}

template<typename F, auto X, auto... Xs>
constexpr auto filter(List<X, Xs...> _, F f) {
    if constexpr (f(X)) {
        return List<X>().prepend(filter(List<Xs...>(), f));
    }
}
