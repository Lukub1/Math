#include "s21_math_test.h"

START_TEST(test_s21_abs) {
  ck_assert_int_eq(s21_abs(i0), abs(i0));
  ck_assert_int_eq(s21_abs(i1), abs(i1));
  ck_assert_int_eq(s21_abs(i2), abs(i2));
  ck_assert_int_eq(s21_abs(i3), abs(i3));
  ck_assert_int_eq(s21_abs(i4), abs(i4));
}
END_TEST

START_TEST(test_s21_fabs) {
  ck_assert_uint_eq(s21_fabs(d0), fabs(d0));
  ck_assert_uint_eq(s21_fabs(d1), fabs(d1));
  ck_assert_uint_eq(s21_fabs(-d2), fabs(-d2));
  ck_assert_uint_eq(s21_fabs(d3), fabs(d3));
  ck_assert_uint_eq(s21_fabs(d7), fabs(d7));
  ck_assert_uint_eq(s21_fabs(d8), fabs(d8));
  ck_assert_uint_eq(s21_fabs(-s21_M_PI), fabs(-s21_M_PI));
  ck_assert_uint_eq(s21_fabs(-s21_EXP), fabs(-s21_EXP));
}
END_TEST

START_TEST(test_s21_pow) {
  ck_assert_uint_eq(s21_pow(i0, i0), pow(i0, i0));
  ck_assert_uint_eq(s21_pow(i1, i1), pow(i1, i1));
  ck_assert_uint_eq(s21_pow(i2, i2), pow(i2, i2));
  ck_assert_uint_eq(s21_pow(i2, i1), pow(i2, i1));
  ck_assert_uint_eq(s21_pow(i2, -i1), pow(i2, -i1));
  ck_assert_uint_eq(s21_pow(i3, i0), pow(i3, i0));
  ck_assert_uint_eq(s21_pow(d0, i0), pow(d0, i0));
  ck_assert_uint_eq(s21_pow(d0, i1), pow(d0, i1));
  ck_assert_uint_eq(s21_pow(d1, i2), pow(d1, i2));
  ck_assert_uint_eq(s21_pow(d1, d0), pow(d1, d0));
  ck_assert_uint_eq(s21_pow(d1, d1), pow(d1, d1));
  ck_assert_uint_eq(s21_pow(d2, d2), pow(d2, d3));
  ck_assert_uint_eq(s21_pow(d4, d0), pow(d4, d0));
  ck_assert_uint_eq(s21_pow(d4, d4), pow(d4, d4));
  ck_assert_uint_eq(s21_pow(d4, d5), pow(d4, d5));
  ck_assert_uint_eq(s21_pow(-d3, s21_POSINF), pow(-d3, s21_POSINF));
  ck_assert_uint_eq(s21_pow(-d3, d3), pow(-d3, d3));
  ck_assert_uint_eq(s21_pow(s21_NEGINF, d5), pow(s21_NEGINF, d5));
  ck_assert_uint_eq(s21_pow(s21_NEGINF, d1), pow(s21_NEGINF, d1));
  ck_assert_uint_eq(s21_pow(s21_POSINF, d1), pow(s21_POSINF, d1));
  ck_assert_uint_eq(s21_pow(s21_POSINF, -d1), pow(s21_POSINF, -d1));
}
END_TEST

START_TEST(test_s21_ceil) {
  ck_assert_uint_eq(s21_ceil(i0), ceil(i0));
  ck_assert_uint_eq(s21_ceil(i1), ceil(i1));
  ck_assert_uint_eq(s21_ceil(i2), ceil(i2));
  ck_assert_uint_eq(s21_ceil(i3), ceil(i3));
  ck_assert_uint_eq(s21_ceil(i4), ceil(i4));
  ck_assert_uint_eq(s21_ceil(d0), ceil(d0));
  ck_assert_uint_eq(s21_ceil(d1), ceil(d1));
  ck_assert_uint_eq(s21_ceil(d2), ceil(d2));
  ck_assert_uint_eq(s21_ceil(d3), ceil(d3));
  ck_assert_uint_eq(s21_ceil(d5), ceil(d5));
  ck_assert_uint_eq(s21_ceil(d6), ceil(d6));
  ck_assert_uint_eq(s21_ceil(d7), ceil(d7));
  ck_assert_uint_eq(s21_ceil(d8), ceil(d8));
  ck_assert_uint_eq(s21_ceil(s21_M_PI), ceil(s21_M_PI));
  ck_assert_uint_eq(s21_ceil(s21_EXP), ceil(s21_EXP));
}
END_TEST

START_TEST(test_s21_floor) {
  ck_assert_uint_eq(s21_floor(i0), floor(i0));
  ck_assert_uint_eq(s21_floor(i1), floor(i1));
  ck_assert_uint_eq(s21_floor(i2), floor(i2));
  ck_assert_uint_eq(s21_floor(i3), floor(i3));
  ck_assert_uint_eq(s21_floor(-i4), floor(-i4));
  ck_assert_uint_eq(s21_floor(d0), floor(d0));
  ck_assert_uint_eq(s21_floor(d1), floor(d1));
  ck_assert_uint_eq(s21_floor(d2), floor(d2));
  ck_assert_uint_eq(s21_floor(d3), floor(d3));
  ck_assert_uint_eq(s21_floor(d4), floor(d4));
  ck_assert_uint_eq(s21_floor(d5), floor(d5));
  ck_assert_uint_eq(s21_floor(d6), floor(d6));
  ck_assert_uint_eq(s21_floor(d7), floor(d7));
  ck_assert_uint_eq(s21_floor(d8), floor(d8));
  ck_assert_uint_eq(s21_floor(s21_M_PI), floor(s21_M_PI));
  ck_assert_uint_eq(s21_floor(s21_EXP), floor(s21_EXP));
}
END_TEST

START_TEST(test_s21_fmod) {
  ck_assert_uint_eq(s21_fmod(i0, s21_M_PI), fmod(i0, s21_M_PI));
  ck_assert_uint_eq(s21_fmod(i0, d0), fmod(i0, d0));
  ck_assert_uint_eq(s21_fmod(i1, d5), fmod(i1, d5));
  ck_assert_uint_eq(s21_fmod(i2, i4), fmod(i2, i4));
  ck_assert_uint_eq(s21_fmod(i3, s21_M_PI), fmod(i3, s21_M_PI));
  ck_assert_uint_eq(s21_fmod(i4, s21_M_PI), fmod(i4, s21_M_PI));
  ck_assert_uint_eq(s21_fmod(d0, s21_M_PI), fmod(d0, s21_M_PI));
  ck_assert_uint_eq(s21_fmod(d0, d0), fmod(d0, d0));
  ck_assert_uint_eq(s21_fmod(d1, d5), fmod(d1, d5));
  ck_assert_uint_eq(s21_fmod(d2, i4), fmod(d2, i4));
  ck_assert_uint_eq(s21_fmod(d3, s21_M_PI), fmod(d3, s21_M_PI));
}
END_TEST

START_TEST(test_s21_cos) {
  ck_assert_uint_eq(s21_cos(i0), cos(i0));
  ck_assert_uint_eq(s21_cos(i1), cos(i1));
  ck_assert_uint_eq(s21_cos(i2), cos(i2));
  ck_assert_uint_eq(s21_cos(i3), cos(i3));
  ck_assert_uint_eq(s21_cos(i4), cos(i4));
  ck_assert_uint_eq(s21_cos(d0), cos(d0));
  ck_assert_uint_eq(s21_cos(d1), cos(d1));
  ck_assert_uint_eq(s21_cos(d2), cos(d2));
  ck_assert_uint_eq(s21_cos(d3), cos(d3));
  ck_assert_uint_eq(s21_cos(d4), cos(d4));
  ck_assert_uint_eq(s21_cos(d5), cos(d5));
  ck_assert_uint_eq(s21_cos(d6), cos(d6));
  ck_assert_uint_eq(s21_cos(d7), cos(d7));
  ck_assert_uint_eq(s21_cos(d8), cos(d8));
  ck_assert_uint_eq(s21_cos(s21_M_PI), cos(s21_M_PI));
  ck_assert_uint_eq(s21_cos(s21_EXP), cos(s21_EXP));
  ck_assert_uint_eq(s21_cos(s21_POSINF), cos(s21_POSINF));
}
END_TEST

START_TEST(test_s21_acos) {
  ck_assert_uint_eq(s21_acos(i0), acos(i0));
  ck_assert_uint_eq(s21_acos(i1), acos(i1));
  ck_assert_uint_eq(s21_acos(-i1), acos(-i1));
  ck_assert_uint_eq(s21_acos(i3), acos(i3));
  ck_assert_uint_eq(s21_acos(i4), acos(i4));
  ck_assert_uint_eq(s21_acos(d0), acos(d0));
  ck_assert_uint_eq(s21_acos(d1), acos(d1));
  ck_assert_uint_eq(s21_acos(d2), acos(d2));
  ck_assert_uint_eq(s21_acos(d5), acos(d5));
  ck_assert_uint_eq(s21_acos(d6), acos(d6));
}
END_TEST

START_TEST(test_s21_sin) {
  ck_assert_uint_eq(s21_sin(i0), sin(i0));
  ck_assert_uint_eq(s21_sin(i1), sin(i1));
  ck_assert_uint_eq(s21_sin(i2), sin(i2));
  ck_assert_uint_eq(s21_sin(i3), sin(i3));
  ck_assert_uint_eq(s21_sin(i4), sin(i4));
  ck_assert_uint_eq(s21_sin(d0), sin(d0));
  ck_assert_uint_eq(s21_sin(d1), sin(d1));
  ck_assert_uint_eq(s21_sin(d2), sin(d2));
  ck_assert_uint_eq(s21_sin(d3), sin(d3));
  ck_assert_uint_eq(s21_sin(d4), sin(d4));
  ck_assert_uint_eq(s21_sin(d5), sin(d5));
  ck_assert_uint_eq(s21_sin(d6), sin(d6));
  ck_assert_uint_eq(s21_sin(d7), sin(d7));
  ck_assert_uint_eq(s21_sin(d8), sin(d8));
  ck_assert_uint_eq(s21_sin(s21_M_PI), sin(s21_M_PI));
  ck_assert_uint_eq(s21_sin(s21_EXP), sin(s21_EXP));
  ck_assert_uint_eq(s21_sin(s21_POSINF), sin(s21_POSINF));
}
END_TEST

START_TEST(test_s21_asin) {
  ck_assert_uint_eq(s21_asin(-d2), asin(-d2));
  ck_assert_uint_eq(s21_asin(-d1), asin(-d1));
  ck_assert_uint_eq(s21_asin(-d5), asin(-d5));
  ck_assert_uint_eq(s21_asin(-d6), asin(-d6));
  ck_assert_uint_eq(s21_asin(d0), asin(d0));
  ck_assert_uint_eq(s21_asin(d1), asin(d1));
  ck_assert_uint_eq(s21_asin(d6), asin(d6));
  ck_assert_uint_eq(s21_asin(d5), asin(d5));
  ck_assert_uint_eq(s21_asin(d2), asin(d2));
}
END_TEST

START_TEST(test_s21_tan) {
  ck_assert_uint_eq(s21_tan(i0), tan(i0));
  ck_assert_uint_eq(s21_tan(i1), tan(i1));
  ck_assert_uint_eq(s21_tan(i2), tan(i2));
  ck_assert_uint_eq(s21_tan(i3), tan(i3));
  ck_assert_uint_eq(s21_tan(i4), tan(i4));
  ck_assert_uint_eq(s21_tan(d0), tan(d0));
  ck_assert_uint_eq(s21_tan(d1), tan(d1));
  ck_assert_uint_eq(s21_tan(d2), tan(d2));
  ck_assert_uint_eq(s21_tan(d3), tan(d3));
  ck_assert_uint_eq(s21_tan(d4), tan(d4));
  ck_assert_uint_eq(s21_tan(d5), tan(d5));
  ck_assert_uint_eq(s21_tan(d6), tan(d6));
  ck_assert_uint_eq(s21_tan(s21_EXP), tan(s21_EXP));
  ck_assert_uint_eq(s21_tan(s21_NAN), tan(s21_NAN));
}
END_TEST

START_TEST(test_s21_atan) {
  ck_assert_uint_eq(s21_atan(-d2), atan(-d2));
  ck_assert_uint_eq(s21_atan(-d1), atan(-d1));
  ck_assert_uint_eq(s21_atan(-d5), atan(-d5));
  ck_assert_uint_eq(s21_atan(-d6), atan(-d6));
  ck_assert_uint_eq(s21_atan(d0), atan(d0));
  ck_assert_uint_eq(s21_atan(d1), atan(d1));
  ck_assert_uint_eq(s21_atan(d6), atan(d6));
  ck_assert_uint_eq(s21_atan(d5), atan(d5));
  ck_assert_uint_eq(s21_atan(d2), atan(d2));
  ck_assert_uint_eq(s21_atan(s21_M_PI), atan(s21_M_PI));
  ck_assert_uint_eq(s21_atan(s21_POSINF), atan(s21_POSINF));
  ck_assert_uint_eq(s21_atan(s21_NEGINF), atan(s21_NEGINF));
  ck_assert_uint_eq(s21_atan(s21_EXP), atan(s21_EXP));
}
END_TEST

START_TEST(test_s21_sqrt) {
  ck_assert_uint_eq(s21_sqrt(i0), sqrt(i0));
  ck_assert_uint_eq(s21_sqrt(i1), sqrt(i1));
  ck_assert_uint_eq(s21_sqrt(i2), sqrt(i2));
  ck_assert_uint_eq(s21_sqrt(i3), sqrt(i3));
  ck_assert_uint_eq(s21_sqrt(i4), sqrt(i4));
  ck_assert_uint_eq(s21_sqrt(d0), sqrt(d0));
  ck_assert_uint_eq(s21_sqrt(d1), sqrt(d1));
  ck_assert_uint_eq(s21_sqrt(d2), sqrt(d2));
  ck_assert_uint_eq(s21_sqrt(d3), sqrt(d3));
  ck_assert_uint_eq(s21_sqrt(d4), sqrt(d4));
  ck_assert_uint_eq(s21_sqrt(d5), sqrt(d5));
  ck_assert_uint_eq(s21_sqrt(d6), sqrt(d6));
  ck_assert_uint_eq(s21_sqrt(d7), sqrt(d7));
  ck_assert_uint_eq(s21_sqrt(d8), sqrt(d8));
  ck_assert_uint_eq(s21_sqrt(s21_M_PI), sqrt(s21_M_PI));
  ck_assert_uint_eq(s21_sqrt(s21_EXP), sqrt(s21_EXP));
  ck_assert_uint_eq(s21_sqrt(s21_POSINF), sqrt(s21_POSINF));
}
END_TEST

START_TEST(test_s21_log) {
  ck_assert_uint_eq(s21_log(i0), log(i0));
  ck_assert_uint_eq(s21_log(i1), log(i1));
  ck_assert_uint_eq(s21_log(i2), log(i2));
  ck_assert_uint_eq(s21_log(i3), log(i3));
  ck_assert_uint_eq(s21_log(i4), log(i4));
  ck_assert_uint_eq(s21_log(d1), log(d1));
  ck_assert_uint_eq(s21_log(d2), log(d2));
  ck_assert_uint_eq(s21_log(d3), log(d3));
  ck_assert_uint_eq(s21_log(d5), log(d5));
  ck_assert_uint_eq(s21_log(d9), log(d9));
  ck_assert_uint_eq(s21_log(s21_POSINF), log(s21_POSINF));
}
END_TEST

Suite *s21_math_suite(void) {
  Suite *suite;
  TCase *core;
  suite = suite_create("S21_math");
  core = tcase_create("Core");
  tcase_add_test(core, test_s21_abs);
  tcase_add_test(core, test_s21_fabs);
  tcase_add_test(core, test_s21_pow);
  tcase_add_test(core, test_s21_ceil);
  tcase_add_test(core, test_s21_floor);
  tcase_add_test(core, test_s21_fmod);
  tcase_add_test(core, test_s21_cos);
  tcase_add_test(core, test_s21_acos);
  tcase_add_test(core, test_s21_sin);
  tcase_add_test(core, test_s21_asin);
  tcase_add_test(core, test_s21_tan);
  tcase_add_test(core, test_s21_atan);
  tcase_add_test(core, test_s21_sqrt);
  tcase_add_test(core, test_s21_log);

  suite_add_tcase(suite, core);

  return (suite);
}

int main(void) {
  int failed = 0;
  Suite *suite;

  SRunner *runner;

  suite = s21_math_suite();
  runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
