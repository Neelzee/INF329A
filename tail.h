#include "list.h"

template<auto X, auto... Xs>
constexpr auto tail(List<X, Xs...>);
