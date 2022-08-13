#include "../utilits/s21_utility.h"
#include "../s21_decimal.h"
#include <stdio.h>
#include <math.h>

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    convertation_result status;
    if (dst) {
        status = CONVERTATION_OK;
        int exp = src.bits[3] & 8355840;
        exp >>= 15;
        *dst = (float)(src.bits[0] / pow(10, exp));
        if (src.bits[3] >> 31 == 1) {
            *dst = -(*dst);
        }
    } else {
        status = CONVERTATION_ERROR;
    }
    return status;
}

