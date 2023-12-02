/**
 * List Reductions
 */

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

template<std::size_t _>
constexpr auto take(List<> l) { return l; }

template<std::size_t n, auto X, auto... Xs>
constexpr auto take(List<X, Xs...> _) {
    if constexpr (n == 0) {
        return List<>();
    }

    return List<X>().prepend(take<n - 1>(List<Xs...>()));
}

template<std::size_t>
constexpr auto drop(List<> l) { return l; }

template<std::size_t n, auto X, auto... Xs>
requires (n <= sizeof...(Xs))
constexpr auto drop(List<X, Xs...> l)
{
    if constexpr (n == 0) {
        return l;
    }

    return drop<n - 1>(List<Xs...>());
}

template<std::size_t n, auto... Xs>
constexpr auto splitAt(List<Xs...> l) {
    return std::make_tuple(take<n>(l), drop<n>(l));
}

template<typename F>
constexpr auto filter(List<> l, F f) {
    return l;
}

template<typename F, auto X, auto... Xs>
constexpr auto filter(List<X, Xs...> _, F f) {
    if constexpr (f(X)) {
        return List<X>().prepend(filter(List<Xs...>(), f));
    } else {
        return filter(List<Xs...>(), f);
    }
}

template<typename F, auto... Xs>
constexpr auto partition(List<Xs...> l, F f) {
    return
        std::make_tuple(
                filter(l, f),
                filter(l, [f](auto x){ return !f(x); })
                );
}

/// ListC

template<typename F>
constexpr auto filter(ListC<> l, F f) {
    return l;
}

template<typename F, auto X, auto... Xs>
requires (AllComparable<decltype(Xs)...> && AllComparable<decltype(X)>)
constexpr auto filter(ListC<X, Xs...> _, F f) {
    if constexpr (f(X)) {
        return ListC<X>().prepend(filter(ListC<Xs...>(), f));
    } else {
        return filter(ListC<Xs...>(), f);
    }
}

template<typename F, auto... Xs>
requires AllComparable<decltype(Xs)...>
constexpr auto partition(ListC<Xs...> l, F f) {
    return
            std::make_tuple(
                    filter(l, f),
                    filter(l, [f](auto x){ return !f(x); })
            );
}

template<std::size_t N, auto X>
requires (N > 0)
constexpr auto replicate() {
    return replicateHelper<N, X>(List<>());
}

template<std::size_t N, auto X, auto... Xs>
constexpr auto replicateHelper(List<Xs...> l) {
    if constexpr (N == 0) {
        return l;
    } else {
        return replicateHelper<N - 1, X>(l.cons(X));
    }
}

template<std::size_t f, std::size_t t, auto... Xs>
requires (f >= 0 && f < t && t <= sizeof... (Xs))
constexpr auto range(List<Xs...> l) {
    return reverse(drop<t>(reverse(drop<f>(l))));
}