#ifndef MAIN_HPP
#define MAIN_HPP

#include "qrcode-util.hpp"

using QR = std::unique_ptr<QrCodeUtil::QrCode>;

int main();
QR meCard();
QR vcard();
QR call();
QR website();
QR email();

#endif
