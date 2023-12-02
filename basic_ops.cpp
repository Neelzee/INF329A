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

template<auto X>
constexpr auto last(List<X>)
{
    return X;
}

template<auto... Xs>
requires (0 <= sizeof...(Xs))
constexpr auto last(List<Xs...> l)
{
    return last(tail(l));
}

template<auto... Xs>
constexpr auto init(List<Xs...> l)
{
    return take<sizeof... (Xs) - 1>(l);
}

constexpr auto reverse(List<> l) {
    return l;
}

template<auto X, auto... Xs>
constexpr auto reverse(List<X, Xs...> l) {
    return reverse(List<Xs...>()).prepend(List<X>());
}
