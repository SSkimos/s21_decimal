#include "../s21_decimal.h"
#include "../utilits/s21_utility.h"

int s21_is_less(s21_decimal a, s21_decimal b) {
    int less = 0;
    int equal = s21_is_equal(a, b);
    if (!(equal)) {
        less = s21_is_greater(a, b);
        if (less) {
            less = 0; 
        } else {
            less = 1;
        }
    }
    return less;
}

