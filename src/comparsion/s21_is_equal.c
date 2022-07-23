#include "s21_comparsion.h"

int s21_is_equal(s21_decimal a, s21_decimal b) {
    // if a == b return 1 else 0;
    int not_equal = 0;
    for (register int i = 0; i < 4; i++) {
        if (a.bits[i] != b.bits[i]) {
            not_equal = 1;
            break;
        }
    }
    return (not_equal) ? 1 : 0;
}
