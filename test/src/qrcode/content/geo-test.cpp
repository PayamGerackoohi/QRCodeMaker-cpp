#include "content/geo.hpp"
#include "test-util/assertion.hpp"
#include "test-util/test-platform.hpp"
#include <cstring>
#include <iostream>
#include <string>

using QrCodeUtil::Geo;
using std::make_unique;
using std::string;

void latitude_longitude_test() {
  Geo geo(4'071'872, -7'398'905);
  assert(is_equal<string>(geo.str(), "geo:40.71872,-73.98905"));
}

void latitude_longitude_altitude_test() {
  Geo geo(4'071'872, -7'398'905);
  geo.altitude = make_unique<int>(100);
  assert(is_equal<string>(geo.str(), "geo:40.71872,-73.98905,100"));
}

int src_qrcode_content_geo_test(int argC, char *argV[]) {
  for (int i = 1; i < argC; i++) {
    const auto testName = argV[i];
    if (strcmp(testName, "latitude_longitude") == 0) {
      latitude_longitude_test();
      return 0;
    }
    if (strcmp(testName, "latitude_longitude_altitude") == 0) {
      latitude_longitude_altitude_test();
      return 0;
    }
  }
  testNotFound("src_qrcode_content_geo_test", argC, argV);
  return 1;
}
