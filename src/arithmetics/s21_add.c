// i am trying to do basic integer addition. NO LOOKING AT EXPONENT!!
// #include <s21_arithmetics.h>
#include <limits.h>
#include <stdio.h>
// typedef struct {
//     unsigned int bits[4];
// } s21_decimal;

typedef struct {
    unsigned char bits[4];
} s21_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    result -> bits[0] = value_1.bits[0] + value_2.bits[0];
    if (result -> bits[0] > SCHAR_MAX) {
        result -> bits[0] = result -> bits[0] - 1 - SCHAR_MAX;
        result -> bits[1] += 1;
    }
    result -> bits[1] = value_1.bits[1] + value_2.bits[1];
    if (result -> bits[1] > SCHAR_MAX) {
        result -> bits[1] = result -> bits[1] - 1 - SCHAR_MAX;
        result -> bits[2] += 1;
    }
    return 1;
}

int main(void) {
    s21_decimal dec1;
    dec1.bits[0] = 100;
    dec1.bits[1] = 100;
    dec1.bits[2] = 0;

    s21_decimal dec2;
    dec2.bits[0] = 100;
    dec2.bits[1] = 100;
    dec2.bits[2] = 0;

    s21_decimal dec3;
    dec3.bits[0] = 0;
    dec3.bits[1] = 0;
    dec3.bits[2] = 0;

    s21_add(dec1, dec2, &dec3);
    int a =  dec3.bits[0] + 128 * dec3.bits[1] + 32768 * dec3.bits[2];
    printf("%i\n", a);
    return 0;
}