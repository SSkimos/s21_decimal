#include "../utilits/s21_utility.h"
#include "s21_decimal_test.h"
#include "../s21_decimal.h"

START_TEST(from_float_to_decimal_simple) {
    s21_decimal decimal;
    init_decimal(&decimal);
    float number = 100.5;
    convertation_result result = s21_from_float_to_decimal(number, &decimal);
    ck_assert_int_eq(result, 0);
} END_TEST

START_TEST(float_eq_float) {
    s21_decimal decimal;
    init_decimal(&decimal);
    float A = 100.5;
    float B = 0.0;
    convertation_result status = s21_from_float_to_decimal(A, &decimal);
    s21_from_decimal_to_float(decimal, &B);
    ck_assert_float_eq(A, B);
} END_TEST

START_TEST(float_eq_float_minus) {
    s21_decimal decimal;
    init_decimal(&decimal);
    float A = -100.5;
    float B = 0.0;
    convertation_result status = s21_from_float_to_decimal(A, &decimal);
    s21_from_decimal_to_float(decimal, &B);
    ck_assert_float_eq(A, B);
} END_TEST

START_TEST(float_eq_float_hard_test) {
    s21_decimal decimal;
    init_decimal(&decimal);
    float A = -1000.201;
    float B = 0.0;
    convertation_result status = s21_from_float_to_decimal(A, &decimal);
    s21_from_decimal_to_float(decimal, &B);
    ck_assert_float_eq(A, B);
}

START_TEST(big_float_eq_big_float1) {
        s21_decimal decimal;
        init_decimal(&decimal);
        float A = 4294967295.000000;
        float B = 4294967295.000000;
        float C = 0.0;
        operation_result res = s21_from_float_to_decimal(A, &decimal);
        s21_from_decimal_to_float(decimal, &C);
        ck_assert_double_eq(B, C);
}

Suite* conversion_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("conversion");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, from_float_to_decimal_simple);
    tcase_add_test(tc_core, float_eq_float);
    tcase_add_test(tc_core, float_eq_float_minus);
    tcase_add_test(tc_core, float_eq_float_hard_test);
//    tcase_add_test(tc_core, big_float_eq_big_float1);

    suite_add_tcase(s, tc_core);

    return s;
}
