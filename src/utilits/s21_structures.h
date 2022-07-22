#ifndef UTILITS_S21_STRUCTURES_H_
#define UTILITS_S21_STRUCTURES_H_

typedef struct {
    unsigned int bits[4];
} s21_decimal;

typedef enum {
    OPERATION_OK = 0,
    NUMBER_TOO_BIG,
    NUMBER_TOO_SMALL,
    DIVISION_BY_ZERO
} operation_result;

#endif