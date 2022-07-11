#include <stdlib.h>
#include <stdio.h>
#include "s21_decimal.h"

int main() {
    s21_decimal decimal;
    s21_from_int_to_decimal(1000000000,&decimal);
    printf("value = %64llu\n", decimal.bits64[0]);
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    if (src < 0) dst->bits8[15] = 128; //TODO:
    dst->bits64[0] = (src < 0) ? -1 * src : src;
}

