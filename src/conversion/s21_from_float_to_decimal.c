#include <stdlib.h>
#include <stdio.h>
#include "../s21_decimal.h"

int get_exponent(long double number) {
    int exponent = 0;
    while (number > 1) {
        printf("%Lf\n", number);
        number /= 10;
        exponent++;
    }
    exponent = (exponent == 0) ? 1 : exponent;
    return exponent;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    convertation_result status;
    if (dst) {
        status = CONVERTATION_OK;
        if (src) {
            printf("=== WARNING ===\nfrom float not yet ready\n");
            printf("exponent = %d\n", get_exponent(src));
            printf("=== === ===\n");
        }
    } else {
        status = CONVERTATION_ERROR;
    }
    return status;
}

