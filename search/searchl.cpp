#include "searchl.h"
#include <tuple>

void test_elem() {
    auto l1 = List<1, 2, 3, 4>();

    static_assert(elem<1>(l1), "One should be in list");
    static_assert(!elem<5>(l1), "Five should not be in list");
}

void test_find() {
    auto l1 = List<1, 2, 3, 4>();
    constexpr auto r = find(l1, [](auto x){ return x % 2 == 0; });

    static_assert(r == 2, "should be 2");
}

void test_find_index() {
    constexpr auto l1 = List<1, 2, 3, 4>();
    constexpr auto i = findIndex<1>(l1);

    static_assert(1 == get<i>(l1), "Should be the first element");
}

void test_lookup() {
    constexpr auto l1 = List<std::pair(1, 2), std::pair(2, 2), std::pair(3, 4)>();
    constexpr auto r = lookup<1>(l1);

    static_assert(r == 2, "Should be two");
}