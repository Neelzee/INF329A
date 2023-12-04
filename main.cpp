#include <iostream>
#include "list_ops.h"
#include "zipping/zip.h"
#include "sfolds/sfolds.h"
#include "scans/scans.h"
#include "subl/subl.h"

void test_list() {
    auto l1 = List<1, 2, 3, 4>();
    auto l2 = l1.prepend(List<5, 6>());
    auto l3 = l1.append(List<0>());
    auto l4 = cons<0>(l1);
    auto l5 = cons_append<5>(l1);

    std::cout << "====== Test List ======";

    std::cout << "Starting list: " << to_string(l1) << std::endl;
    std::cout << "Prepend <5, 6>: " << to_string(l2) << std::endl;
    std::cout << "Append <0>: " << to_string(l3) << std::endl;
    std::cout << "Cons 0: " << to_string(l4) << std::endl;
    std::cout << "Cons append 5: " << to_string(l5) << std::endl;

    std::cout << "=======================";
}


int main() {

     std::cout << "##### TEST LIST METHODS #####" << std::endl;
    test_list();
    std::cout << "##############################" << std::endl;

    std::cout << "####### TEST LIST OPS ########" << std::endl;
    test_list_ops();
    std::cout << "##############################" << std::endl;

    test_scans();

    test_zip_main();

    test_sfolds();

    return 0;
}




