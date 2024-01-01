#include "content/me-card.hpp"
#include "test-util/assertion.hpp"
#include "test-util/test-platform.hpp"
#include <cassert>
#include <cstring>
#include <memory>
#include <string>

using QrCodeUtil::MeCard;
using std::make_unique;
using std::string;

namespace MeCardTest {
void minimal_data_test() {
  MeCard card;
  card.name = make_unique<MeCard::Name>("Payam", "Gerackoohi");
  card.phone = make_unique<string>("+98 905 738 0865");
  assert(is_equal<string>(card.str(), "MECARD:N:Gerackoohi,Payam;TEL:+98 905 738 0865;;"));
}

void full_data_test() {
  MeCard card;
  card.name = make_unique<MeCard::Name>("Payam", "Gerackoohi");
  card.phone = make_unique<string>("+98 905 738 0865");
  card.videoPhone = make_unique<string>("+1 123 456 7890");
  card.email = make_unique<string>("pgerackoohi@gmail.com");
  card.address = make_unique<string>(",,123 Main St.,Springfield,IL,12345,USA");
  card.birthDay = make_unique<string>("19700310");
  card.nickName = make_unique<string>("PayamGr");
  card.note = make_unique<string>("I am proficient in Tiger-Crane Style,\nand I am more than "
                                  "proficient in the exquisite art of the Samurai sword.");
  card.url = make_unique<string>("https://www.johndoe.com/");
  assert(is_equal<string>(card.str(),
                          "MECARD:N:Gerackoohi,Payam;TEL:+98 905 738 0865;TEL-AV:+1 123 456 "
                          "7890;EMAIL:pgerackoohi@gmail.com;ADR:,,123 Main "
                          "St.,Springfield,IL,12345,USA;BDAY:19700310;NICKNAME:PayamGr;NOTE:I am "
                          "proficient in Tiger-Crane Style,\nand I am more than proficient in the "
                          "exquisite art of the Samurai sword.;URL:https://www.johndoe.com/;;"));
}
} // namespace MeCardTest

int src_qrcode_content_me_card_test(int argC, char *argV[]) {
  using namespace MeCardTest;
  for (int i = 1; i < argC; i++) {
    const auto testName = argV[i];
    if (strcmp(testName, "minimal_data") == 0) {
      minimal_data_test();
      return 0;
    }
    if (strcmp(testName, "full_data") == 0) {
      full_data_test();
      return 0;
    }
  }
  testNotFound("src_qrcode_content_me_card_test", argC, argV);
  return 1;
}
