#include "splitAt.h"
#include <tuple>

template<std::size_t n, auto... Xs>
constexpr auto splitAt(List<Xs...> l) {
    return std::make_tuple(take<n>(l), drop<n>(l));
}

