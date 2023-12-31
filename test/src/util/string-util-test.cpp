#include "test-util/assertion.hpp"
#include "test-util/test-platform.hpp"
#include "util/string-util.hpp"
#include <cstring>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

void join_empty_list_test() {
  vector<int> list;
  assert(join(list) == "");
}

void join_default_test() {
  vector list{2, 3, 5, 7};
  assert(join(list) == "2,3,5,7");
}

void join_custom_delimiter_test() {
  vector list{2, 3, 5, 7};
  assert(join(list, ", ") == "2, 3, 5, 7");
}

struct User {
  int id;
  std::string name;
  bool isAdmin;
  User(int id, std::string name, bool isAdmin) : id(id), name(name), isAdmin(isAdmin) {}
  friend std::ostream &operator<<(std::ostream &os, User &user) {
    os << "User(id: " << user.id << ", name: " << user.name
       << ", isAdmin: " << (user.isAdmin == 0 ? "false" : "true") << ")";
    return os;
  }
};

vector<User> makeUsers() {
  vector<User> users{User(123, "Payam", true), User(321, "Mayap", false)};
  return users;
}

void join_custom_type_test() {
  auto users = makeUsers();
  auto result = join(users, " -- ");
  assert(is_equal<string>(
      "User(id: 123, name: Payam, isAdmin: true) -- User(id: 321, name: Mayap, isAdmin: false)",
      result));
}

void encode_url_test() {
  assert(is_equal<string>(url_encode("aaa bbb!@#$%^&*()1234567890"), "???"));
}

template <typename IN, typename OUT> struct TestCase {
  IN input;
  OUT output;
  TestCase(IN input, OUT output) : input(input), output(output) {}
};

void geo_format_test() {
  vector cases{
      TestCase(0, "0.00000"),
      TestCase(1, "0.00001"),
      TestCase(12, "0.00012"),
      TestCase(123, "0.00123"),
      TestCase(1'234, "0.01234"),
      TestCase(12'345, "0.12345"),
      TestCase(123'456, "1.23456"),
      TestCase(1'234'567, "12.34567"),
      TestCase(12'345'678, "123.45678"),
      TestCase(123'456'789, "1234.56789"),
      TestCase(1'234'567'891, "12345.67891"),
      TestCase(-1, "-0.00001"),
      TestCase(-12, "-0.00012"),
      TestCase(-123, "-0.00123"),
      TestCase(-1'234, "-0.01234"),
      TestCase(-12'345, "-0.12345"),
      TestCase(-123'456, "-1.23456"),
      TestCase(-1'234'567, "-12.34567"),
      TestCase(-12'345'678, "-123.45678"),
      TestCase(-123'456'789, "-1234.56789"),
      TestCase(-1'234'567'891, "-12345.67891"),
  };
  for (auto &c : cases)
    assert(is_equal<string>(geo_format(c.input), c.output));
}

int src_util_string_util_test(int argC, char *argV[]) {
  for (int i = 1; i < argC; i++) {
    const auto testName = argV[i];
    if (strcmp(testName, "join_empty_list") == 0) {
      join_empty_list_test();
      return 0;
    }
    if (strcmp(testName, "join_default") == 0) {
      join_default_test();
      return 0;
    }
    if (strcmp(testName, "join_custom_delimiter") == 0) {
      join_custom_delimiter_test();
      return 0;
    }
    if (strcmp(testName, "join_custom_type") == 0) {
      join_custom_type_test();
      return 0;
    }
    if (strcmp(testName, "geo_format") == 0) {
      geo_format_test();
      return 0;
    }
  }
  testNotFound("src_string_util_test", argC, argV);
  return 1;
}
