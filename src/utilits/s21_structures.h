#ifndef UTILITS_S21_STRUCTURES_H_
#define UTILITS_S21_STRUCTURES_H_

#define MINUS_SIGN 4294967295;

typedef struct {
    unsigned int bits[4];
} s21_decimal;

typedef enum {
    CONVERTATION_OK = 0,
    CONVERTATION_ERROR = 1
} convertation_result;

#endif