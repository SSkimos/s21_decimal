#include "../utilits/s21_utility.h"
#include "../s21_decimal.h"

int s21_is_greater(s21_decimal a, s21_decimal b) {
    int greater = 0;
    bool aSign = 0, bSign = 0;
    if (s21_get_sign_std(a)) {
        aSign = 1;
    }
    if (s21_get_sign_std(b)) {
        bSign = 1;  // if their signs are not matching = they are ne
    }
    if ((aSign == 0) && (bSign == 1)) {
        greater = 1;
    } else if ((aSign == 1) && (bSign == 0)) {
        greater = 0;
    }
    if (greater == 0) {
        s21_rescale(&a, &b);
        for (register int i = 2; i >= 0; i--) {
            if (a.bits[i] > b.bits[i]) {
                greater = 1;
                break;
            } else if (a.bits[i] < b.bits[i]) {
                greater = 0;
                break;
            }
        }
    }
    return (greater);
}

