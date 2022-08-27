#include "../s21_decimal.h"
#include "../utilits/s21_utility.h"

int s21_is_equal(s21_decimal a, s21_decimal b) {
    int equal = 1;
    bool aSign = 0, bSign = 0;
    aSign = s21_get_sign_std(a);
    bSign = s21_get_sign_std(b);
    if (aSign != bSign) {
        equal = 0;
    } else {
        s21_rescale(&a, &b);
        for (register int i = 0; i <= 2; i++) {
            if (a.bits[i] != b.bits[i]) {
                equal = 0;
                break;
            }
        }
    }
    return equal;
}
