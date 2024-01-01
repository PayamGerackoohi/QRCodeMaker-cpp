#include "content/face-time.hpp"
#include "test-util/assertion.hpp"
#include "test-util/test-platform.hpp"
#include <cassert>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>

using QrCodeUtil::FaceTime;
using std::make_unique;
using std::string;

void video_phone_test() {
  FaceTime faceTime(FaceTime::Type::Video, "+18005551212");
  assert(is_equal<string>(faceTime.str(), "facetime:+18005551212"));
}

void video_cloud_id_test() {
  FaceTime faceTime(FaceTime::Type::Video, "me@icloud.com");
  assert(is_equal<string>(faceTime.str(), "facetime:me@icloud.com"));
}

void audio_phone_test() {
  FaceTime faceTime(FaceTime::Type::Audio, "+18005551212");
  assert(is_equal<string>(faceTime.str(), "facetime-audio:+18005551212"));
}

void audio_cloud_id_test() {
  FaceTime faceTime(FaceTime::Type::Audio, "me@icloud.com");
  assert(is_equal<string>(faceTime.str(), "facetime-audio:me@icloud.com"));
}

int src_qrcode_content_face_time_test(int argC, char *argV[]) {
  for (int i = 1; i < argC; i++) {
    const auto testName = argV[i];
    if (strcmp(testName, "video_phone") == 0) {
      video_phone_test();
      return 0;
    }
    if (strcmp(testName, "video_cloud_id") == 0) {
      video_cloud_id_test();
      return 0;
    }
    if (strcmp(testName, "audio_phone") == 0) {
      audio_phone_test();
      return 0;
    }
    if (strcmp(testName, "audio_cloud_id") == 0) {
      audio_cloud_id_test();
      return 0;
    }
  }
  testNotFound("src_qrcode_content_face_time_test", argC, argV);
  return 1;
}
