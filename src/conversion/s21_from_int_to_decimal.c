#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    convertation_result status;
    if (dst) {
        status = CONVERTATION_OK;
        if (src < 0) dst->bits[3] = MINUS_SIGN;
        dst->bits[0] = (src < 0) ? -1 * src : src;
    } else {
        status = CONVERTATION_ERROR;
    }
    return status;
}
