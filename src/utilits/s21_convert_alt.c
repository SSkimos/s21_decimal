#include "s21_utility.h"

// преобразование стандартного децимала в альтернативный
// протестировано, работает с корректными децималами
// поломается на децимале со слишком большим положением точки
s21_decimal_alt s21_convert_std_to_alt(s21_decimal std) {
    s21_decimal_alt alt;
    alt.sign = s21_get_sign_std(std);
    alt.exp = s21_get_exp_std(std);
    int i = 0;
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 32; k++)
            alt.bits[i++] = s21_get_bit_int(std.bits[j], k);
    }
    return alt;
}

// преобразование альтернативного децимала
// протестировано, работает с корректными децималами
// уже не поломается на децимале со слишком большим положением точки
// (вроде)
s21_decimal s21_convert_alt_to_std(s21_decimal_alt alt) {
    s21_decimal std;
    s21_null_decimal(&std);
    int k = 95;
    for (int i = 2; i >= 0; i--)
        for (int j = 31; j >= 0; j--)
            std.bits[i] = (std.bits[i] << 1) + alt.bits[k--];
    std.bits[3] = alt.sign;
    std.bits[3] <<= 6;
    k = 64;
    for (int i = 8; i >= 0; i--) {
        std.bits[3] <<= 1;
        if (alt.exp >= k) {
            alt.exp -= k;
            std.bits[3]++;
        }
        k >>= 1;
    }
    std.bits[3] <<= 16;
    return std;
}