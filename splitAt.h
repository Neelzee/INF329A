#include "list.h"
#include <stdlib.h>

#pragma once

template<std::size_t n, auto... Xs>
constexpr auto splitAt(List<Xs...> l);
