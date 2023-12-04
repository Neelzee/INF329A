#include "../list.h"
#include "../list_ops/list_ops.h"
#include <tuple>

#pragma once


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

template<auto... Xs>
requires (sizeof... (Xs) > 0)
constexpr auto init(List<Xs...> l) {
    return take<l.length() - 1>(l);
}

void test_init();


template<std::size_t>
constexpr auto drop(List<> l) { return l; }

template<std::size_t n, auto X, auto... Xs>
requires (n <= sizeof...(Xs))
constexpr auto drop(List<X, Xs...> l) {
    if constexpr (n == 0) {
        return l;
    } else {
        return drop<n - 1>(List<Xs...>());
    }
}

template<std::size_t n, auto... Xs>
constexpr auto splitAt(List<Xs...> l) {
    return std::make_tuple(take<n>(l), drop<n>(l));
}

template<typename F, auto... Xs>
requires (InvocableWith<F, decltype(Xs)> && ...)
constexpr auto partition(List<Xs...> l, F f) {
    return
            std::make_tuple(
                    filter(l, f),
                    filter(l, [f](auto x){ return !f(x); })
            );
}

template<auto X>
constexpr auto sort(List<X> l) {
    return l;
}

template<auto... Xs>
requires (AllComparable<decltype(Xs)...> && (sizeof... (Xs) > 0))
constexpr auto sort(List<Xs...> l) {
    auto pivot = head(l);

    auto fn = [pivot](auto X){ return X > pivot; };

    auto res = partition<decltype(fn)>(l, fn);

    auto sorted_less = sort(res.first);
    auto sorted_greater = sort(res.second);

    return sorted_less.append(sorted_greater);
}

template<typename F>
constexpr auto sortBy(List<> l, F) {
    return l;
}

template<typename F, auto... Xs>
requires AllComparable<decltype(Xs)...>
constexpr auto sortBy(List<Xs...> l, F f) {
    if constexpr (l.length() <= 1) {
        return l;
    } else {
        auto [less, greater] = partition(l, f);

        return sortBy(less, f).append(sortBy(greater, f));
    }
}

constexpr auto unique(List<> l) {
    return l;
}

template<auto... Xs>
requires AllComparable<decltype(Xs)...>
constexpr auto unique(List<Xs...> l) {
    return uniqueHelper(List<>(), l);
}

template<auto... Xs>
requires AllComparable<decltype(Xs)...>
constexpr auto uniqueHelper(List<Xs...> l, List<>) {
    return l;
}

template<auto... Xs, auto... Ys>
requires AllComparable<decltype(Xs)...>
constexpr auto uniqueHelper(List<Xs...> seen, List<Ys...> remainder) {
    if constexpr (elem(seen, head(remainder))) {
        return uniqueHelper(seen, tail(remainder));
    } else {
        return uniqueHelper(seen.cons(head(remainder)), tail(remainder));
    }
}


constexpr auto group(List<> l) {
    return l;
}

template<auto... Xs>
requires AllComparable<decltype(Xs)...>
constexpr auto group(List<Xs...> l) {
    auto ul = unique(l);
    return groupHelper(ul, l);
}

template<auto... Xs, auto... Ys>
requires ((AllComparable<decltype(Xs)...>) && (AllComparable<decltype(Ys)...>) && 1 == sizeof... (Xs) )
constexpr auto groupHelper(List<Xs...> ul, List<Ys...> l) {
    auto X = head(ul);
    return std::make_tuple(filter(l, [X](auto y){ return y == X; }));
}

template<auto... Xs, auto... Ys>
requires ((AllComparable<decltype(Xs)...>) && (AllComparable<decltype(Ys)...>))
constexpr auto groupHelper(List<Xs...> ul, List<Ys...> l) {
    auto X = head(ul);
    auto currentGroup = filter(l, [X](auto y){ return y == X; });
    auto restGroups = groupHelper(tail(ul), l);

    // Combine currentGroup with restGroups in some manner
    return std::tuple_cat(restGroups, currentGroup);
}

template<typename F>
constexpr auto groupBy(List<> l, F) {
    return l;
}

template<auto... Xs, typename F>
requires AllComparable<decltype(Xs)...>
constexpr auto groupBy(List<Xs...> l, F f) {
    auto ul = filter(l, f);
    return groupHelper(ul, l);
}

template<typename F>
constexpr auto take_while(F f, List<> l) {
    return l;
}

template<auto... Xs, typename F>
constexpr auto take_while(F f, List<Xs...> l) {
    if constexpr (f(head(l))) {
        return List<head(l)>().append(take_while(f, tail(l)));
    } else {
        return List<>();
    }
}

template<typename F>
constexpr auto drop_while(F, List<> l) {
    return l;
}

template<auto... Xs, typename F>
requires (sizeof... (Xs) > 0)
constexpr auto drop_while(F f, List<Xs...> l) {
    if constexpr (f(head(l))) {
        return drop_while(f, tail(l));
    } else {
        return l;
    }
}

template<auto... Xs, typename F>
constexpr auto span(F f, List<Xs...> l) {
    return std::make_pair(take_while(f, l), drop_while(f, l));
}

template<auto... Xs, typename F>
constexpr auto list_break(F f, List<Xs...> l) {
    return std::make_pair(take_while([f](auto x){ return !f(x); }, l), drop_while([f](auto x){ return !f(x); }, l));
}

void test_drop();
void test_splitAt();
void test_sort();
void test_sortBy();
void test_unique();
void test_group();
void test_groupBy();
void test_take_while();
void test_drop_while();
void test_span();
void test_list_break();