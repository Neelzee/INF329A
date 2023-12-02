#include "list.h"
#include <cstdlib>
#include "list_red.h"

#pragma once

constexpr auto sort(ListC<> l);

template<auto... Xs>
requires AllComparable<decltype(Xs)...>
constexpr auto sort(ListC<Xs...> l);

template<typename F>
constexpr auto sortBy(ListC<> l, F);

template<typename F, auto... Xs>
requires AllComparable<decltype(Xs)...>
constexpr auto sortBy(ListC<Xs...> l, F f);

constexpr auto unique(ListC<> l);

template<auto... Xs>
requires AllComparable<decltype(Xs)...>
constexpr auto unique(ListC<Xs...> l);

constexpr auto group(ListC<> l);

template<auto... Xs>
requires AllComparable<decltype(Xs)...>
constexpr auto group(ListC<Xs...> l);

constexpr auto groupBy(ListC<> l);

template<auto... Xs>
requires AllComparable<decltype(Xs)...>
constexpr auto groupBy(ListC<Xs...> l);