#include "s21_utility.h"
#include <stdio.h>
int s21_div_alt(s21_decimal_alt alt_value_1, \
s21_decimal_alt alt_value_2, s21_decimal_alt *alt_result) {
    s21_decimal_alt ten;
    s21_null_decimal_alt(&ten);
    ten.bits[1] = 1;
    ten.bits[3] = 1;
    s21_null_decimal_alt(alt_result);
    int return_code = 0;
    alt_result -> sign = alt_value_1.sign ^ alt_value_2.sign;
    alt_value_1.sign = 0;
    alt_value_2.sign = 0;

    s21_rescale_alt_to_zero(&alt_value_1, &alt_value_2);
    // print_binary_representation_alt(alt_value_1);
    // print_binary_representation_alt(alt_value_2);
    s21_decimal_alt modulo;
    s21_null_decimal_alt(&modulo);
    modulo = div_with_modulo(alt_value_1, alt_value_2, &alt_value_1);

    while (!is_null(alt_value_1) || !is_null(modulo)) {
        s21_mul_alt(modulo, ten, &modulo);
        // printf("\nmodulo:\n");
        // print_binary_representation_alt(modulo);
        // printf("result from last iteration:\n");
        // print_binary_representation_alt(*alt_result);
        // printf("mul by ten:\n");
        // print_binary_representation_alt(*alt_result);
        s21_mul_alt(*alt_result, ten, alt_result);
        s21_add_alt(*alt_result, alt_value_1, alt_result);
        // printf("add previous result:\n");
        // print_binary_representation_alt(*alt_result);
        modulo = div_with_modulo(modulo, alt_value_2, &alt_value_1);
    }
    // printf("\n");
    // printf("final result:\n");
    // print_binary_representation_alt(*alt_result);
    return return_code;
}

s21_decimal_alt div_with_modulo(s21_decimal_alt alt_value_1, \
s21_decimal_alt alt_value_2, s21_decimal_alt *alt_result) {
    int denominator_left_bit = last_bit(alt_value_2);
    s21_decimal_alt modulo;
    s21_null_decimal_alt(&modulo);
    s21_null_decimal_alt(alt_result);
    if (compare_bits(alt_value_1, alt_value_2)) {
        align(&alt_value_1, &alt_value_2);
    }
    // print_binary_representation_alt(alt_value_1);
    // print_binary_representation_alt(alt_value_2);
    for (int i = 0; i < 191; i++) {
        if (compare_bits(alt_value_1, alt_value_2)) {
            s21_sub_alt(alt_value_1, alt_value_2, &alt_value_1);
            alt_result -> bits[0] = 1;
        }
        if (last_bit(alt_value_2) <= denominator_left_bit)
            break;
        if (last_bit(alt_value_2) > denominator_left_bit)
            s21_right_shift(&alt_value_2);
        s21_left_shift(alt_result);
        // printf("\n");
        // print_binary_representation_alt(alt_value_1);
        // print_binary_representation_alt(alt_value_2);
    }
    return alt_value_1;
}

