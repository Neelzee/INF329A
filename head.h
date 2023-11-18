#include "list.h"

template<auto X, auto... Xs>
constexpr auto head(List<X, Xs...> _);

