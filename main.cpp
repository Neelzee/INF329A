#include <iostream>

template<auto... Xs>
struct List
{
    /// ================ ADD ===================
    template<auto... Ys>
    constexpr auto prepend(List<Ys...> L) const {
        return List<Xs..., Ys...>();
    }
    /// =========================================

};

/// =============== MAP =================
template<typename F>
constexpr auto map(List<> l, F _) {
    return l;
}

template<typename F, auto X, auto... Xs>
constexpr auto map(List<X, Xs...> _, F f) {
    return List<f(X)>().prepend(map(List<Xs...>(), f));
}

/// =====================================


/// =============== TAKE ================
template<std::size_t _>
constexpr auto take(List<> l) { return l; }

template<std::size_t n, auto X, auto... Xs>
constexpr auto take(List<X, Xs...> _) {
    if constexpr (n == 0) {
        return List<>();
    }

    return List<X>().prepend(take<n - 1>(List<Xs...>()));
}

/// =====================================

/// =============== DROP ================
template<std::size_t>
constexpr auto drop(List<> l) { return l; }

template<std::size_t n, auto X, auto... Xs>
constexpr auto drop(List<X, Xs...> l) requires (n <= sizeof...(Xs))
{
    if constexpr (n == 0) {
        return l;
    }

    return drop<n - 1>(List<Xs...>());
}

/// =====================================


/// =============== FILTER ===============

constexpr auto filter(List<> l, auto f) {
    return l;
}

template<auto X, auto... Xs>
constexpr auto filter(List<X, Xs...> _, auto f)
{
    if constexpr (f(X)) {
        return List<X>().prepend(filter(List<Xs...>(), f));
    }
    return filter(List<Xs...>(), f);
}

/// ======================================


/// ============== SPLIT AT ==============

template<std::size_t n, auto... Xs>
constexpr auto splitAt(List<Xs...> l) {

    return std::make_tuple(take<n>(l), drop<n>(l));
}

/// ======================================



/// ================= GET ================

template<std::size_t n, auto X, auto... Xs>
constexpr auto get(List<X, Xs...> l) {
requires (n <= sizeof...(Xs))
    if constexpr (n == 0) {
        return X;
    } else {
        return get<n - 1>(List<Xs...>());
    }
}

/// ======================================




int main() {

    std::cout << "Hello, World!" << std::endl;

    constexpr auto L1 = List<1, 2, 3, 4, 5>();
    constexpr auto L2 = splitAt<2>(L1);

    return 0;
}


