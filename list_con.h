#include "list.h"
#include <vector>

#pragma once

template <typename T, std::size_t N>
requires (N > 0)
constexpr auto arrayToList(const T (&array)[N]);

template <auto... Xs>
constexpr auto listToArray(List<Xs...>);
