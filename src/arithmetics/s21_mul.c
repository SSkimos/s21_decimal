#include "../utilits/s21_utility.h"
#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int return_code = 0;
    s21_decimal_alt alt_value_1 = s21_convert_std_to_alt(value_1);
    s21_decimal_alt alt_value_2 = s21_convert_std_to_alt(value_2);
    s21_decimal_alt alt_result;
    s21_null_decimal_alt(&alt_result);
    s21_mul_alt(alt_value_1, alt_value_2, &alt_result);
    *result = s21_convert_alt_to_std(alt_result);
    return return_code;
}

