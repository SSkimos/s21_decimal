#include "../s21_decimal.h"
#include "../utilits/s21_utility.h"

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int return_code = 0;
    result->bits[0] = value_1.bits[0] / value_2.bits[0];
    return return_code;
}
