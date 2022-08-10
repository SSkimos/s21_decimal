#include "../utilits/s21_utility.h"
#include "s21_decimal_test.h"
#include "../s21_decimal.h"

START_TEST(basic_mul) {
    s21_decimal dec1;
    s21_decimal dec2;
    s21_decimal ans;
    init_decimal(&dec1);
    init_decimal(&dec2);
    dec1.bits[0] = 1256;
    dec2.bits[0] = 1000;

    s21_decimal true_ans;
    init_decimal(&true_ans);
    true_ans.bits[0] = 1256000;

    int status = s21_mul(dec1, dec2, &ans);
    int true_status = 0;  // операция прошла успешно

    ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
    ck_assert_int_eq(status, true_status);
} END_TEST

START_TEST(basic_mul_2) {
    s21_decimal dec1;
    s21_decimal dec2;
    s21_decimal ans;
    init_decimal(&dec1);
    init_decimal(&dec2);
    // 125236476 * (-364287140) = -45622037665718640
    //          10100010 00010101 00000000
    // 01100100 11111110 10100001 01110000
    dec1.bits[0] = 125236476;
    dec1.bits[3] = 393216;  // точка после шестого знака

    dec2.bits[0] = 364287140;
    // отрицательное число и точка после третьего знака
    dec2.bits[3] = 2147483648 + 196608;

    s21_decimal true_ans;
    init_decimal(&true_ans);
    true_ans.bits[0] = 1694409072;
    true_ans.bits[1] = 10622208;
    true_ans.bits[3] = 589824 + 2147483648;
    // отрицательное число с точкой после девятого знака

    int status = s21_mul(dec1, dec2, &ans);
    int true_status = 0;  // операция прошла успешно

    ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
    ck_assert_int_eq(status, true_status);
} END_TEST

Suite* mul_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("s21_mul");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, basic_mul);
    tcase_add_test(tc_core, basic_mul_2);
    suite_add_tcase(s, tc_core);

    return s;
}
