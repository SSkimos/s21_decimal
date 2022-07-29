#ifndef UTILITS_S21_STRUCTURES_H_
#define UTILITS_S21_STRUCTURES_H_

typedef struct {
    unsigned int bits[4];
} s21_decimal;

#include <stdbool.h>
typedef struct {
    bool bits[96];
    bool sign;
    int exp;
} s21_decimal_alt;

typedef enum {
    OPERATION_OK = 0,
    NUMBER_TOO_BIG,
    NUMBER_TOO_SMALL,
    DIVISION_BY_ZERO
} operation_result;

#endif