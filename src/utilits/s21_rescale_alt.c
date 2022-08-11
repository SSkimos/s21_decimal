#include "s21_utility.h"

// рескейл на уровне альтернативных децималов
// лучше переделать, мне очень не нравится постоянный перегон
// из одной формы в другую
// сделать сразу рабочий и нормальный не получилось :)
int s21_rescale_alt(s21_decimal_alt *alt_value_1, \
s21_decimal_alt *alt_value_2) {
    s21_decimal_alt ten;
    s21_null_decimal_alt(&ten);
    ten.bits[1] = 1;
    ten.bits[3] = 1;
    int exp_dif;
    if (alt_value_1 -> exp > alt_value_2 -> exp) {
        exp_dif = alt_value_1 -> exp - alt_value_2 -> exp;
        for (int i = 0; i < exp_dif; i++)
            s21_mul_alt(*alt_value_2, ten, alt_value_2);
        alt_value_2 -> exp = alt_value_1 -> exp;
    } else 
    if (alt_value_2 -> exp > alt_value_1 -> exp) {
        exp_dif = alt_value_2 -> exp - alt_value_1 -> exp;
        for (int i = 0; i < exp_dif; i++)
            s21_mul_alt(*alt_value_1, ten, alt_value_1);
        alt_value_1 -> exp = alt_value_2 -> exp;
    }
}
