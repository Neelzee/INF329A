#include "list.h"

// List.tpp
template<auto... Xs>
template<auto... Ys>
constexpr auto List<Xs...>::prepend(List<Ys...> l) const {
    return List<Ys..., Xs...>();
}

template<auto... Xs>
template<auto... Ys>
constexpr auto List<Xs...>::append(List<Ys...> l) const {
    return l.prepend(List<Xs...>()); // Code reuse
}

template<auto... Xs>
constexpr auto List<Xs...>::cons(auto X) const {
    return List<X, Xs...>();
}

template<auto... Xs>
constexpr auto List<Xs...>::lenght() const {
    return sizeof... (Xs);
}

