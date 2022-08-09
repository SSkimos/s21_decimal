#include "../utilits/s21_utility.h"
#include "../s21_decimal.h"
#include <stdio.h>
#include <math.h>

int s21_mul_10(s21_decimal value, s21_decimal *result);

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
	convertation_result status;
	if (dst) {
		status = CONVERTATION_OK;
		typedef union {
			int n;
			float f;
		} u;
		u num;
		num.f = src;
        int mant = num.n;
        int exp = num.n;

		mant &= 8388607; // мантисса без единицы
        mant |= (1 << 23);
        exp &= 2139095040; // получил exp
        exp >>= 23; //сдвинул exp
        exp -= 127;
		dst->bits[0] = mant;

        int counter = 23 - exp;
        while (counter > 0) {
            if (s21_get_bit_int(dst->bits[0], 32)) {
                // если на конце единица
                s21_mul_10(*dst, dst);
                s21_decimal_alt alt_decimal = s21_convert_std_to_alt(*dst);
                s21_right_shift(&alt_decimal);
                *dst = s21_convert_alt_to_std(alt_decimal);
                exp++;
            } else {
                // если на конце ноль
                s21_decimal_alt alt_decimal = s21_convert_std_to_alt(*dst);
                s21_right_shift(&alt_decimal);
                *dst = s21_convert_alt_to_std(alt_decimal);
            }
            counter--;
        }
        dst->bits[3] = exp << 15;
        print_binary_representation_std(*dst);
	} else {
		status = CONVERTATION_ERROR;
	} return status;
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

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
	int return_code = 0;
    float result = 0.0;
    int sign = 1;
    result = src.bits[0] * pow(10, (-1 * s21_get_exp_std(src)));
    if (s21_get_sign_std(src)) {
        sign = -1;
    }
    result *= sign;
    *dst = result;
    return return_code;
}

