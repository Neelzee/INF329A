#include "subl.h"
#include "list_ops.h"
#include <iostream>

void test_drop() {
    constexpr auto l1 = List<1, 2, 3, 4>();
    constexpr auto l2 = drop<2>(l1);
}

void test_splitAt() {
    constexpr auto l1 = List<1, 2, 3, 4>();
    auto [l2, l3] = splitAt<2>(l1);
}

void test_sort() {
    constexpr auto l1 = List<4, 2, 5, 8, 10>();
    /*
    constexpr auto l2 = sort(l1);

    std::cout << to_string(l2) << std::endl;
     */
}
void test_sortBy();
void test_unique();
void test_group();
void test_groupBy();

void test_take_while() {
    constexpr auto l1 = List<1, 2, 3, 4>();
    constexpr auto l2 = take_while([](auto x){ return x <= 3; }, l1);
}

void test_drop_while() {
    constexpr auto l1 = List<1, 2, 3, 4>();
    constexpr auto l2 = drop_while([](auto x){ return x < 3; }, l1);

    std::cout << to_string(l2) << std::endl;
}

void test_span() {
    constexpr auto l1 = List<1, 2, 3, 4>();
    auto [l2, l3] = span([](auto x){ return x < 3; }, l1);

    std::cout << to_string(l2) << std::endl;
    std::cout << to_string(l3) << std::endl;
}

void test_list_break() {
    constexpr auto l1 = List<1, 2, 3, 4>();
    auto [l2, l3] = list_break([](auto x){ return x > 2; }, l1);

    std::cout << to_string(l2) << std::endl;
    std::cout << to_string(l3) << std::endl;
}