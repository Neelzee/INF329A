#include "div2.h"
#include "div.h"
#include <iostream>

void max_test() {
}

void min_test() {

}

void sum_test() {
  auto l1 = List<1, 2, 3, 4>();
  auto res = list_sum(l1);
}

void product_test() {
  auto l1 = List<1, 2, 3, 4>();
  auto res = list_product(l1);
}

void iterateN_test() {
  auto l1 = iterateN<4, 1>();

  std::cout << to_string(l1) << std::endl;
}