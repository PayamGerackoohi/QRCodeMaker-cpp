set(testModule QrCodeTest)
create_test_sourcelist(Tests
  TestRunner.cpp
  src/qrcode/content/app-market-test.cpp
  src/qrcode/content/biz-card-test.cpp
  src/qrcode/content/calendar-test.cpp
  src/qrcode/content/email-test.cpp
  src/qrcode/content/face-time-test.cpp
  src/qrcode/content/geo-test.cpp
  src/qrcode/content/me-card-test.cpp
  src/qrcode/content/phone-call-test.cpp
  src/qrcode/content/sms-test.cpp
  src/qrcode/content/v-card-test.cpp
  src/qrcode/content/wifi-test.cpp
  src/util/string-util-test.cpp
)

include_directories(src)
add_executable(${testModule} ${Tests} src/test-util/test-platform.cpp)
target_include_directories(${testModule} PRIVATE
  ../lib/include
  ../lib/src
)
target_link_libraries(${testModule} PRIVATE qrcode)

enable_testing()

# set (TestsToRun ${Tests})
# remove (TestsToRun TestRunner.cpp)
# foreach (test ${TestsToRun})
#   get_filename_component (TName ${test} NAME_WE)
#   add_test (NAME ${TName} COMMAND ${testModule} src/${TName})
# endforeach ()

# *** Adding Tests ***
function(add_tests testName testSource)
  foreach(test ${ARGN})
    add_test(NAME ${testName}.${test} COMMAND ${testModule} ${testSource} ${test})
  endforeach()
endfunction()

# *** Email Test ***
add_tests(Email src/qrcode/content/email-test
  address
  address_subject
  address_cc_bcc_subject
  address_cc_bcc_subject_body
)

# *** Me-Card Test ***
add_tests(MeCard src/qrcode/content/me-card-test
  minimal_data
  full_data
)

# *** Phone Call Test ***
add_tests(PhoneCall src/qrcode/content/phone-call-test
  normal_use_case
)

# *** V-Card Test ***
add_tests(VCard src/qrcode/content/v-card-test
  minimal_data
  full_data
)

# *** String Util Test ***
add_tests(StringUtil src/util/string-util-test
  join_empty_list
  join_default
  join_custom_delimiter
  join_custom_type
  geo_format
)

# *** Biz Card Test ***
add_tests(BizCard src/qrcode/content/biz-card-test
  normal_use_case
)

# *** SMS Test ***
add_tests(SMS src/qrcode/content/sms-test
  phone
  phone_message
)

# *** FaceTime Test ***
add_tests(FaceTime src/qrcode/content/face-time-test
  video_phone
  video_cloud_id
  audio_phone
  audio_cloud_id
)

# *** GEO Test ***
add_tests(GEO src/qrcode/content/geo-test
  latitude_longitude
  latitude_longitude_altitude
)

# *** Calendar Test ***
add_tests(Calendar src/qrcode/content/calendar-test
  minimal_data
  full_data
)

# *** Wifi Test ***
add_tests(Wifi src/qrcode/content/wifi-test
  ssid_from_ascii
  ssid_from_hex
  minimal_data
  full_data
)

# *** App Market Test ***
add_tests(AppMarket src/qrcode/content/app-market-test
  google_play
  apple_music
  i_book_store
  app_store
)
