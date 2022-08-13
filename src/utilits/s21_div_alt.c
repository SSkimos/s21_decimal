#include "s21_utility.h"

int s21_div_alt(s21_decimal_alt alt_value_1, \
s21_decimal_alt alt_value_2, s21_decimal_alt *alt_result) {
    int return_code = 0;
    alt_result -> sign = alt_value_1.sign ^ alt_value_2.sign;
    alt_value_1.sign = 0;
    alt_value_2.sign = 0;
    ////////////////////////////////////
    // пока что совсем не думаю о положении точки
    ////////////////////////////////////
    // очень важное значение:
    // нужно для того чтобы я ненароком не уменьшила знаменатель
    int denominator_left_bit = last_bit(alt_value_2);
    align(&alt_value_1, &alt_value_2);
    for (int i = 0; i < 97; i++) {
        if (compare_bits(alt_value_1, alt_value_2)) {
            s21_sub_alt(alt_value_1, alt_value_2, &alt_value_1);
            alt_result -> bits[0] = 1;
        }
        if (is_null(alt_value_1) && \
        last_bit(alt_value_2) == denominator_left_bit)
            break;
        if (last_bit(alt_value_2) > denominator_left_bit) {
            s21_right_shift(&alt_value_2);
        } else {
            s21_left_shift(&alt_value_1);
        }
        s21_left_shift(alt_result);
    }
    if (last_bit(*alt_result) > 95) {
        int mod = div_by_ten(alt_result);
        s21_bank_rounding(alt_result, mod);
    }
    return return_code;
}
