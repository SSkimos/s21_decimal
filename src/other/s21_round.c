#include "../s21_decimal.h"
#include "../utilits/s21_utility.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
    if (result) {
        s21_null_decimal(result);
        result->bits[0] = value.bits[0];
        result->bits[1] = value.bits[1];
        result->bits[2] = value.bits[2];
        s21_get_bit_int(value.bits[3], 31);
    }
    return 0;
}
