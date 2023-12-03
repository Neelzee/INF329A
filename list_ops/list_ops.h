/**
 * List Operations
 */

#include "../list.h"
#include "../subl/subl.h"
#include <tuple>

#pragma once

template<typename F, auto X>
constexpr auto map(List<X>, F f) {
    return List<f(X)>();
}

template<typename F, auto... Xs>
requires (sizeof... (Xs) > 0)
constexpr auto map(List<Xs...> l, F f) {
    return List<f(head(l))>().append(map(tail(l), f));
}

void test_map();

template<typename F, auto X>
requires (InvocableWith<F, decltype(X)>)
constexpr auto filter(List<X>, F f) {
    if constexpr (f(X)) {
        return List<X>();
    } else {
        return List<>();
    }
}

template<typename F, auto X, auto... Xs>
requires (sizeof... (Xs) > 0 && InvocableWith<F, decltype(X)>)
constexpr auto filter(List<X, Xs...>, F f) {
    if constexpr (f(X)) {
        return List<X>().append(filter(List<Xs...>(), f));
    } else {
        return filter(List<Xs...>(), f);
    }
}

void test_filter();


template<std::size_t>
constexpr auto take(List<> l) {
    return l;
}

template<std::size_t N, auto X, auto... Xs>
requires (N <= (sizeof... (Xs) + 1))
constexpr auto take(List<X, Xs...> l) {
    if constexpr (N == 0) {
        return List<>();
    } else {
        return List<X>().append(take<N - 1>(tail(l)));
    }
}

void test_take();

template<auto X, auto... Xs>
constexpr auto head(List<X, Xs...>) {
    return X;
}

void test_head();

template<auto X>
constexpr auto last(List<X>) {
    return X;
}

template<auto... Xs>
requires (0 <= sizeof...(Xs))
constexpr auto last(List<Xs...> l) {
    return last(tail(l));
}

void test_last();

template<auto X, auto... Xs>
constexpr auto tail(List<X, Xs...>) {
    return List<Xs...>();
}

void test_tail();

template<auto... Xs>
requires (sizeof... (Xs) > 0)
constexpr auto init(List<Xs...> l) {
    return take<l.length() - 1>(l);
}

void test_init();

constexpr bool null(List<>) {
    return true;
}

template<auto... Xs>
constexpr bool null(List<Xs...>) {
    return false;
}

void test_null();

template<std::size_t n, auto... Xs>
requires (n <= sizeof...(Xs))
constexpr auto get(List<Xs...> l) {
    if constexpr (n == 0) {
        return head(l);
    } else {
        return get<n - 1>(tail(l));
    }
}

void get_test();

constexpr auto reverse(List<> l) {
    return l;
}

void reverse_test();

template<auto X, auto... Xs>
requires (sizeof... (Xs) + 1 > 0)
constexpr auto reverse(List<X, Xs...> l) {
    return cons_append<X>(reverse(tail(l)));
}

template<typename F, auto... Xs>
constexpr auto partition(List<Xs...> l, F f) {
    return
            std::make_tuple(
                    filter(l, f),
                    filter(l, [f](auto x){ return !f(x); })
            );
}

void test_partition();
