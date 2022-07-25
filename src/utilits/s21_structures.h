#ifndef UTILITS_S21_STRUCTURES_H_
#define UTILITS_S21_STRUCTURES_H_

#define MINUS_SIGN 4294967295

typedef struct {
    unsigned int bits[4];
} s21_decimal;

typedef enum {
    OPERATION_OK = 0,
    NUMBER_TOO_BIG,
    NUMBER_TOO_SMALL,
    DIVISION_BY_ZERO
} operation_result;

typedef enum {
    CONVERTATION_OK = 0,
    CONVERTATION_ERROR = 1
} convertation_result;

#endif
