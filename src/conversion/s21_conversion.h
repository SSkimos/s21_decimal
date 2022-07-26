#ifndef SRC_CONVERSION_S21_CONVERSION_H_
#define SRC_CONVERSION_S21_CONVERSION_H_
#include "../utilits/s21_structures.h"
#include "../utilits/utilits.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);

#endif  // SRC_CONVERSION_S21_CONVERSION_H_
