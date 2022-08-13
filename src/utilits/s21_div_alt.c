#include "s21_utility.h"

int s21_div_alt(s21_decimal_alt alt_value_1, \
s21_decimal_alt alt_value_2, s21_decimal_alt *alt_result) {
    int return_code = 0;
    alt_result -> sign = alt_value_1.sign ^ alt_value_2.sign;
    alt_value_1.sign = 0;
    alt_value_2.sign = 0;
    s21_rescale_alt_to_zero(&alt_value_1, &alt_value_2);
    //  s21_decimal_alt result;
    //  s21_decimal_alt res = div_with_modulo(alt_value_1, alt_value_2, &result);
    return return_code;
}

s21_decimal_alt div_with_modulo(s21_decimal_alt alt_value_1, \
s21_decimal_alt alt_value_2, s21_decimal_alt *alt_result) {
    int denominator_left_bit = last_bit(alt_value_2);
    s21_decimal_alt modulo;
    s21_null_decimal_alt(&modulo);
    s21_null_decimal_alt(alt_result);
    if (compare_bits(alt_value_1, alt_value_2))
        align(&alt_value_1, &alt_value_2);
    for (int i = 0; i < 191; i++) {
        if (compare_bits(alt_value_1, alt_value_2)) {
            s21_sub_alt(alt_value_1, alt_value_2, &alt_value_1);
            alt_result -> bits[0] = 1;
        }
        if (last_bit(alt_value_2) == denominator_left_bit)
            break;
        if (last_bit(alt_value_2) > denominator_left_bit)
            s21_right_shift(&alt_value_2);
        s21_left_shift(alt_result);
    }
    return alt_value_1;
}

