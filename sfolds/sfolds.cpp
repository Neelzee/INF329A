#include "sfolds.h"
#include <iostream>
#include <string>

void test_foldl() {
    auto l1 = List<1, 2, 3>();
    auto r = foldl([](auto x, auto y) { return x * 10 + y; }, 0, l1);

    std::cout << r << std::endl;
}

void test_foldr() {
    auto l1 = List<1, 2, 3>();
    auto l2 = List<1, 2, 3>();
    auto r = foldr([](auto x, auto y) { return x + y; }, 0, l1);

    std::cout << r << std::endl;
}

void test_concat() {
    auto l1 = List<1, 2, 3>();
    auto l2 = List<1, 2, 3>();
    auto l = List<1, 2, 3>();
    auto l3 = List<l1, l2>();
    auto l4 = concat(l3);
    auto l6 = concat(List<l1, l2, l>());

    auto lst = List<true, false>();
    auto lst2 = List<l1, l2>();

    auto lst3 = concat(List<lst, lst2>());

    std::cout << to_string(l6) << std::endl;
}

void test_list_and() {
    auto l1 = List<true, true, true>();
    auto r = list_and(l1);

    std::cout << r << std::endl;
    std::cout << list_and(List<false>()) << std::endl;
    std::cout << list_and(List<true>()) << std::endl;
}

void test_list_or() {
    auto l1 = List<true, true, true>();
    auto r = list_or(l1);

    std::cout << r << std::endl;
    std::cout << list_or(List<false>()) << std::endl;
    std::cout << list_or(List<true>()) << std::endl;
}

void test_list_any() {
    auto l1 = List<true, true, true>();
    auto r = list_and(l1);

    std::cout << r << std::endl;
    std::cout << list_and(List<false>()) << std::endl;
    std::cout << list_and(List<true>()) << std::endl;
}

void test_concat_map() {
    auto l1 = List<1, 2, 3>();
    auto l2 = List<1, 2, 3>();
    auto l = List<1, 2, 3>();
    auto l3 = List<l1, l2>();
    auto l4 = concat_map(l3, [](auto x){ return 2 * x; });
    auto l6 = concat_map(List<l1, l2, l>(), [](auto x){ return 2 * x; });

    std::cout << to_string(l6) << std::endl;
}

void test_sfolds() {
    test_foldl();
    test_foldr();
    test_concat();
    test_list_and();
    test_list_or();
    test_list_any();
    test_concat_map();
}