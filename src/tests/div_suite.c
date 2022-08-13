#include "../utilits/s21_utility.h"
#include "s21_decimal_test.h"
#include "../s21_decimal.h"

START_TEST(basic_div) {
    s21_decimal dec1;
    s21_decimal dec2;
    s21_decimal ans;
    init_decimal(&dec1);
    init_decimal(&dec2);
    dec1.bits[0] = 3096;
    dec2.bits[0] = 4;

    s21_decimal true_ans;
    init_decimal(&true_ans);
    true_ans.bits[0] = 774;

    int status = s21_div(dec1, dec2, &ans);
    int true_status = 0;  // операция прошла успешно
    ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
    ck_assert_int_eq(status, true_status);
} END_TEST

START_TEST(basic_div_2) {
    s21_decimal dec1;
    s21_decimal dec2;
    s21_decimal ans;
    init_decimal(&dec1);
    init_decimal(&dec2);
    dec1.bits[0] = 1732144;
    dec1.bits[3] = MINUS_SIGN;

    dec2.bits[0] = 4;

    s21_decimal true_ans;
    init_decimal(&true_ans);
    true_ans.bits[0] = 433036;
    true_ans.bits[3] = MINUS_SIGN;

    int status = s21_div(dec1, dec2, &ans);
    int true_status = 0;  // операция прошла успешно
    ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
    ck_assert_int_eq(status, true_status);
} END_TEST

Suite* div_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("s21_div");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, basic_div);
    tcase_add_test(tc_core, basic_div_2);
    suite_add_tcase(s, tc_core);

    return s;
}
