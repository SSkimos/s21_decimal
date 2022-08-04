#include "s21_utility.h"

// побитовое перемножение альтернативных децималов
// принимает два альтернативных децимала
// совсем не работает с переполнением
int s21_mul_alt(s21_decimal_alt alt_value_1, \
s21_decimal_alt alt_value_2, s21_decimal_alt *alt_result) {
    int exp1 = alt_value_1.exp;
    int exp2 = alt_value_2.exp;
    alt_value_1.exp = 0;
    alt_value_2.exp = 0;
    int sign1 = alt_value_1.sign;
    int sign2 = alt_value_2.sign;
    alt_value_1.sign = 0;
    alt_value_2.sign = 0;
    for (int i = 0; i < 96; i++) {
        if (alt_value_2.bits[i] == 1)
            s21_add_alt(*alt_result, alt_value_1, alt_result);
        s21_right_shift(&alt_value_1);
    }
    alt_result -> exp = exp1 + exp2;
    // if (alt_result.exp > 26)
    alt_result -> sign = sign1 ^ sign2;
}
