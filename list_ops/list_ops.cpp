#include "list_ops.h"
#include <iostream>

void test_map() {
    auto l1 = List<1, 2, 3>();
    auto l2 = map(l1, [](auto x){ return x * 2; });
    auto l3 = map(l1, [](auto x){ return x * 3; });

    auto l4 = List<71, 68, 75, 75, 78>();
    auto l5 = map(l4, [](auto x){ return x / 2; });

    auto l6 = map(List<2>(), [](auto x){ return x / 2; });
    //auto l7 = map(List<>(), [](auto x){ return x / 2; });

    std::cout << "====== Test Map ======" << std::endl;

    std::cout << "Starting list: " << to_string(l1) << std::endl;
    std::cout << "Doubled: " << to_string(l2) << std::endl;
    std::cout << "Tripled: " << to_string(l3) << std::endl;
    std::cout << "Starting list 2: " << to_string(l4) << std::endl;
    std::cout << "Divided: " << to_string(l5) << std::endl;
    std::cout << "Divided, Singleton: " << to_string(l6) << std::endl;

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

void test_filter() {
    auto l1 = List<1, 2, 3, 4, 5, 6>();
    auto l2 = filter(l1, [](auto x){ return x % 2 == 0; });
    auto l3 = filter(l1, [](auto x){ return x % 2 != 0; });
    auto l4 = filter(l1, [](auto x){ return x > 6; });
    auto l5 = filter(l1, [](auto x){ return x <= 6; });
    //auto l7 = filter(List<>(), [](auto x){ return x <= 6; });

    std::cout << "==== Test Filter =====" << std::endl;

    std::cout << "Starting list: " << to_string(l1) << std::endl;
    std::cout << "Evens: " << to_string(l2) << std::endl;
    std::cout << "Odds: " << to_string(l3) << std::endl;
    std::cout << "Greater than 6: " << to_string(l4) << std::endl;
    std::cout << "Less than or equal to 6: " << to_string(l5) << std::endl;

    std::cout << "======================" << std::endl;
}

void test_head() {
    auto l1 = List<1, 2, 3>();
    auto one = head(l1);
    auto l2 = List<5, 2, 3>();
    auto five = head(l2);

    std::cout << "====== Test Head =====" << std::endl;

    std::cout << "Starting list: " << to_string(l1) << std::endl;
    std::cout << "Head: " << one << std::endl;
    std::cout << "Starting list two: " << to_string(l2) << std::endl;
    std::cout << "Head: " << five << std::endl;

    std::cout << "======================" << std::endl;
}

void test_last() {
    auto l1 = List<1, 2, 3>();
    auto three = head(l1);
    auto l2 = List<5, 2, 5>();
    auto five = head(l2);
    std::cout << "====== Test Last =====" << std::endl;

    std::cout << "Starting list: " << to_string(l1) << std::endl;
    std::cout << "Head: " << three << std::endl;
    std::cout << "Starting list two: " << to_string(l2) << std::endl;
    std::cout << "Head: " << five << std::endl;

    std::cout << "======================" << std::endl;
}

void test_tail() {
    auto l1 = List<1, 2, 3>();
    auto l2 = tail(l1);
    auto l3 = List<5, 1, 2, 3, 4>();
    auto l4 = tail(l3);

    std::cout << "====== Test Tail =====" << std::endl;

    std::cout << "Starting list: " << to_string(l1) << std::endl;
    std::cout << "Tail: " << to_string(l2) << std::endl;
    std::cout << "Starting list two: " << to_string(l3) << std::endl;
    std::cout << "Tail: " << to_string(l4) << std::endl;

    std::cout << "======================" << std::endl;
}

void get_test() {
    auto l1 = List<1, 2, 3, 4>();
    auto one = get<0>(l1);
    auto two = get<1>(l1);
    auto three = get<2>(l1);
    auto four = get<3>(l1);

    std::cout << "====== Get Test ======" << std::endl;

    std::cout << one << std::endl;
    std::cout << two << std::endl;
    std::cout << three << std::endl;
    std::cout << four << std::endl;

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

void reverse_test() {
    auto l1 = List<1, 2, 3, 4>();
    auto l2 = reverse(l1);

}

void test_null() {
    static_assert(null(List<>()), "Should be true");
    static_assert(!null(List<1>()), "Should be false");
}

void test_partition() {
    auto l1 = List<1, 2, 3, 4, 5, 6, 7, 8, 9, 10>();
    auto [l2, l3] = partition(l1, [](auto x) { return x % 2 == 0; });

    std::cout << "=== Test Partition ===" << std::endl;

    std::cout << "Starting list: " << to_string(l1) << std::endl;
    std::cout << "Should be evens" << to_string(l2) << std::endl;
    std::cout << "Should be odds" << to_string(l3) << std::endl;

    std::cout << "======================" << std::endl;
}