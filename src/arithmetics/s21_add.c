// i am trying to do basic integer addition. NO LOOKING AT EXPONENT!!
// работает только для положительных чисел соответственно
#include "s21_arithmetics.h"
#include <stdio.h>

// #include "../utilits/s21_utilities.h"
// #define S21_INTMAX 255  //(hotblack) i need it for some tests

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    s21_decimal_alt alt_value_1 = s21_convert_std_to_alt(value_1);
    s21_decimal_alt alt_value_2 = s21_convert_std_to_alt(value_2);
    s21_decimal_alt alt_value_3;
    s21_null_decimal_alt(&alt_value_3);
    if (alt_value_1.sign == alt_value_2.sign) {
        if (alt_value_1.exp == alt_value_2.exp) {
            int t_bit = 0;  // бит переноса
            for (int i = 0; i < 96; i++) {
                // нужно попробовать максимально упростить это выражение
                // "если хотя бы два бита из трех равны единице"
                if ((alt_value_1.bits[i] & alt_value_2.bits[i]) || \
                (alt_value_1.bits[i] & t_bit) || \
                (alt_value_2.bits[i] & t_bit)) {
                    t_bit = 1;
                }
                alt_value_3.bits[i] = \
                (alt_value_1.bits[i] ^ alt_value_2.bits[2]) ^ t_bit;
            }
            if (t_bit == 1)
                return 1;  // произошло переполнение
        }  // else домножение меньшего числа на 10 и уменьшение экспоненты
    }  // else вычитание вместо сложения
    *result = s21_convert_alt_to_std(alt_value_3);
}

// int main(void) {
//     s21_decimal dec1;
//     s21_null_decimal(&dec1);
//     dec1.bits[0] = 100;
//     dec1.bits[1] = 100;
//     dec1.bits[2] = 10;

//     s21_decimal dec2;
//     s21_null_decimal(&dec2);
//     dec2.bits[0] = 100;
//     dec2.bits[1] = 100;
//     dec2.bits[2] = 10;

//     s21_decimal dec3;
//     s21_null_decimal(&dec3);
//     dec3.bits[0] = 0;
//     dec3.bits[1] = 0;
//     dec3.bits[2] = 0;

//     s21_add(dec1, dec2, &dec3);
//     print_binary_representation_std(dec1);
//     print_binary_representation_std(dec2);
//     print_binary_representation_std(dec3);
//     return 0;
// }
