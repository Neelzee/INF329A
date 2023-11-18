#include "drop.h"

template<std::size_t>
constexpr auto drop(List<> l) { return l; }

template<std::size_t n, auto X, auto... Xs>
//requires (n <= sizeof...(Xs))
constexpr auto drop(List<X, Xs...> l) 
{
    if constexpr (n == 0) {
        return l;
    }

    return drop<n - 1>(List<Xs...>());
}

