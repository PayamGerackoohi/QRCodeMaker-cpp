#include "content/email.hpp"
#include "test-util/assertion.hpp"
#include "test-util/test-platform.hpp"
#include <cstring>
#include <iostream>
#include <string>

using QrCodeUtil::Email;
using std::make_unique;
using std::string;

void address_test() {
  Email email("someone@yoursite.com");
  assert(is_equal<string>(email.str(), "mailto:someone@yoursite.com"));
}

void address_subject_test() {
  Email email("someone@yoursite.com");
  email.subject = make_unique<string>("Mail from Our Site");
  assert(is_equal<string>(email.str(),
                          "mailto:someone@yoursite.com?subject=Mail%20from%20Our%20Site"));
}

void address_cc_bcc_subject_test() {
  Email email("someone@yoursite.com");
  email.cc = {"someoneelse@theirsite.com", "another@thatsite.com", "me@mysite.com"};
  email.bcc = {"lastperson@theirsite.com"};
  email.subject = make_unique<string>("Big News");
  assert(is_equal<string>(
      email.str(), "mailto:someone@yoursite.com?cc=someoneelse@theirsite.com,another@thatsite.com,"
                   "me@mysite.com&bcc=lastperson@theirsite.com&subject=Big%20News"));
}

void address_cc_bcc_subject_body_test() {
  Email email("someone@yoursite.com");
  email.cc = {"someoneelse@theirsite.com", "another@thatsite.com", "me@mysite.com"};
  email.bcc = {"lastperson@theirsite.com"};
  email.subject = make_unique<string>("Big News");
  email.body = make_unique<string>("Body goes here.");
  assert(is_equal<string>(
      email.str(),
      "mailto:someone@yoursite.com?cc=someoneelse@theirsite.com,another@thatsite.com,me@mysite.com&"
      "bcc=lastperson@theirsite.com&subject=Big%20News&body=Body%20goes%20here."));
}

int src_qrcode_content_email_test(int argC, char *argV[]) {
  for (int i = 1; i < argC; i++) {
    const auto testName = argV[i];
    if (strcmp(testName, "address") == 0) {
      address_test();
      return 0;
    }
    if (strcmp(testName, "address_subject") == 0) {
      address_subject_test();
      return 0;
    }
    if (strcmp(testName, "address_cc_bcc_subject") == 0) {
      address_cc_bcc_subject_test();
      return 0;
    }
    if (strcmp(testName, "address_cc_bcc_subject_body") == 0) {
      address_cc_bcc_subject_body_test();
      return 0;
    }
  }
  testNotFound("src_qrcode_content_email_test", argC, argV);
  return 1;
}
