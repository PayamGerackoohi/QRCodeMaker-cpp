#include "content/wifi.hpp"
#include "test-util/assertion.hpp"
#include "test-util/test-platform.hpp"
#include <cassert>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>

using QrCodeUtil::Wifi;
using std::make_unique;
using std::string;

void ssid_from_ascii_test() {
  auto ssid = Wifi::SSID::fromAscii("zzz");
  assert(is_equal<string>(ssid->value, "\"zzz\""));
}

void ssid_from_hex_test() {
  auto ssid = Wifi::SSID::fromHex("aaa");
  assert(is_equal<string>(ssid->value, "aaa"));
}

void minimal_data_test() {
  Wifi wifi;
  using AType = Wifi::AuthenticationType;
  wifi.authenticationType = make_unique<AType>(AType::WPA);
  wifi.ssid = make_unique<Wifi::SSID>("mynetwork");
  wifi.password = make_unique<string>("mypass");
  assert(is_equal<string>(wifi.str(), "WIFI:T:WPA;S:mynetwork;P:mypass;;"));
}

void full_data_test() {
  Wifi wifi;
  using AType = Wifi::AuthenticationType;
  wifi.authenticationType = make_unique<AType>(AType::WPA);
  wifi.ssid = make_unique<Wifi::SSID>("mynetwork");
  wifi.password = make_unique<string>("mypass");
  wifi.hideSsid = make_unique<bool>(true);
  wifi.eapMode = make_unique<string>("TTLS");
  wifi.anonymousIdentity = make_unique<string>("anon");
  wifi.identity = make_unique<string>("myidentity");
  wifi.phase2method = make_unique<string>("MSCHAPV2");
  assert(is_equal<string>(
      wifi.str(),
      "WIFI:T:WPA;S:mynetwork;P:mypass;H:true;E:TTLS;A:anon;I:myidentity;PH2:MSCHAPV2;;"));
}

int src_qrcode_content_wifi_test(int argC, char *argV[]) {
  for (int i = 1; i < argC; i++) {
    const auto testName = argV[i];
    if (strcmp(testName, "ssid_from_ascii") == 0) {
      ssid_from_ascii_test();
      return 0;
    }
    if (strcmp(testName, "ssid_from_hex") == 0) {
      ssid_from_hex_test();
      return 0;
    }
    if (strcmp(testName, "minimal_data") == 0) {
      minimal_data_test();
      return 0;
    }
    if (strcmp(testName, "full_data") == 0) {
      full_data_test();
      return 0;
    }
  }
  testNotFound("src_qrcode_content_wifi_test", argC, argV);
  return 1;
}
