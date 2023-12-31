#include "content/app-market.hpp"
#include "test-util/assertion.hpp"
#include "test-util/test-platform.hpp"
#include <cstring>
#include <iostream>
#include <string>

using namespace QrCodeUtil::AppMarket;
using std::make_unique;
using std::string;

void google_play_test() {
  assert(
      is_equal<string>(GooglePlay("org.example.foo").str(), "market://details?id=org.example.foo"));
}

void apple_music_test() {
  assert(is_equal<string>(
      AppleMusic("concrete-and-gold/1249068417?mt=1&app=music").str(),
      "https://geo.itunes.apple.com/us/album/concrete-and-gold/1249068417?mt=1&app=music"));
  assert(is_equal<string>(
      AppleMusic("concrete-and-gold/1249068417?mt=1&app=itunes").str(),
      "https://geo.itunes.apple.com/us/album/concrete-and-gold/1249068417?mt=1&app=itunes"));
}

void i_book_store_test() {
  assert(
      is_equal<string>(IBookStore("crazy-rich-asians/id588213164?mt=11").str(),
                       "https://geo.itunes.apple.com/us/book/crazy-rich-asians/id588213164?mt=11"));
}

void app_store_test() {
  assert(is_equal<string>(AppStore("fortnite/id1261357853?mt=8").str(),
                          "https://itunes.apple.com/us/app/fortnite/id1261357853?mt=8"));
}

int src_qrcode_content_app_market_test(int argC, char *argV[]) {
  for (int i = 1; i < argC; i++) {
    const auto testName = argV[i];
    if (strcmp(testName, "google_play") == 0) {
      google_play_test();
      return 0;
    }
    if (strcmp(testName, "apple_music") == 0) {
      apple_music_test();
      return 0;
    }
    if (strcmp(testName, "i_book_store") == 0) {
      i_book_store_test();
      return 0;
    }
    if (strcmp(testName, "app_store") == 0) {
      app_store_test();
      return 0;
    }
  }
  testNotFound("src_qrcode_content_app_market_test", argC, argV);
  return 1;
}
