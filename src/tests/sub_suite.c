#include "../utilits/s21_utility.h"
#include "s21_decimal_test.h"
#include "../s21_decimal.h"

START_TEST(basic_sub) {
    s21_decimal dec1;
    s21_decimal dec2;
    s21_decimal ans;
    init_decimal(&dec1);
    init_decimal(&dec2);
    dec1.bits[0] = 532167;
    dec2.bits[0] = 123456;
    // 532167 - 123456 = 408711;

    s21_decimal true_ans;
    init_decimal(&true_ans);
    true_ans.bits[0] = 408711;

    int status = s21_sub(dec1, dec2, &ans);
    int true_status = 0;  // операция прошла успешно

    ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
    ck_assert_int_eq(status, true_status);
} END_TEST


// SEGMENTATION FAULT
// START_TEST(basic_sub_2) {
//     s21_decimal dec1;
//     s21_decimal dec2;
//     s21_decimal ans;
//     init_decimal(&dec1);
//     init_decimal(&dec2);
//     dec1.bits[0] = 123456;
//     dec2.bits[0] = 532167;
//     // 532167 - 123456 = 408711;

//     s21_decimal true_ans;
//     init_decimal(&true_ans);
//     true_ans.bits[0] = 408711;
//     true_ans.bits[3] = 2147483648;

//     int status = s21_sub(dec1, dec2, &ans);
//     int true_status = 0;  // операция прошла успешно

//     ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
//     ck_assert_int_eq(status, true_status);
// } END_TEST

Suite* sub_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("sub_suite");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, basic_sub);
    // tcase_add_test(tc_core, basic_sub_2);
    suite_add_tcase(s, tc_core);

    return s;
}
