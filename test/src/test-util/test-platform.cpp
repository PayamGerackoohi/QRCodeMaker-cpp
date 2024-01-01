#include "test-platform.hpp"
#include <iostream>
#include <string>

using std::string;

void testNotFound(string label, int argC, char *argV[]) {
  std::cout << label << "::argC: " << argC << std::endl;
  for (int i = 0; i < argC; i++)
    std::cout << label << "::argV[" << i << "]: " << argV[i] << std::endl;
  std::cout << label << ":: test not found." << std::endl;
}
