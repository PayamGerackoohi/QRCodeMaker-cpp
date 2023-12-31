#include "content/sms.hpp"
#include "test-util/assertion.hpp"
#include "test-util/test-platform.hpp"
#include <cstring>
#include <iostream>
#include <string>

using QrCodeUtil::Sms;
using std::make_unique;
using std::string;

namespace SmsTest {
void phone_test() {
  Sms sms("+18005551212");
  assert(is_equal<string>(sms.str(), "sms:+18005551212"));
}

void phone_message_test() {
  Sms sms("+18005551212");
  sms.message = make_unique<string>("This is my text message.");
  assert(is_equal<string>(sms.str(), "sms:+18005551212:This%20is%20my%20text%20message."));
}
} // namespace SmsTest

int src_qrcode_content_sms_test(int argC, char *argV[]) {
  using namespace SmsTest;
  for (int i = 1; i < argC; i++) {
    const auto testName = argV[i];
    if (strcmp(testName, "phone") == 0) {
      phone_test();
      return 0;
    }
    if (strcmp(testName, "phone_message") == 0) {
      phone_message_test();
      return 0;
    }
  }
  testNotFound("src_qrcode_content_sms_test", argC, argV);
  return 1;
}
