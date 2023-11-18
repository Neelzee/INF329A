#include "take.h"


template<std::size_t _>
constexpr auto take(List<> l) { return l; }

template<std::size_t n, auto X, auto... Xs>
constexpr auto take(List<X, Xs...> _) {
    if constexpr (n == 0) {
        return List<>();
    }

    return List<X>().prepend(take<n - 1>(List<Xs...>()));
}

