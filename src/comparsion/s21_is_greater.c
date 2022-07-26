#include "s21_comparsion.h"

int s21_is_greater(s21_decimal a, s21_decimal b) {
    int greater = 0;
    int aSign = 0, bSign = 0;
    if (a.bits[3] >= MINUS_SIGN) {
        aSign = 1;
    }
    if (b.bits[3] >= MINUS_SIGN) {
        bSign = 1;  // if their signs are not matching = they are ne
    }
    if ((aSign == 0) && (bSign == 1)) {
        greater = 1;
    } else if ((aSign == 1) && (bSign == 0)) {
        greater = 0;
    }
    if (greater == 0) {
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

