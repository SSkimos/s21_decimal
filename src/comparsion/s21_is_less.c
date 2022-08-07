#include "../s21_decimal.h"
#include "../utilits/s21_utility.h"

int s21_is_less(s21_decimal a, s21_decimal b) {
    int less = 0;
    int equal = s21_is_equal(a, b);
    if (!(equal)) {
        s21_rescale(&a, &b);
        for (register int i = 0; i < 3; i++) {
            if ((a.bits[i] < b.bits[i])) {
                less = 1;
                break;
            }
        }
    }
    return less;
}

