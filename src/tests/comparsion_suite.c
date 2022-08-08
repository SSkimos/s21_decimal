#include "../utilits/s21_utility.h"
#include "s21_decimal_test.h"
#include "../s21_decimal.h"
#include <math.h>

START_TEST(is_equal_simple) {
    s21_decimal decimal;
    s21_decimal second_decimal;
    init_decimal(&decimal);
    init_decimal(&second_decimal);
    int A = 5123;
    convertation_result status = s21_from_int_to_decimal(A, &decimal);
    convertation_result second_status = s21_from_int_to_decimal(A, &second_decimal);
    ck_assert_int_eq(1, s21_is_equal(decimal, second_decimal));
} END_TEST

START_TEST(is_equal_0_decimal) {
    s21_decimal decimal;
    s21_decimal second_decimal;
    init_decimal(&decimal);
    init_decimal(&second_decimal);
    int A = 5123;
    convertation_result status = s21_from_int_to_decimal(A, &decimal);
    ck_assert_int_eq(0, s21_is_equal(decimal, second_decimal));
} END_TEST

START_TEST(is_not_equal) {
    s21_decimal decimal;
    s21_decimal second_decimal;
    init_decimal(&decimal);
    init_decimal(&second_decimal);
    int A = 5123;
    int B = 5122;
    convertation_result status = s21_from_int_to_decimal(A, &decimal);
    convertation_result second_status = s21_from_int_to_decimal(B, &second_decimal);
    ck_assert_int_eq(1, s21_is_not_equal(decimal, second_decimal));

} END_TEST

START_TEST(is_not_equal_SIGN) {
    s21_decimal decimal;
    s21_decimal second_decimal;
    init_decimal(&decimal);
    init_decimal(&second_decimal);
    int A = -5123;
    int B = 5123;
    convertation_result status = s21_from_int_to_decimal(A, &decimal);
    convertation_result second_status = s21_from_int_to_decimal(B, &second_decimal);
    ck_assert_int_eq(1, s21_is_not_equal(decimal, second_decimal));
} END_TEST

START_TEST(is_greater_stand) {
    s21_decimal decimal;
    s21_decimal second_decimal;
    init_decimal(&decimal);
    init_decimal(&second_decimal);
    int A = -5123;
    int B = 5123;
    convertation_result status = s21_from_int_to_decimal(A, &decimal);
    convertation_result second_status = s21_from_int_to_decimal(B, &second_decimal);
    ck_assert_int_eq(1, s21_is_greater(second_decimal, decimal));
} END_TEST

START_TEST(is_greater_0) {
    s21_decimal decimal;
    s21_decimal second_decimal;
    init_decimal(&decimal);
    init_decimal(&second_decimal);
    int A = 0;
    int B = 5123;
    convertation_result status = s21_from_int_to_decimal(A, &decimal);
    convertation_result second_status = s21_from_int_to_decimal(B, &second_decimal);
    ck_assert_int_eq(0, s21_is_greater(decimal, second_decimal));
} END_TEST

START_TEST(is_less_ne) {
    s21_decimal decimal;
    s21_decimal second_decimal;
    init_decimal(&decimal);
    init_decimal(&second_decimal);
    int A = 5124;
    int B = 5123;
    convertation_result status = s21_from_int_to_decimal(A, &decimal);
    convertation_result second_status = s21_from_int_to_decimal(B, &second_decimal);
    ck_assert_int_eq(0, s21_is_less(decimal, second_decimal));
} END_TEST

START_TEST(is_less_equal) {
    s21_decimal decimal;
    s21_decimal second_decimal;
    init_decimal(&decimal);
    init_decimal(&second_decimal);
    int B = 5123;
    int A = B;
    convertation_result status = s21_from_int_to_decimal(A, &decimal);
    convertation_result second_status = s21_from_int_to_decimal(B, &second_decimal);
    ck_assert_int_eq(0, s21_is_less(decimal, second_decimal));
} END_TEST

START_TEST(is_less_Classic) {
    s21_decimal decimal;
    s21_decimal second_decimal;
    init_decimal(&decimal);
    init_decimal(&second_decimal);
    int A = 0;
    int B = 5123;
    convertation_result status = s21_from_int_to_decimal(A, &decimal);
    convertation_result second_status = s21_from_int_to_decimal(B, &second_decimal);
    ck_assert_int_eq(1, s21_is_less(decimal, second_decimal));
} END_TEST

START_TEST(is_less_or_equal_Classic) {
    s21_decimal decimal;
    s21_decimal second_decimal;
    init_decimal(&decimal);
    init_decimal(&second_decimal);
    int B = 5123;
    int A = B;
    convertation_result status = s21_from_int_to_decimal(A, &decimal);
    convertation_result second_status = s21_from_int_to_decimal(B, &second_decimal);
    ck_assert_int_eq(1, s21_is_less_or_equal(decimal, second_decimal));
} END_TEST

START_TEST(is_less_or_equal_nan) {
    s21_decimal decimal;
    s21_decimal second_decimal;
    init_decimal(&decimal);
    init_decimal(&second_decimal);
    int B = 5123;
    int A = NAN;
    convertation_result status = s21_from_int_to_decimal(A, &decimal);
    convertation_result second_status = s21_from_int_to_decimal(B, &second_decimal);
    ck_assert_int_eq(1, s21_is_less_or_equal(decimal, second_decimal));
} END_TEST

Suite* comparsion_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("equal");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, is_equal_simple);
    tcase_add_test(tc_core, is_equal_0_decimal);
    tcase_add_test(tc_core, is_not_equal);
    tcase_add_test(tc_core, is_not_equal_SIGN);
    tcase_add_test(tc_core, is_greater_stand);
    tcase_add_test(tc_core, is_greater_0);
    tcase_add_test(tc_core, is_less_Classic);
    tcase_add_test(tc_core, is_less_equal);
    tcase_add_test(tc_core, is_less_or_equal_Classic);
    tcase_add_test(tc_core, is_less_or_equal_nan);
    suite_add_tcase(s, tc_core);

    return s;
}
