#include "content/v-card.hpp"
#include "test-util/assertion.hpp"
#include "test-util/test-platform.hpp"
#include <cassert>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>

using QrCodeUtil::VCard;
using std::make_unique;
using std::string;

namespace VCardTest {
void minimal_data_test() {
  VCard card;
  card.name = make_unique<VCard::Name>("", "Payam", "", "Gerackoohi", "");
  card.phone = make_unique<VCard::Phone>("Mobile", "+98 905 738 0865");
  card.birthDay = make_unique<string>("19700310");
  assert(is_equal<string>(card.str(), "BEGIN:VCARD\n"
                                      "VERSION:4.0\n"
                                      "N:Gerackoohi;Payam;;;\n"
                                      "TEL;TYPE=Mobile:+98 905 738 0865\n"
                                      "BDAY:19700310\n"
                                      "END:VCARD"));
}

void full_data_test() {
  VCard card;
  card.name = make_unique<VCard::Name>("", "Payam", "", "Gerackoohi", "");
  card.phone = make_unique<VCard::Phone>("Mobile", "+98 905 738 0865");
  card.address = make_unique<VCard::Address>("home", ";;123 Main St.;Springfield;IL;12345;USA");
  card.agent = make_unique<string>("http://mi6.gov.uk/007");
  card.anniversary = make_unique<string>("19901021");
  card.birthDay = make_unique<string>("19700310");
  card.calAdrUri = make_unique<string>("http://example.com/calendar/jdoe");
  card.calUri = make_unique<string>("http://example.com/calendar/jdoe");
  card.categories = {"swimmer", "biker"};
  card.clazz = make_unique<string>("public");
  card.clientPidMap = make_unique<string>("1;urn:uuid:3df403f4-5924-4bb7-b077-3c711d9eb34b");
  card.email = make_unique<string>("pgerackoohi@gmail.com");
  card.fbUrl = make_unique<string>("http://example.com/fb/jdoe");
  card.formattedName = make_unique<string>("Dr. John Doe");
  card.gender = make_unique<string>("M");
  card.geo = make_unique<string>("39.95,-75.1667");
  card.impp = make_unique<string>("aim:johndoe@aol.com");
  card.key = make_unique<string>("MEDIATYPE=application/pgp-keys:http://example.com/key.pgp");
  card.kind = make_unique<string>("individual");
  card.label = make_unique<string>("TYPE=HOME:123 Main St.\\nSpringfield, IL 12345\\nUSA");
  card.lang = make_unique<string>("fr-CA");
  card.logo = make_unique<string>("MEDIATYPE=image/png:http://example.com/logo.png");
  card.mailer = make_unique<string>("Thunderbird");
  card.member = make_unique<string>("urn:uuid:03a0e51f-d1aa-4385-8a53-e29025acd8af");
  card.nicknames = {"PayamGr"};
  card.note = make_unique<string>("I am proficient in Tiger-Crane Style,\\nand I am more than "
                                  "proficient in the exquisite art of the Samurai sword.");
  card.org = make_unique<string>("Google;GMail Team;Spam Detection Squad");
  card.photo = make_unique<string>("MEDIATYPE=image/jpeg:http://example.com/photo.jpg");
  card.prodId = make_unique<string>("-//ONLINE DIRECTORY//NONSGML Version 1//EN");
  card.profile = make_unique<string>("VCARD");
  card.related = make_unique<string>("TYPE=friend:urn:uuid:03a0e51f-d1aa-4385-8a53-e29025acd8af");
  card.rev = make_unique<string>("20121201T134211Z");
  card.role = make_unique<string>("Executive");
  card.sortString = make_unique<string>("Doe");
  card.sound = make_unique<string>("MEDIATYPE=audio/ogg:http://example.com/sound.ogg");
  card.source = make_unique<string>("http://johndoe.com/vcard.vcf");
  card.title = make_unique<string>("V.P. Research and Development");
  card.timeZone = make_unique<string>("America/New_York");
  card.uid = make_unique<string>("urn:uuid:da418720-3754-4631-a169-db89a02b831b");
  card.url = make_unique<string>("http://www.johndoe.com");
  card.xml = make_unique<string>("XML:<b>Not an xCard XML element</b>");
  assert(is_equal<string>(card.str(),
                          "BEGIN:VCARD\n"
                          "VERSION:4.0\n"
                          "N:Gerackoohi;Payam;;;\n"
                          "TEL;TYPE=Mobile:+98 905 738 0865\n"
                          "ADR;TYPE=home:;;123 Main St.;Springfield;IL;12345;USA\n"
                          "AGENT:http://mi6.gov.uk/007\n"
                          "ANNIVERSARY:19901021\n"
                          "BDAY:19700310\n"
                          "CALADRURI:http://example.com/calendar/jdoe\n"
                          "CALURI:http://example.com/calendar/jdoe\n"
                          "CATEGORIES:swimmer,bikerCLASS:public\n"
                          "CLIENTPIDMAP:1;urn:uuid:3df403f4-5924-4bb7-b077-3c711d9eb34b\n"
                          "EMAIL:pgerackoohi@gmail.com\n"
                          "FBURL:http://example.com/fb/jdoe\n"
                          "FB:Dr. John Doe\n"
                          "GENDER:M\n"
                          "GEO:geo:39.95,-75.1667\n"
                          "IMPP:aim:johndoe@aol.com\n"
                          "KEY;MEDIATYPE=application/pgp-keys:http://example.com/key.pgp\n"
                          "KIND:individual\n"
                          "LABEL;TYPE=HOME:123 Main St.\\nSpringfield, IL 12345\\nUSA\n"
                          "LANG:fr-CA\n"
                          "LOGO;MEDIATYPE=image/png:http://example.com/logo.png\n"
                          "MAILER:Thunderbird\n"
                          "MEMBER:urn:uuid:03a0e51f-d1aa-4385-8a53-e29025acd8af\n"
                          "NICKNAME:PayamGr\n"
                          "NOTE:I am proficient in Tiger-Crane Style,\\nand I am more than "
                          "proficient in the exquisite art of the Samurai sword.\n"
                          "ORG:Google;GMail Team;Spam Detection Squad\n"
                          "PHOTO;MEDIATYPE=image/jpeg:http://example.com/photo.jpg\n"
                          "PRODID:-//ONLINE DIRECTORY//NONSGML Version 1//EN\n"
                          "PROFILE:VCARD\n"
                          "RELATED;TYPE=friend:urn:uuid:03a0e51f-d1aa-4385-8a53-e29025acd8af\n"
                          "REV:20121201T134211Z\n"
                          "ROLE:Executive\n"
                          "SORT-STRING:Doe\n"
                          "SOUND;MEDIATYPE=audio/ogg:http://example.com/sound.ogg\n"
                          "SOURCE:http://johndoe.com/vcard.vcf\n"
                          "TITLE:V.P. Research and Development\n"
                          "TZ:America/New_York\n"
                          "UID:urn:uuid:da418720-3754-4631-a169-db89a02b831b\n"
                          "URL:http://www.johndoe.com\n"
                          "XML:XML:<b>Not an xCard XML element</b>\n"
                          "END:VCARD"));
}
} // namespace VCardTest

int src_qrcode_content_v_card_test(int argC, char *argV[]) {
  using namespace VCardTest;
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
  testNotFound("src_qrcode_content_v_card_test", argC, argV);
  return 1;
}
