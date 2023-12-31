#include "content/biz-card.hpp"
#include "test-util/assertion.hpp"
#include "test-util/test-platform.hpp"
#include <cstring>
#include <iostream>
#include <string>

using QrCodeUtil::BizCard;
using std::make_unique;
using std::string;

namespace BizCardTest {
void normal_use_case_test() {
  BizCard card;
  card.firstName = make_unique<string>("Sean");
  card.lastName = make_unique<string>("Owen");
  card.title = make_unique<string>("Software Engineer");
  card.company = make_unique<string>("Google");
  card.address = make_unique<string>("76 9th Avenue, New York, NY 10011");
  card.phone = make_unique<string>("+12125551212");
  card.email = make_unique<string>("srowen@google.com");
  assert(is_equal<string>(card.str(),
                          "BIZCARD:N:Sean;X:Owen;T:Software Engineer;C:Google;A:76 9th Avenue, New "
                          "York, NY 10011;B:+12125551212;E:srowen@google.com;;"));
}
} // namespace BizCardTest

int src_qrcode_content_biz_card_test(int argC, char *argV[]) {
  using namespace BizCardTest;
  for (int i = 1; i < argC; i++) {
    const auto testName = argV[i];
    if (strcmp(testName, "normal_use_case") == 0) {
      normal_use_case_test();
      return 0;
    }
  }
  testNotFound("src_qrcode_content_biz_card_test", argC, argV);
  return 1;
}
