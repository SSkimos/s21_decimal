#ifndef UTILITS_S21_STRUCTURES_H_
#define UTILITS_S21_STRUCTURES_H_

typedef struct {
    int bits[4];
} s21_decimal;

typedef struct {
    int bits[24];
    int sign;
    int exp;
} s21_decimal_alt;

typedef enum {
    OPERATION_OK = 0,
    NUMBER_TOO_BIG,
    NUMBER_TOO_SMALL,
    DIVISION_BY_ZERO
} operation_result;

#endif