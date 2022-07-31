#ifndef SRC_UTILITS_S21_STRUCTURES_H_
#define SRC_UTILITS_S21_STRUCTURES_H_

#define MINUS_SIGN 4294967295

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

typedef enum {
    CONVERTATION_OK = 0,
    CONVERTATION_ERROR = 1
} convertation_result;

#endif  // SRC_UTILITS_S21_STRUCTURES_H_
