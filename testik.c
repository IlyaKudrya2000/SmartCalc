#include <check.h>

#include "polka.h"

START_TEST(test1) {
  char str[255] = "(tan(-2^4)^2)*5/3+(ln(sqrt(+25))-(sin(-4)))";
  double ress = 0;
  int flag = preRead(str, &ress);
  double res_orig = 1.0032683253667286;
  ck_assert_int_eq(flag, 0);
  ck_assert_double_eq_tol(res_orig, ress, 1e-07);
}
END_TEST

START_TEST(test2) {
  char str[255] = "(asin(1)-(sin(-1)))";
  double ress = 0;
  int flag = preRead(str, &ress);
  double res_orig = 2.41226731;
  ck_assert_int_eq(flag, 0);
  ck_assert_double_eq_tol(res_orig, ress, 1e-07);
}
END_TEST

START_TEST(test3) {
  char str[255] = "(acos(0)-(sin(1)))";
  double ress = 0;
  int flag = preRead(str, &ress);
  double res_orig = 0.72932534;
  ck_assert_int_eq(flag, 0);
  ck_assert_double_eq_tol(res_orig, ress, 1e-07);
}
END_TEST

START_TEST(test4) {
  char str[255] = "asin(1)-atan(1)+acos(1)";
  double ress = 0;

  int flag = preRead(str, &ress);
  double res_orig = 0.78539816;
  ck_assert_int_eq(flag, 0);
  ck_assert_double_eq_tol(res_orig, ress, 1e-07);
}
END_TEST

START_TEST(test5) {
  char str[255] = "sin(0.5)+16-3^8";
  double ress = 0;
  double x = 0.5;
  int flag = preRead(str, &ress);
  double res_orig = -6544.52057446;
  ck_assert_int_eq(flag, 0);
  ck_assert_double_eq_tol(res_orig, ress, 1e-07);
}
END_TEST

START_TEST(test6) {
  char str[255] = "-(-8*9.0)";
  double ress = 0;
  int flag = preRead(str, &ress);
  double res_orig = 72.00000000;
  ck_assert_int_eq(flag, 0);
  ck_assert_double_eq_tol(res_orig, ress, 1e-07);
}
END_TEST

START_TEST(test7) {
  char str[255] = "(-2)";
  double ress = 0;
  int flag = preRead(str, &ress);
  double res_orig = -2.0000000000000;
  ck_assert_int_eq(flag, 0);
  ck_assert_double_eq_tol(res_orig, ress, 1e-07);
}
END_TEST

START_TEST(test8) {
  char str[255] = "+(2*1)-(sin(1))";
  double ress = 0;

  int flag = preRead(str, &ress);
  double res_orig = 1.15852902;
  ck_assert_int_eq(flag, 0);
  ck_assert_double_eq_tol(res_orig, ress, 1e-07);
}
END_TEST

START_TEST(test9) {
  char str[255] = "-2.54)*((((2.54^2";
  double ress = 0;

  int flag = preRead(str, &ress);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test10) {
  char str[255] = "sqrt(100)";
  double ress = 0;

  int flag = preRead(str, &ress);
  double res_orig = 10.00000000;
  ck_assert_int_eq(flag, 0);
  ck_assert_double_eq_tol(res_orig, ress, 1e-07);
}
END_TEST

START_TEST(test11) {
  char str[255] = "sin16+";
  double ress = 0;

  int flag = preRead(str, &ress);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test12) {
  char str[255] = "3.4.5+++82.548";
  double ress = 0;

  int flag = preRead(str, &ress);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test13) {
  char str[255] = "*90-*hfjdk";
  double ress = 0;

  int flag = preRead(str, &ress);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test14) {
  char str[255] = "tsitsxzdfghjsfgjt2.54)";
  double ress = 0;

  int flag = preRead(str, &ress);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test15) {
  char str[255] = "())";
  double ress = 0;

  int flag = preRead(str, &ress);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test16) {
  char str[255] = "53mod2";
  double ress = 0;
  int flag = preRead(str, &ress);
  double res_orig = 1.00000000;
  ck_assert_int_eq(flag, 0);
  ck_assert_double_eq_tol(res_orig, ress, 1e-07);
}
END_TEST

START_TEST(test17) {
  char str[255] = "cos(0.5)+log(53)";
  double ress = 0;
  int flag = preRead(str, &ress);
  double res_orig = 2.60185843;
  ck_assert_int_eq(flag, 0);
  ck_assert_double_eq_tol(res_orig, ress, 1e-07);
}
END_TEST

START_TEST(test18) {
  char str[255] = "())+";
  double ress = 0;
  int flag = preRead(str, &ress);
  ck_assert_int_eq(flag, 1);
}
END_TEST

END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test1);
  tcase_add_test(tc1_1, test2);
  tcase_add_test(tc1_1, test3);
  tcase_add_test(tc1_1, test4);
  tcase_add_test(tc1_1, test5);
  tcase_add_test(tc1_1, test6);
  tcase_add_test(tc1_1, test7);
  tcase_add_test(tc1_1, test8);
  tcase_add_test(tc1_1, test9);
  tcase_add_test(tc1_1, test10);
  tcase_add_test(tc1_1, test11);
  tcase_add_test(tc1_1, test12);
  tcase_add_test(tc1_1, test13);
  tcase_add_test(tc1_1, test14);
  tcase_add_test(tc1_1, test15);
  tcase_add_test(tc1_1, test16);
  tcase_add_test(tc1_1, test17);
  tcase_add_test(tc1_1, test18);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}