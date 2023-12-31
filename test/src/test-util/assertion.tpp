#include <iostream>

template <typename T> bool is_equal(T actual, T expected) {
  bool condition = actual == expected;
  if (!condition)
    std::cout << "Expected:" << std::endl
              << actual << std::endl
              << "to be equal to:" << std::endl
              << expected << std::endl;
  return condition;
}
