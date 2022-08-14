#include "../utilits/s21_utility.h"
#include "s21_decimal_test.h"
#include "../s21_decimal.h"

START_TEST(short_div) {
    s21_decimal dec1;
    s21_decimal dec2;
    s21_decimal ans;
    init_decimal(&dec1);
    init_decimal(&dec2);
    dec1.bits[0] = 65536;
    dec2.bits[0] = 2;
    s21_decimal true_ans;
    init_decimal(&true_ans);
    true_ans.bits[0] = 32768;
    int status = s21_div(dec1, dec2, &ans);
    int true_status = 0;
    ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
    ck_assert_int_eq(status, true_status);
} END_TEST

START_TEST(basic_div) {
    s21_decimal dec1;
    s21_decimal dec2;
    s21_decimal ans;
    init_decimal(&dec1);
    init_decimal(&dec2);
    dec1.bits[0] = 9;
    dec1.bits[3] = 65536;
    dec2.bits[0] = 6;
    dec2.bits[3] = 65536;
    s21_decimal true_ans;
    init_decimal(&true_ans);
    true_ans.bits[0] = 15;
    true_ans.bits[3] = 65536;
    int status = s21_div(dec1, dec2, &ans);
    int true_status = 0;
    ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
    ck_assert_int_eq(status, true_status);
} END_TEST

START_TEST(basic_div_2) {
    s21_decimal dec1;
    s21_decimal dec2;
    s21_decimal ans;
    init_decimal(&dec1);
    init_decimal(&dec2);
    dec1.bits[0] = 14;
    dec1.bits[3] = 65536;
    dec2.bits[0] = 9;
    dec2.bits[3] = 65536;
    // 14/9 = 1.5555555555 5555555555 55555556
    // 00110010 01000011 01000001 00000100
    // 01100000 10101011 01011001 00001000
    // 11000011 10001110 00111000 11100100
    // 00000000 00011100 00000000 00000000
    s21_decimal true_ans;
    init_decimal(&true_ans);
    true_ans.bits[0] = 3280877796;
    true_ans.bits[1] = 1621842184;
    true_ans.bits[2] = 843268356;
    true_ans.bits[3] = 1835008;
    int status = s21_div(dec1, dec2, &ans);
    int true_status = 0;  // операция прошла успешно
    ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
    ck_assert_int_eq(status, true_status);
} END_TEST

START_TEST(basic_div_3) {
    s21_decimal dec1;
    s21_decimal dec2;
    s21_decimal ans;
    init_decimal(&dec1);
    init_decimal(&dec2);
    dec1.bits[0] = 14;
    dec1.bits[3] = 65536;
    dec2.bits[0] = 9;
    dec2.bits[3] = 65536 + MINUS_SIGN;
    // 14/(-9) = -1.5555555555 5555555555 55555556
    // 00110010 01000011 01000001 00000100
    // 01100000 10101011 01011001 00001000
    // 11000011 10001110 00111000 11100100
    // 00000000 00011100 00000000 00000000
    s21_decimal true_ans;
    init_decimal(&true_ans);
    true_ans.bits[0] = 3280877796;
    true_ans.bits[1] = 1621842184;
    true_ans.bits[2] = 843268356;
    true_ans.bits[3] = 1835008 + MINUS_SIGN;
    int status = s21_div(dec1, dec2, &ans);
    int true_status = 0;  // операция прошла успешно
    ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
    ck_assert_int_eq(status, true_status);
} END_TEST

START_TEST(div_by_zero) {
    s21_decimal dec1;
    s21_decimal dec2;
    s21_decimal ans;
    init_decimal(&dec1);
    init_decimal(&dec2);
    dec1.bits[0] = 2814903;
    dec1.bits[3] = 65536;
    dec2.bits[0] = 0;
    dec2.bits[3] = 65536 + MINUS_SIGN;
    int status = s21_div(dec1, dec2, &ans);
    int true_status = 3;  // не надо делить на ноль
    ck_assert_int_eq(status, true_status);
} END_TEST

START_TEST(div_zero) {
    s21_decimal dec1;
    s21_decimal dec2;
    s21_decimal ans;
    init_decimal(&dec1);
    init_decimal(&dec2);
    dec1.bits[0] = 0;
    dec1.bits[3] = 65536;
    dec2.bits[0] = 4578783;
    s21_decimal true_ans;
    init_decimal(&true_ans);
    true_ans.bits[0] = 0;
    true_ans.bits[1] = 0;
    true_ans.bits[2] = 0;
    true_ans.bits[3] = 0;
    int status = s21_div(dec1, dec2, &ans);
    int true_status = 0;  // операция прошла успешно
    ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
    ck_assert_int_eq(status, true_status);
} END_TEST

// START_TEST(result_too_big) {
//     s21_decimal dec1;
//     s21_decimal dec2;
//     s21_decimal ans;
//     init_decimal(&dec1);
//     init_decimal(&dec2);
//     dec1.bits[0] = 4294967294;
//     dec1.bits[1] = 4294967295;
//     dec1.bits[2] = 4294967295;
//     dec2.bits[0] = 1;
//     dec2.bits[3] = 1179648;

//     int status = s21_div(dec1, dec2, &ans);
//     print_binary_representation_std(ans);    
//     int true_status = 1;
//     ck_assert_int_eq(status, true_status);
// } END_TEST

START_TEST(result_too_small) {
    s21_decimal dec1;
    s21_decimal dec2;
    s21_decimal ans;
    init_decimal(&dec1);
    init_decimal(&dec2);
    dec2.bits[0] = 4294967294;
    dec2.bits[1] = 4294967295;
    dec2.bits[2] = 4294967295;
    dec1.bits[0] = 1;
    dec1.bits[3] = 1179648;

    int status = s21_div(dec1, dec2, &ans);
    int true_status = 2;
    ck_assert_int_eq(status, true_status);
} END_TEST

// нужны тесты на переполнение
Suite* div_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("s21_div");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, short_div);
    tcase_add_test(tc_core, basic_div);
    tcase_add_test(tc_core, basic_div_2);
    tcase_add_test(tc_core, basic_div_3);
    tcase_add_test(tc_core, div_by_zero);
    tcase_add_test(tc_core, div_zero);
    tcase_add_test(tc_core, result_too_small);
    // пока что не обрабатывала, нужно влезть в рескейл
    // tcase_add_test(tc_core, result_too_big);
    suite_add_tcase(s, tc_core);

    return s;
}
