#include <stdlib.h>
#include <stdio.h>
#include "../conversion/s21_conversion.h"
#include "../utilits/s21_structures.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    convertation_result status;
    if (dst) {
        status = CONVERTATION_OK;
        if (src) {
            printf("=== WARNING ===\nfrom float not yet ready\n");
        }
    } else {
        status = CONVERTATION_ERROR;
    }
    return status;
}