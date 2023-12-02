#include "list_sort.h"

constexpr auto sort(ListC<> l) {
    return l;
}

template<auto... Xs>
requires AllComparable<decltype(Xs)...>
constexpr auto sort(ListC<Xs...> l) {
    if constexpr (l.length() <= 1) {
        return l;
    } else {
        auto pivot = head(l);

        auto [less, greater] = partition(l, [pivot](auto X){ return X < pivot; });

        auto sorted_less = sort(less);
        auto sorted_greater = sort(greater);

        return sorted_less.append(sorted_greater);
    }
}

template<typename F>
constexpr auto sortBy(ListC<> l, F) {
    return l;
}

template<typename F, auto... Xs>
requires AllComparable<decltype(Xs)...>
constexpr auto sortBy(ListC<Xs...> l, F f) {
    if constexpr (l.length() <= 1) {
        return l;
    } else {
        auto [less, greater] = partition(l, f);

        return sortBy(less, f).append(sortBy(greater, f));
    }
}

constexpr auto unique(ListC<> l) {
    return l;
}

template<auto... Xs>
requires AllComparable<decltype(Xs)...>
constexpr auto unique(ListC<Xs...> l) {
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


constexpr auto group(ListC<> l) {
    return l;
}

template<auto... Xs>
requires AllComparable<decltype(Xs)...>
constexpr auto group(ListC<Xs...> l) {
    auto ul = unique(l);
    return groupHelper(ul, l);
}

template<auto... Xs, auto... Ys>
requires ((AllComparable<decltype(Xs)...>) && (AllComparable<decltype(Ys)...>) && 1 == sizeof... (Xs) )
constexpr auto groupHelper(ListC<Xs...> ul, ListC<Ys...> l) {
    auto X = head(ul);
    return std::make_tuple(filter(l, [X](auto y){ return y == X; }));
}

template<auto... Xs, auto... Ys>
requires ((AllComparable<decltype(Xs)...>) && (AllComparable<decltype(Ys)...>))
constexpr auto groupHelper(ListC<Xs...> ul, ListC<Ys...> l) {
    auto X = head(ul);
    auto currentGroup = filter(l, [X](auto y){ return y == X; });
    auto restGroups = groupHelper(tail(ul), l);

    // Combine currentGroup with restGroups in some manner
    return std::tuple_cat(restGroups, currentGroup);
}

template<typename F>
constexpr auto groupBy(ListC<> l, F) {
    return l;
}

template<auto... Xs, typename F>
requires AllComparable<decltype(Xs)...>
constexpr auto groupBy(ListC<Xs...> l, F f) {
    auto ul = filter(l, f);
    return groupHelper(ul, l);
}