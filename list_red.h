#include "list.h"

#pragma once

template<typename F>
constexpr auto foldl(F, auto acc, List<>);

template<typename F, auto... Xs>
constexpr auto foldl(F f, auto acc, List<Xs...> l);

template<typename F>
constexpr auto foldr(F, auto acc, List<>);

template<typename F, auto... Xs>
constexpr auto foldr(F f, auto acc, List<Xs...> l);