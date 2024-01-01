# QR-Code
A C++ QR-Code wrapper around [QR-Code-generator](https://github.com/nayuki/QR-Code-generator) to provide easier content generation.

Currently it can make:
- Raw Text
- App Market
- Biz-Card
- Calendar
- Email
- Face Time
- Geo
- Me-Card
- Phone Call
- SMS
- V-Card
- Wifi

## Run
```sh
./scripts/config.sh 
./scripts/build.sh 
./scripts/test.sh 
./scripts/run.sh 
```

## Sample
```c++
#include "qrcode-util.hpp"
#include <fstream>
#include <string>

using QrCodeUtil::MeCard;
using QrCodeUtil::QrCode;
using std::make_unique;
using std::unique_ptr;
using std::string;

unique_ptr<QrCode> meCard() {
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
  return QrCode::encodeText(card.str().c_str(), QrCode::Ecc::LOW);
}

int main() {
  auto qr = meCard();
  std::ofstream file("build/output.svg");
  file << QrCodeUtil::toSvgString(*qr, 10);
  file.close();
  return 0;
}
```

### Output
![Output](/doc/images/output.svg)
