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
    constexpr auto l2 = sort(List<1>());
    //constexpr auto l3 = sort(List<1, 2>());

    //std::cout << to_string(l2) << std::endl;
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

void test_partition() {
    auto l1 = List<1, 2, 3, 4, 5, 6, 7, 8, 9, 10>();
    auto [l2, l3] = partition(l1, [](auto x) { return x % 2 == 0; });

    auto l4 = List<8, 10, 4, 2, 5>();

    auto [l5, l6] = partition(l4, [](auto X){ return X > 4; });

    std::cout << "=== Test Partition ===" << std::endl;

    std::cout << "Starting list: " << to_string(l1) << std::endl;
    std::cout << "Should be evens" << to_string(l2) << std::endl;
    std::cout << "Should be odds" << to_string(l3) << std::endl;

    std::cout << "======================" << std::endl;
}

void test_init() {
    auto l1 = List<1, 2, 3, 4>();
    auto l2 = init(l1);

    std::cout << "====== Test Init =====" << std::endl;

    std::cout << "Starting list: " << to_string(l1) << std::endl;
    std::cout << "Init: " << to_string(l2) << std::endl;

    std::cout << "======================" << std::endl;
}


void test_take() {
    auto l1 = List<1, 2, 3, 4, 5>();
    auto l2 = take<0>(l1);
    auto l3 = take<1>(l1);
    auto l4 = take<4>(l1);
    auto l5 = take<5>(l1);
    //auto l6 = take<6>(l1);

    std::cout << "====== Test Take =====" << std::endl;

    std::cout << "Starting list: " << to_string(l1) << std::endl;
    std::cout << "Take 0: " << to_string(l2) << std::endl;
    std::cout << "Take 1: " << to_string(l3) << std::endl;
    std::cout << "Take 4: " << to_string(l4) << std::endl;
    std::cout << "Take 5: " << to_string(l5) << std::endl;

    std::cout << "======================" << std::endl;
}