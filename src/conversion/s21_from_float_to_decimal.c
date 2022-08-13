#include "../s21_decimal.h"
#include "../utilits/s21_utility.h"
#include <stdio.h>
#include <math.h>

int s21_mul_10(s21_decimal value, s21_decimal *result);
void s21_set_minus(s21_decimal *dst);

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    convertation_result status;
    if (dst) {
        status = CONVERTATION_OK;
        if (src < 0) {
            s21_set_minus(dst);
            src = -(src);
        }
        int new = (int)src;
        int exp = 0;
        while (src - ((float)new / (int)(pow(10, exp))) != 0) {
            exp++;
            new = src * (int)(pow(10, exp));
        }
        dst->bits[0] = new;
        dst->bits[3] += exp << 15;
    } else {
        status = CONVERTATION_ERROR;
    }
    return status;
}

void s21_set_minus(s21_decimal *dst) {
    dst->bits[3] = 1 << 31;
}

int s21_mul_10(s21_decimal value, s21_decimal *result) {
	int return_code = 0;
	s21_decimal_alt alt_value_1 = s21_convert_std_to_alt(value);
	s21_decimal_alt alt_value_2 = s21_convert_std_to_alt(value);
	s21_decimal_alt alt_result;
	s21_null_decimal_alt(&alt_result);

    s21_left_shift(&alt_value_1);
    s21_left_shift(&alt_value_2);
    s21_left_shift(&alt_value_2);
    s21_left_shift(&alt_value_2);
	return_code = s21_add_alt(alt_value_1, alt_value_2, &alt_result);

	*result = s21_convert_alt_to_std(alt_result);
	return return_code;
}

