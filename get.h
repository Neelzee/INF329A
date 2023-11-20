#include "list.h"
#include <stdlib.h>

template<std::size_t n, auto X, auto... Xs>
concept SizeLessEqual = (n <= sizeof...(Xs));

template<std::size_t n, auto X, auto... Xs>
require SizeLessEqual<n, ...Xs>
constexpr auto get(List<X, Xs...> l) {
    if constexpr (n == 0) {
        return X;
    } else {
        return get<n - 1>(List<Xs...>());
    }
}

