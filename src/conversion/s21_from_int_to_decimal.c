#include <stdlib.h>
#include <stdio.h>
#include "../conversion/s21_conversion.h"
#include "../utilits/s21_structures.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    convertation_result status;
    if (dst) {
        status = CONVERTATION_OK;
        if (src < 0) dst->bits8[15] = 128;
        dst->bits64[0] = (src < 0) ? -1 * src : src;
    } else {
        status = CONVERTATION_ERROR;
    }
    return status;
}

