#include "content/calendar.hpp"
#include "test-util/assertion.hpp"
#include "test-util/test-platform.hpp"
#include <cstring>
#include <iostream>
#include <string>

using QrCodeUtil::Calendar;
using std::make_unique;
using std::string;

namespace CalendarTest {
void minimal_data_test() {
  Calendar calendar;
  calendar.event = make_unique<Calendar::Event>();
  calendar.event->start = make_unique<string>("19970714T170000Z");
  calendar.event->end = make_unique<string>("19970715T040000Z");
  calendar.event->summary = make_unique<string>("Bastille Day Party");
  assert(is_equal<string>(calendar.str(), "BEGIN:VCALENDAR\n"
                                          "BEGIN:VEVENT\n"
                                          "DTSTART:19970714T170000Z\n"
                                          "DTEND:19970715T040000Z\n"
                                          "SUMMARY:Bastille Day Party\n"
                                          "END:VEVENT\n"
                                          "END:VCALENDAR"));
}

void full_data_test() {
  Calendar calendar;
  calendar.version = make_unique<string>("2.0");
  calendar.prodId = make_unique<string>("-//hacksw/handcal//NONSGML v1.0//EN");
  calendar.event = make_unique<Calendar::Event>();
  calendar.event->uid = make_unique<string>("uid1@example.com");
  calendar.event->creationDate = make_unique<string>("19970714T170000Z");
  calendar.event->organizer = make_unique<string>("CN=John Doe:MAILTO:john.doe@example.com");
  calendar.event->start = make_unique<string>("19970714T170000Z");
  calendar.event->end = make_unique<string>("19970715T040000Z");
  calendar.event->summary = make_unique<string>("Bastille Day Party");
  calendar.event->geo = make_unique<string>("48.85299;2.36885");
  assert(is_equal<string>(calendar.str(), "BEGIN:VCALENDAR\n"
                                          "VERSION:2.0\n"
                                          "PRODID:-//hacksw/handcal//NONSGML v1.0//EN\n"
                                          "BEGIN:VEVENT\n"
                                          "UID:uid1@example.com\n"
                                          "DTSTAMP:19970714T170000Z\n"
                                          "ORGANIZER;CN=John Doe:MAILTO:john.doe@example.com\n"
                                          "DTSTART:19970714T170000Z\n"
                                          "DTEND:19970715T040000Z\n"
                                          "SUMMARY:Bastille Day Party\n"
                                          "GEO:48.85299;2.36885\n"
                                          "END:VEVENT\n"
                                          "END:VCALENDAR"));
}
} // namespace CalendarTest

int src_qrcode_content_calendar_test(int argC, char *argV[]) {
  using namespace CalendarTest;
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
  testNotFound("src_qrcode_content_calendar_test", argC, argV);
  return 1;
}
