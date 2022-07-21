#ifndef SRC_S21_COMPARSION_H_
#define SRC_S21_COMPARSION_H_
#include <stdint.h>

typedef union {
    uint64_t bits64[2];
    uint32_t bits32[4];
    uint16_t bits16[8];
    uint8_t bits8[16];
    int32_t bits[4];
} s21_decimal;

  int s21_is_equal(s21_decimal, s21_decimal);
  int s21_is_greater(s21_decimal, s21_decimal);
  int s21_is_greater_or_equal(s21_decimal, s21_decimal);
  int s21_is_less(s21_decimal, s21_decimal);
  int s21_is_less_or_equal(s21_decimal, s21_decimal);

#endif  // SRC_S21_COMPARSION_H_


