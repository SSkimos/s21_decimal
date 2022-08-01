#ifndef SRC_S21_ARITHMETICS_H_
#define SRC_S21_ARITHMETICS_H_
// #include "../utilits/s21_structures.h"
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

bool s21_get_bit_int(unsigned int num, int pos);
bool s21_right_shift(s21_decimal_alt *alt);
bool s21_get_sign_std(s21_decimal dec);
int s21_get_exp_std(s21_decimal dec);
void print_binary_representation_std(s21_decimal std);
void print_binary_representation_alt(s21_decimal_alt alt);
void s21_null_decimal(s21_decimal *std);
void s21_null_decimal_alt(s21_decimal_alt *alt);
s21_decimal_alt s21_convert_std_to_alt(s21_decimal std);
s21_decimal s21_convert_alt_to_std(s21_decimal_alt alt);
int s21_sub_alt(s21_decimal_alt alt_value_1, \
s21_decimal_alt alt_value_2, s21_decimal_alt *alt_result);
int s21_add_alt(s21_decimal_alt alt_value_1, \
s21_decimal_alt alt_value_2, s21_decimal_alt *alt_result);
int s21_mul_alt(s21_decimal_alt alt_value_1, \
s21_decimal_alt alt_value_2, s21_decimal_alt *alt_result);
#endif