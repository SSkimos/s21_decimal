#include "../utilits/s21_utility.h"
#include "../s21_decimal.h"
#include <stdio.h>

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    convertation_result status;
    if (dst) {
        status = CONVERTATION_OK;
        float result = 0;
        int exp = 0;

        exp = src.bits[3] & 16711680;
        printf("exp = %d\n", exp);

        *dst = result;
    } else {
        status = CONVERTATION_ERROR;
    }
    return status;
}
