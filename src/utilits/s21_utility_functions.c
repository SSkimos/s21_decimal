#include "s21_utility.h"
#include "../s21_decimal.h"
#include <stdio.h>

bool s21_get_bit_int(unsigned int num, int pos) {
    return (num >> pos) & 1;
}

// сдвиг вправо для альтернативного децимала
bool s21_right_shift(s21_decimal_alt *alt) {
    bool return_code = 0;
    if (alt -> bits[0] == 1)
        return_code = 1;
    // число было нечетным
    for (int i = 0; i < 191; i++)
        alt -> bits[i] = alt -> bits[i + 1];
    alt -> bits[191] = 0;
    return return_code;
}

// сдвиг влево для альтернативного децимала
// нужно при умножении
bool s21_left_shift(s21_decimal_alt *alt) {
    bool return_code = 0;
    // if (alt -> bits[191] == 1) {
    //     return_code = 1;
    // } else {
    for (int i = 191; i > 0; i--)
        alt -> bits[i] = alt -> bits[i - 1];
    alt -> bits[0] = 0;
    // }
    return return_code;
}

bool s21_get_sign_std(s21_decimal dec) {
    return s21_get_bit_int(dec.bits[3], 31);
}

int s21_get_exp_std(s21_decimal dec) {
    return (dec.bits[3] % 2147483648) >> 16;
}

void s21_null_decimal(s21_decimal *std) {
    for (int i = 0; i < 4; i++)
        std -> bits[i] = 0;
}

void s21_null_decimal_alt(s21_decimal_alt *alt) {
    alt -> sign = 0;
    alt -> exp = 0;
    for (int i = 0; i < 192; i++)
        alt -> bits[i] = 0;
}

// простейший рескейл. нужно будет разбить на две функции,
// подключить округление при переполнении
// и выдачу ошибки при совсем переполнении
int s21_rescale(s21_decimal *value_1, s21_decimal *value_2) {
    s21_decimal_alt alt_value_1 = s21_convert_std_to_alt(*value_1);
    s21_decimal_alt alt_value_2 = s21_convert_std_to_alt(*value_2);
    s21_rescale_alt(&alt_value_1, &alt_value_2);
    *value_1 = s21_convert_alt_to_std(alt_value_1);
    *value_2 = s21_convert_alt_to_std(alt_value_2);
}

void init_decimal(s21_decimal *decimal) {
    for (int i = 0; i < 4; i++) {
        decimal->bits[i] = 0;
    }
}

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
        else
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

// сравнение битов первого и второго альтернативного децимала
// не учитывает экспоненту
// возвращает 1, если первое число больше или равно второму
// 0 если второе число больше первого
bool compare_bits(s21_decimal_alt alt1, s21_decimal_alt alt2) {
    int i = 191;
    while (alt1.bits[i] == alt2.bits[i] && i >= 0)
        i--;
    return i == -1 ? 1 : alt1.bits[i];
}

// равен ли альтернативный децимал 0
bool is_null(s21_decimal_alt alt) {
    bool result = 0;
    for (int i = 0; i < 192; i++)
        result += alt.bits[i];
    return !result;
}

// где находится самый левый единичный бит?
int last_bit(s21_decimal_alt alt) {
    int i = -1;
    if (!is_null(alt)) {
        for (i = 191; i >= 0; i--)
            if (alt.bits[i] == 1)
                break;
    }
    return i;
}

void s21_bank_rounding(s21_decimal_alt *alt, int mod) {
    if (mod == 5 && alt -> bits[0] || mod > 5) {
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
