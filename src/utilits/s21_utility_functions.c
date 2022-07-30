#include "s21_structures.h"
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

bool s21_get_bit(unsigned int num, int pos) {
    return (num >> pos) & 1;
}

bool s21_get_sign(s21_decimal dec) {
    return s21_get_bit(dec.bits[3], 31);
}

int s21_get_exp(s21_decimal dec) {
    return (dec.bits[3] >> 16) % 2147483648;
}

// this function is used for testing purposes
void print_binary_representation(int num) {
    for (int i = 31; i >= 0; i--)
        printf("%i", s21_get_bit(num, i));
}

// this function is used for testing purposes
void print_binary_representation_alt(s21_decimal_alt alt) {
    for (int i = 95; i >= 0; i--)
        printf("%i", alt.bits[i]);
}

void s21_null_decimal(s21_decimal *std) {
    std -> bits[0] = 0;
    std -> bits[1] = 0;
    std -> bits[2] = 0;
    std -> bits[3] = 0;
}

s21_decimal_alt s21_convert_std_to_alt(s21_decimal std) {
    s21_decimal_alt alt;
    alt.sign = s21_get_sign(std);
    alt.exp = s21_get_exp(std);
    int i = 0;
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 32; k++)
            alt.bits[i++] = s21_get_bit(std.bits[j], k);
    }
    return alt;
}

s21_decimal s21_convert_alt_to_std(s21_decimal_alt alt) {
    s21_decimal std;
    s21_null_decimal(&std);
    int k = 95;
    for (int i = 2; i >= 0; i--)
        for (int j = 31; j >= 0; j--)
            std.bits[i] = (std.bits[i] << 1) + alt.bits[k--];
    std.bits[3] = alt.sign;
    std.bits[3] <<= 7;
    k = 16;
    for (int i = 4; i >= 0; i--) {
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

// int main(void) {
//     s21_decimal std;
//     std.bits[0] = 33;
//     std.bits[1] = 127;
//     std.bits[2] = 1;
//     std.bits[3] = 196608;
//     s21_decimal_alt alt = s21_convert_std_to_alt(std);
//     print_binary_representation_alt(alt);
//     s21_decimal ret = s21_convert_alt_to_std(alt);
//     printf("\n%u %u %u %u", ret.bits[0], ret.bits[1], ret.bits[2], ret.bits[3]);
// }
