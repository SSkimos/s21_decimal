#include "s21_utility.h"
#include "../s21_decimal.h"

// деление числа на 10
// возращает остаток от деления числа на 10
int div_by_ten(s21_decimal_alt *alt) {
    s21_decimal_alt result;
    s21_null_decimal_alt(&result);
    // возможно, эта конструкция не нужна и есть решение получше
    int exp = alt -> exp;
    int sign = alt -> sign;
    result.sign = 0;
    result.exp = 0;
    s21_decimal_alt ten;
    s21_null_decimal_alt(&ten);
    ten.bits[1] = 1;
    ten.bits[3] = 1;
    while (compare_bits(*alt, ten))
        s21_left_shift(&ten);
    if (ten.bits[1] == 0)
        s21_right_shift(&ten);
    for (int i = 0; i < 191; i++) {
        if (compare_bits(*alt, ten)) {
            s21_sub_alt(*alt, ten, alt);
            result.bits[0] = 1;
        }
        if (ten.bits[1] == 1)
            break;
        s21_right_shift(&ten);
        s21_left_shift(&result);
    }
    int res = s21_convert_alt_to_std(*alt).bits[0];
    *alt = result;
    // возможно, эта конструкция не нужна и есть решение получше
    alt -> exp = exp - 1;
    alt -> sign = sign;
    return res;
}

void s21_bank_rounding(s21_decimal_alt *alt, int mod) {
    if ((mod == 5 && alt -> bits[0]) || mod > 5) {
        s21_decimal_alt one;
        s21_null_decimal_alt(&one);
        one.bits[0] = 1;
        one.exp = alt -> exp;
        one.sign = alt -> sign;
        s21_add_alt(*alt, one, alt);
        if (last_bit(*alt) > 95) {
            s21_sub_alt(*alt, one, alt);
            mod = div_by_ten(alt);
            s21_bank_rounding(alt, mod);
        }
    }
}
