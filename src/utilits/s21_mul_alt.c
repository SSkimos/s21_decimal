#include "s21_utility.h"

int s21_mul_alt(s21_decimal_alt alt_value_1, \
s21_decimal_alt alt_value_2, s21_decimal_alt *alt_result) {
    int return_code = 0;
    s21_null_decimal_alt(alt_result);
    int exp1 = alt_value_1.exp;
    int exp2 = alt_value_2.exp;
    alt_value_1.exp = 0;
    alt_value_2.exp = 0;
    int sign1 = alt_value_1.sign;
    int sign2 = alt_value_2.sign;
    alt_value_1.sign = 0;
    alt_value_2.sign = 0;
    for (int i = 0; i < 96; i++) {
        int k = 0;
        if (alt_value_2.bits[i] == 1)
            k = s21_add_alt(*alt_result, alt_value_1, alt_result);
        s21_left_shift(&alt_value_1);
    }
    alt_result -> exp = exp1 + exp2;
    alt_result -> sign = sign1 ^ sign2;
    //////////////////////////////////
    // обработка переполнения на уровне слишком длинного числа
    // обработка из-за слишком большой экспоненты будет позже
    if (last_bit(*alt_result) > 95) {
        int mod = 0;
        while (last_bit(*alt_result) > 95) {
            if (alt_result -> exp == 0)
                break;
            mod = div_by_ten(alt_result);
        }
        s21_bank_rounding(alt_result, mod);
        // нужна еще одна проверка на переполнение
    }
}
