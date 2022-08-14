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

START_TEST(from_float_to_decimal_null) {
    s21_decimal decimal;
    init_decimal(&decimal);
    float n = (void*)0;
    convertation_result result = s21_from_float_to_decimal(n, &decimal);
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

START_TEST(float_eq_0) {
    s21_decimal decimal;
    init_decimal(&decimal);
    float A = 0.0;
    float B = 1.0;
    convertation_result status = s21_from_float_to_decimal(A, &decimal);
    s21_from_decimal_to_float(decimal, &B);
    ck_assert_float_eq(A, B);
} END_TEST

START_TEST(int_eq_int) {
    s21_decimal decimal;
    init_decimal(&decimal);
    int A = 0;
    int B = 1;
    convertation_result status = s21_from_int_to_decimal(A, &decimal);
    s21_from_decimal_to_int(decimal, &B);
    ck_assert_int_eq(A, B);
} END_TEST

START_TEST(int_eq_Bigint) {
    s21_decimal decimal;
    init_decimal(&decimal);
    int A = 112312312;
    int B = 1;
    convertation_result status = s21_from_int_to_decimal(A, &decimal);
    s21_from_decimal_to_int(decimal, &B);
    ck_assert_int_eq(A, B);
} END_TEST

Suite* conversion_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("conversion");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, from_float_to_decimal_simple);
    tcase_add_test(tc_core, float_eq_float);
    tcase_add_test(tc_core, float_eq_float_minus);
    tcase_add_test(tc_core, float_eq_0);
    tcase_add_test(tc_core, int_eq_int);
    suite_add_tcase(s, tc_core);

    return s;
}
