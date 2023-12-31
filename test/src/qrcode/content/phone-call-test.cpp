#include "content/phone-call.hpp"
#include "test-util/assertion.hpp"
#include "test-util/test-platform.hpp"
#include <cstring>
#include <iostream>
#include <string>

using QrCodeUtil::PhoneCall;
using std::make_unique;
using std::string;

void normal_use_case_test() {
  PhoneCall call("1234567890");
  assert(is_equal<string>(call.str(), "tel:1234567890"));
}

int src_qrcode_content_phone_call_test(int argC, char *argV[]) {
  for (int i = 1; i < argC; i++) {
    const auto testName = argV[i];
    if (strcmp(testName, "normal_use_case") == 0) {
      normal_use_case_test();
      return 0;
    }
  }
  testNotFound("src_qrcode_content_phone_call_test", argC, argV);
  return 1;
}
