#include "basic_ops.h"



constexpr auto nil() {
    return List<>();
}

template<auto X, auto... Xs>
constexpr auto cons(List<Xs...>) {
    return List<X, Xs...>();
}

template<std::size_t n, auto X, auto... Xs>
constexpr auto get(List<X, Xs...> l)
requires (n <= sizeof...(Xs))
{
    if constexpr (n == 0) {
        return X;
    } else {
        return get<n - 1>(List<Xs...>());
    }
}

template<auto X, auto... Xs>
constexpr auto head(List<X, Xs...>) {
    return X;
}

template<auto X, auto... Xs>
constexpr auto tail(List<X, Xs...>)
{
    return List<Xs...>();
}
