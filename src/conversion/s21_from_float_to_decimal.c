#include "../utilits/s21_utility.h"
#include "../s21_decimal.h"

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
		mant &= 8388607;
		dst->bits[0] = mant;
		//printf_binary_decimal(dst);
		//s21_mul_10(*dst, dst);
		//printf_binary_decimal(dst);	
	} else {
		status = CONVERTATION_ERROR;
	}
	return status;
}

int s21_mul_10(s21_decimal value, s21_decimal *result) {
	int return_code = 0;
	// s21_decimal_alt alt_value_1 = s21_convert_std_to_alt(value);
	// s21_decimal_alt alt_value_2 = s21_convert_std_to_alt(value);
	s21_decimal_alt alt_result;
	s21_null_decimal_alt(&alt_result);
	// return_code = s21_add_alt(alt_value_1 << 1, alt_value_2 << 3, &alt_result);
	*result = s21_convert_alt_to_std(alt_result);
	return return_code;
}

