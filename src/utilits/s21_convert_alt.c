#include "s21_utility.h"
#include <math.h>

s21_decimal_alt s21_convert_std_to_alt(s21_decimal std) {
    s21_decimal_alt alt;
    s21_null_decimal_alt(&alt);
    alt.sign = s21_get_sign_std(std);
    alt.exp = s21_get_exp_std(std);
    int i = 0;
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 32; k++)
            alt.bits[i++] = s21_get_bit_int(std.bits[j], k);
    }
    return alt;
}

s21_decimal s21_convert_alt_to_std(s21_decimal_alt alt) {
    s21_decimal std;
    init_decimal(&std);
    int k = 95;
    for (int i = 2; i >= 0; i--)
        for (int j = 31; j >= 0; j--)
            std.bits[i] = (std.bits[i] << 1) + alt.bits[k--];
    std.bits[3] = alt.sign;
    std.bits[3] <<= 7;
    k = 128;
    for (int i = 7; i >= 0; i--) {
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

s21_decimal s21_convert_int_to_std(unsigned long int number) {
    s21_decimal decimal;
    init_decimal(&decimal);
    s21_decimal_alt alt_decimal;
    alt_decimal = s21_convert_int_to_alt(number);
    decimal = s21_convert_alt_to_std(alt_decimal);
    return decimal;
}

s21_decimal_alt s21_convert_int_to_alt(unsigned long int number) {
    s21_decimal_alt alt;
    s21_null_decimal_alt(&alt);
    int i = 0;
    while (number >= 1) {
        if (number % 2 == 1) {
            alt.bits[i] = 1;
        }
        i++;
        number /= 2;
    }
    return alt;
}

long int s21_convert_std_to_int(s21_decimal decimal) {
    s21_decimal_alt alt;
    s21_null_decimal_alt(&alt);
    alt = s21_convert_std_to_alt(decimal);
    long int result = s21_convert_alt_to_int(alt);
    return result;
}

long int s21_convert_alt_to_int(s21_decimal_alt alt) {
    long int result = 0;
    print_binary_representation_alt(alt);
    for (int i = 0; i <= 96; i++) {
        if (alt.bits[i] == 1) {
            result += (pow(2, (i)));
        }
    }
    //0000100010101
    //0 2 4 8
    return result;
}
