#include "s21_utility.h"

// рескейл на уровне альтернативных децималов
// лучше переделать, мне очень не нравится постоянный перегон
// из одной формы в другую
// сделать сразу рабочий и нормальный не получилось :)
int s21_rescale_alt(s21_decimal_alt *alt_value_1, \
s21_decimal_alt *alt_value_2) {
    s21_decimal ten;
    s21_null_decimal(&ten);
    ten.bits[0] = 10;
    int exp_dif;
    s21_decimal value_1 = s21_convert_alt_to_std(*alt_value_1);
    s21_decimal value_2 = s21_convert_alt_to_std(*alt_value_2);
    if (alt_value_1 -> exp > alt_value_2 -> exp) {
        exp_dif = alt_value_1 -> exp - alt_value_2 -> exp;
        for (int i = 0; i < exp_dif; i++) {
            s21_mul(value_2, ten, &value_2);
            *alt_value_2 = s21_convert_std_to_alt(value_2);
        }
        alt_value_2 -> exp = alt_value_1 -> exp;
    } else if (alt_value_2 -> exp > alt_value_1 -> exp) {
        exp_dif = alt_value_2 -> exp - alt_value_1 -> exp;
        for (int i = 0; i < exp_dif; i++) {
            s21_mul(value_1, ten, &value_1);
            *alt_value_1 = s21_convert_std_to_alt(value_1);
        }
        alt_value_1 -> exp = alt_value_2 -> exp;
    }
}
