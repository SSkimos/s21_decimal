#ifndef UTILITS_S21_STRUCTURES_H_
#define UTILITS_S21_STRUCTURES_H_

typedef union {
    uint64_t bits64[2];
    uint32_t bits32[4];
    uint16_t bits16[8];
    uint8_t bits8[16];
    int32_t bits[4];
} s21_decimal;

typedef enum {
    OPERATION_OK = 0,
    NUMBER_TOO_BIG = 1,
    NUMBER_TOO_SMALL = 2,
    DIVISION_BY_ZERO = 3
} operation_result;

#endif