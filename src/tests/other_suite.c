#include "../utilits/s21_utility.h"
#include "s21_decimal_test.h"
#include "../s21_decimal.h"

START_TEST(s21_negate_simple) {
        s21_decimal decimal;
        s21_decimal result;
        init_decimal(&decimal);
        init_decimal(&result);
        int A = 100;
        int B = -100;
        operation_result res = s21_negate(decimal, &result);
        s21_from_decimal_to_int(result, &A);
        ck_assert_int_eq(A, B);
} END_TEST

START_TEST(s21_negate_ok) {
        s21_decimal decimal;
        s21_decimal result;
        init_decimal(&decimal);
        init_decimal(&result);
        int A = 133414412;
        int B = -A;
        operation_result res = s21_negate(decimal, &result);
        s21_from_decimal_to_int(result, &A);
        ck_assert_int_eq(A, B);
} END_TEST

START_TEST(s21_negate_0) {
        s21_decimal decimal;
        s21_decimal result;
        init_decimal(&decimal);
        init_decimal(&result);
        int A = 0;
        int B = -A;
        operation_result res = s21_negate(decimal, &result);
        s21_from_decimal_to_int(result, &A);
        ck_assert_int_eq(A, B);
} END_TEST

Suite* other_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("other");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_negate_simple);
    tcase_add_test(tc_core, s21_negate_ok);
    tcase_add_test(tc_core, s21_negate_0);
    suite_add_tcase(s, tc_core);

    return s;
}

