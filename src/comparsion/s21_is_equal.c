#include "../s21_decimal.h"

int s21_is_equal(s21_decimal a, s21_decimal b) {
    int equal = 1;
    int aSign = 0, bSign = 0;
    if (a.bits[3] >= MINUS_SIGN) {
        aSign = 1;
    }
    if (b.bits[3] >= MINUS_SIGN) {
        bSign = 1;  // if their signs are not matching = they are ne
    }
    if (aSign != bSign) {
        equal = 0;
    } else {
        for (register int i = 0; i <= 2; i++) {
            if (a.bits[i] != b.bits[i]) {
                equal = 0;
                break;
            }
        }
    }
    return (equal);
}
