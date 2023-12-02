#include "list_trans.h"


template<typename F>
constexpr auto map(List<> l, F _) {
    return l;
}

template<typename F, auto X, auto... Xs>
constexpr auto map(List<X, Xs...> _, F f) {
    return List<f(X)>().prepend(map(List<Xs...>(), f));
}

template<auto... Xs, auto... Ys>
constexpr auto zip(List<Xs...> a, List<Ys...> b) {
    if (sizeof... (Xs) == 0 || sizeof... (Ys) == 0) {
        return List<>();
    } else {
        return List<std::make_tuple(head(a), head(b))>().append(zip(tail(a), tail(b)));
    }
}

template<auto... Xs, auto... Ys, auto... Zs>
constexpr auto zip3(List<Xs...> a, List<Ys...> b, List<Zs...> c) {
    if (sizeof... (Xs) == 0 || sizeof... (Ys) == 0 || sizeof... (Zs) == 0) {
        return List<>();
    } else {
        return List<std::make_tuple(head(a), head(b), head(c))>().append(zip3(tail(a), tail(b), tail(c)));
    }
}

template<auto... Xs>
requires (BoolConvertible<decltype(Xs)> && ...)
constexpr bool list_and(List<Xs...> l) {
    return foldr([](auto X, auto Y){ return X && Y; }, true, l);
}


template<auto... Xs>
requires (BoolConvertible<decltype(Xs)> && ...)
constexpr bool list_or(List<Xs...> l) {
    return foldr([](auto X, auto Y){ return X || Y; }, true, l);
}


template<auto... Xs>
requires (BoolConvertible<decltype(Xs)> && ...)
constexpr bool list_any(List<Xs...> l) {
    return filter(l, [](auto X){ return X; }).length() != 0;
}
