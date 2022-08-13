#include "../utilits/s21_utility.h"
#include "../s21_decimal.h"
#include <stdio.h>

int s21_negate(s21_decimal value, s21_decimal *res) {
    operation_result result;
    if (1) {
        result = OPERATION_OK;
        if (value.bits[3] >> 31) {
            res->bits[0] = value.bits[0];
            res->bits[1] = value.bits[1];
            res->bits[2] = value.bits[2];
            res->bits[3] = value.bits[3];
            res->bits[3] = res->bits[3] + (0 << 31);
        } else {
            res->bits[0] = value.bits[0];
            res->bits[1] = value.bits[1];
            res->bits[2] = value.bits[2];
            res->bits[3] = value.bits[3];
            res->bits[3] = res->bits[3] + (1 << 31);
        }
    } else {
        result = 1;
    }
    return result;
}