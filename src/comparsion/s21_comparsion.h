#ifndef SRC_COMPARSION_S21_COMPARSION_H_
#define SRC_COMPARSION_S21_COMPARSION_H_

#include "../utilits/s21_structures.h"

#include <stdint.h>

int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal a, s21_decimal b);
int s21_is_greater(s21_decimal a, s21_decimal b);
int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);
int s21_is_less(s21_decimal a, s21_decimal b);
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);

#endif  // SRC_COMPARSION_S21_COMPARSION_H_

