// i am trying to do basic integer addition. NO LOOKING AT EXPONENT!!
#include "s21_arithmetics.h"
#include <stdio.h>
#define S21_INTMAX 255  //(hotblack) i need it for some tests

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int r = 0;
    for (int i = 0; i < 3; i++) {
        result -> bits[i] = value_1.bits[i] + value_2.bits[i];
        if (result -> bits[i] > S21_INTMAX) {
            result -> bits[i] = result -> bits[i] - 1 - S21_INTMAX;
            if (i != 2)
                result -> bits[i] += 1;
            else
                r = 1;
        }
    }
    return r;
}

int main(void) {
    s21_decimal dec1;
    dec1.bits[0] = 100;
    dec1.bits[1] = 100;
    dec1.bits[2] = 10;

    s21_decimal dec2;
    dec2.bits[0] = 100;
    dec2.bits[1] = 100;
    dec2.bits[2] = 10;

    s21_decimal dec3;
    dec3.bits[0] = 0;
    dec3.bits[1] = 0;
    dec3.bits[2] = 0;

    s21_add(dec1, dec2, &dec3);
    int b = dec1.bits[0] + 256 * dec1.bits[1] + 32768 * dec1.bits[2];
    int a =  dec3.bits[0] + 256 * dec3.bits[1] + 32768 * dec3.bits[2];
    printf("%i\n", a);
    return 0;
}