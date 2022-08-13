#include "../s21_decimal.h"
#include "../utilits/s21_utility.h"
#include <stdio.h>
#include <math.h>

void s21_set_minus(s21_decimal *dst);

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    convertation_result status;
    if (dst) {
        status = CONVERTATION_OK;
        if (src < 0) {
            s21_set_minus(dst);
            src = -(src);
        }
        int new = (int)src;
        int exp = 0;
        while (src - ((float)new / (int)(pow(10, exp))) != 0) {
            exp++;
            new = src * (int)(pow(10, exp));
        }
        dst->bits[0] = new;
        dst->bits[3] += exp << 15;
    } else {
        status = CONVERTATION_ERROR;
    }
    return status;
}

void s21_set_minus(s21_decimal *dst) {
    dst->bits[3] = 1 << 31;
}

