#include "scans.h"
#include <iostream>

void test_scanl() {
    auto l1 = List<1, 2, 3>();
    auto r = scanl<0>([](auto acc, auto x){ return acc + x; }, l1);

    std::cout << "=== Test scanl ===";
    std::cout << to_string(r) << std::endl;
    std::cout << "==================";
}

void test_scanl1() {
    auto l1 = List<1, 2, 3>();
    auto r = scanl1([](auto acc, auto x){ return acc + x; }, l1);

    std::cout << "=== Test scanl1 ===";
    std::cout << to_string(r) << std::endl;
    std::cout << "===================";
}

void test_scanr() {
    auto l1 = List<1, 2, 3>();
    auto r = scanr<0>([](auto acc, auto x){ return acc + x; }, l1);

    std::cout << "=== Test scanr ===";
    std::cout << to_string(r) << std::endl;
    std::cout << "===================";
}

void test_scanr1() {
    auto l1 = List<1, 2, 3>();
    auto r = scanr1([](auto acc, auto x){ return acc + x; }, l1);

    std::cout << "=== Test scanr1 ===";
    std::cout << to_string(r) << std::endl;
    std::cout << "====================";
}

void test_scans() {
    test_scanl();
    test_scanl1();
    test_scanr();
    test_scanr1();
}