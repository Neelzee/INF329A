#include "zip.h"

void test_zip() {
    auto l1 = List<1, 3, 5>();
    auto l2 = List<2, 3, 6>();
    auto l3 = zip(l1, l2);
}

void test_unzip() {
    auto l1 = List<1, 3, 5>();
    auto l2 = List<2, 4, 6>();
    auto l3 = zip(l1, l2);
    auto [l4, l5] = unzip(l3);

    std::cout << to_string(l4) << std::endl;
    std::cout << to_string(l5) << std::endl;
}

void test_zip3() {
    auto l1 = List<1, 3, 5>();
    auto l2 = List<2, 3, 6>();
    auto l3 = List<0, 0, 0>();
    //auto l4 = zip3(l1, l2, l3);

}


void test_zip_main() {
    test_zip();
    test_unzip();
}