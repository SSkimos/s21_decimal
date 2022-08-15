#ifndef SRC_UTILITS_S21_UTILITY_H_
#define SRC_UTILITS_S21_UTILITY_H_
#include "../s21_decimal.h"

bool s21_get_bit_int(unsigned int num, int pos);
void s21_right_shift(s21_decimal_alt *alt);
void s21_left_shift(s21_decimal_alt *alt);
bool s21_get_sign_std(s21_decimal dec);
int s21_get_exp_std(s21_decimal dec);
void s21_null_decimal_alt(s21_decimal_alt *alt);
s21_decimal_alt s21_convert_std_to_alt(s21_decimal std);
s21_decimal s21_convert_alt_to_std(s21_decimal_alt alt);
int s21_sub_alt(s21_decimal_alt alt_value_1, s21_decimal_alt alt_value_2, s21_decimal_alt *alt_result);
int s21_add_alt(s21_decimal_alt alt_value_1, s21_decimal_alt alt_value_2, s21_decimal_alt *alt_result);
int s21_mul_alt(s21_decimal_alt alt_value_1, s21_decimal_alt alt_value_2, s21_decimal_alt *alt_result);
void s21_rescale(s21_decimal *value_1, s21_decimal *value_2);
void s21_rescale_alt(s21_decimal_alt *alt_value_1, s21_decimal_alt *alt_value_2);
void s21_rescale_alt_to_smaller(s21_decimal_alt *alt_value_1, s21_decimal_alt *alt_value_2);
void init_decimal(s21_decimal *decimal);
int div_by_ten(s21_decimal_alt *alt);
bool compare_bits(s21_decimal_alt alt1, s21_decimal_alt alt2);
bool is_null(s21_decimal_alt alt);
int last_bit(s21_decimal_alt alt);
void s21_bank_rounding(s21_decimal_alt *alt, int mod);
int s21_div_alt(s21_decimal_alt alt_value_1, s21_decimal_alt alt_value_2, s21_decimal_alt *alt_result);
void align(s21_decimal_alt *alt1, s21_decimal_alt *alt2);
void s21_rescale_alt_to_zero(s21_decimal_alt *alt_value_1, s21_decimal_alt *alt_value_2);
s21_decimal_alt div_with_modulo(s21_decimal_alt alt_value_1, s21_decimal_alt alt_value_2, \
s21_decimal_alt *alt_result);

void print_binary_representation_std(s21_decimal std);
void print_binary_representation_alt(s21_decimal_alt alt);
void print_binary_representation_std_s(s21_decimal std);
void print_binary_representation_alt_s(s21_decimal_alt alt);

s21_decimal_alt s21_convert_int_to_alt(unsigned long int number);
s21_decimal_alt s21_revert_alt_decimal(s21_decimal_alt alt, int i);
s21_decimal s21_convert_int_to_std(unsigned long int number);

#endif  // SRC_UTILITS_S21_UTILITY_H_
