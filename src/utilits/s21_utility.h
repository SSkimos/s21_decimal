#ifndef UTILITS_S21_STRUCTURES_H_
#define UTILITS_S21_STRUCTURES_H_

typedef struct {
    unsigned int bits[4];
} s21_decimal;

#include <stdbool.h>
typedef struct {
    bool bits[96];
    bool sign;
    int exp;
} s21_decimal_alt;

typedef enum {
    OPERATION_OK = 0,
    NUMBER_TOO_BIG,
    NUMBER_TOO_SMALL,
    DIVISION_BY_ZERO
} operation_result;

bool s21_get_bit_int(unsigned int num, int pos);
bool s21_right_shift(s21_decimal_alt *alt);
bool s21_left_shift(s21_decimal_alt *alt);
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
int s21_rescale(s21_decimal *value_1, s21_decimal *value_2);
int s21_rescale_alt(s21_decimal_alt *alt_value_1, \
s21_decimal_alt *alt_value_2);

void print_binary_representation_std_s(s21_decimal std);
void print_binary_representation_alt_s(s21_decimal_alt alt);

#endif