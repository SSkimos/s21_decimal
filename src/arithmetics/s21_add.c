// i am trying to do basic integer addition. NO LOOKING AT EXPONENT!!
// #include <s21_arithmetics.h>
#include <limits.h>
#include <stdio.h>
#define S21_INTMAX 255  //(hotblack) i need it for some tests
// typedef struct {
//     unsigned int bits[4];
// } s21_decimal;

typedef struct {
    unsigned char bits[4];
} s21_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int r = 0;
    result -> bits[0] = value_1.bits[0] + value_2.bits[0];
    if (result -> bits[0] > S21_INTMAX) {
        result -> bits[0] = result -> bits[0] - 1 - S21_INTMAX;
        result -> bits[1] += 1;
    }
    result -> bits[1] = value_1.bits[1] + value_2.bits[1];
    if (result -> bits[1] > S21_INTMAX) {
        result -> bits[1] = result -> bits[1] - 1 - S21_INTMAX;
        result -> bits[2] += 1;
    }
    result -> bits[2] = value_1.bits[2] + value_2.bits[2];
    if (result -> bits[2] > S21_INTMAX) {
        result -> bits[2] = result -> bits[2] - 1 - S21_INTMAX;
        r = 1;
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
    printf("%i\n", b);
    return 0;
}