#include "main.hpp"
#include <fstream>
// #include <iostream>
// #include <sstream>
#include <string>

using QrCodeUtil::Email;
using QrCodeUtil::MeCard;
using QrCodeUtil::PhoneCall;
using QrCodeUtil::QrCode;
using QrCodeUtil::VCard;
// using std::cout;
// using std::endl;
using std::make_unique;
// using std::ostringstream;
using std::string;

int main() {
  auto qr = meCard();
  // auto qr = vcard();
  // auto qr = call();
  // auto qr = website();
  // auto qr = email();
  // PhoneCall phoneCall("+98 905 738 0865");
  // auto text = "BEGIN:VEVENT\n"
  //             "SUMMARY:Summer+Vacation!\n"
  //             "DTSTART:20180601T070000Z\n"
  //             "DTEND:20180831T070000Z\n"
  //             "END:VEVENT\n";
  // auto text = "BEGIN:VCALENDAR\n"
  //             "VERSION:2.0\n"
  //             "PRODID:-//hacksw/handcal//NONSGML v1.0//EN\n"
  //             "BEGIN:VEVENT\n"
  //             "UID:uid1@example.com\n"
  //             "DTSTAMP:19970714T170000Z\n"
  //             "ORGANIZER;CN=John Doe:MAILTO:john.doe@example.com\n"
  //             "DTSTART:19970714T170000Z\n"
  //             "DTEND:19970715T040000Z\n"
  //             "SUMMARY:Bastille Day Party\n"
  //             "GEO:48.85299;2.36885\n"
  //             "END:VEVENT\n"
  //             "END:VCALENDAR\n";
  // auto qr = make_unique<QrCode>(QrCode::encodeText(text, QrCode::Ecc::LOW));

  std::ofstream file("build/output.svg");
  file << QrCodeUtil::toSvgString(*qr, 10);
  file.close();
  return 0;
}

QR meCard() {
  MeCard card;
  card.name = make_unique<MeCard::Name>("Payam", "Gerackoohi");
  card.phone = make_unique<string>("+98 905 738 0865");
  card.videoPhone = make_unique<string>("+98 905 738 0865");
  card.email = make_unique<string>("pgerackoohi@gmail.com");
  card.address = make_unique<string>(",,123 Main St.,Springfield,IL,12345,USA");
  card.birthDay = make_unique<string>("19700310");
  card.nickName = make_unique<string>("PayamGr");
  card.note = make_unique<string>("I am proficient in Tiger-Crane Style,\nand I am more than "
                                  "proficient in the exquisite art of the Samurai sword.");
  card.url = make_unique<string>("https://www.johndoe.com/");
  return make_unique<QrCode>(QrCode::encodeText(card.str().c_str(), QrCode::Ecc::LOW));
}

QR vcard() {
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
  return make_unique<QrCode>(QrCode::encodeText(card.str().c_str(), QrCode::Ecc::LOW));
}

QR call() {
  PhoneCall phoneCall("+98 905 738 0865");
  return make_unique<QrCode>(QrCode::encodeText(phoneCall.str().c_str(), QrCode::Ecc::LOW));
}

QR website() {
  auto url = "https://github.com/zxing/zxing/wiki/Barcode-Contents";
  return make_unique<QrCode>(QrCode::encodeText(url, QrCode::Ecc::LOW));
}

QR email() {
  Email email("pgerackoohi@gmail.com");
  email.cc = {"someoneelse@theirsite.com", "another@thatsite.com", "me@mysite.com"};
  email.bcc = {"lastperson@theirsite.com"};
  email.subject = make_unique<string>("Big News");
  email.body = make_unique<string>("Body goes here.");
  return make_unique<QrCode>(QrCode::encodeText(email.str().c_str(), QrCode::Ecc::LOW));
}
