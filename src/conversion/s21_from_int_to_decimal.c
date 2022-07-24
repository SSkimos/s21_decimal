#include "../conversion/s21_conversion.h"
#include "../utilits/s21_structures.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    convertation_result status;
    if (dst) {
        status = CONVERTATION_OK;
        if (src < 0) dst->bits[3] = MINUS_SIGN;
        dst->bits[0] = (src < 0) ? -1 * src : src;
        printf("number = %d\n", src);
        for (int i = 0; i < 4; i++) {
            printf("arr%d = %u\n", i, dst->bits[i]);
        }
    } else {
        status = CONVERTATION_ERROR;
    }
    return status;
}
