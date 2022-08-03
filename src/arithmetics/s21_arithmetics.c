#include <stdio.h>
#include "../utilits/s21_utility.h"
#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int return_code;
    if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
        return_code = 3;  // деление на ноль
    } else {
        // побитовое деление
        s21_decimal_alt alt_value_1 = s21_convert_std_to_alt(value_1);
        s21_decimal_alt alt_value_2 = s21_convert_std_to_alt(value_2);
        s21_decimal_alt alt_result;
        s21_null_decimal_alt(&alt_result);
        if (alt_value_1.bits[0] == 0 && alt_value_2.bits[0] == 0) {
            s21_right_shift(&alt_value_1);
            s21_right_shift(&alt_value_2);
        }
        // я пока что не поняла алгоритма побитового деления на степени двойки
        // но вот сокращение всего на степени двойки!
        *result = s21_convert_alt_to_std(alt_result);
        value_1 = s21_convert_alt_to_std(alt_value_1);
        value_2 = s21_convert_alt_to_std(alt_value_2);
    }
    return return_code;
}

// вычитание децималов
// не хватает (закомментировано, записано в комментарии):
// сравнения по экспоненте (нет приведения к одной экспоненте)
// вычитания в случае, если модуль второго числа больше модуля первого числа
// (требуется is_less_or_equal, is_more_or_equal)
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int return_code = 0;
    s21_rescale(&value_1, &value_2);
    s21_decimal_alt alt_value_1 = s21_convert_std_to_alt(value_1);
    s21_decimal_alt alt_value_2 = s21_convert_std_to_alt(value_2);
    s21_decimal_alt alt_result;
    s21_null_decimal_alt(&alt_result);
    if (alt_value_1.sign == alt_value_2.sign) {
        // if (alt_value_1.exp = alt_value_2.exp) {
            // there if no is_less_or_equal yet
            // if (s21_is_greater_or_equal(value_1, value_2) && \
            // alt_value_1.sign == 0 || s21_is_less_or_equal(value_1, value_2) \
            // && alt_value_1.sign == 1) {
                // нормальные побитовые вычисления
        return_code = s21_sub_alt(alt_value_1, alt_value_2, &alt_result);
                // }
            // } else {
            //     alt_value_1.sign = alt_value_1.sign ^ 1;
            //     alt_value_2.sign = alt_value_2.sign ^ 1;
            //     value_1 = s21_convert_alt_to_std(alt_value_2);
            //     value_2 = s21_convert_alt_to_std(alt_value_1);
            //     return_code = s21_sub(value_1, value_2, result);
            // }
        // }  // else приведение к большему
    } else {
        alt_value_2.sign = alt_value_2.sign ^ 1;
        value_2 = s21_convert_alt_to_std(alt_value_2);
        return_code = s21_add(value_1, value_2, result);
        alt_result = s21_convert_std_to_alt(*result);
    }
    *result = s21_convert_alt_to_std(alt_result);
    return return_code;
}

// сложение децималов
// не хватает:
// сравнения по экспоненте (нет приведения к одной экспоненте)
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int return_code = 0;
    s21_rescale(&value_1, &value_2);
    s21_decimal_alt alt_value_1 = s21_convert_std_to_alt(value_1);
    s21_decimal_alt alt_value_2 = s21_convert_std_to_alt(value_2);
    s21_decimal_alt alt_result;
    s21_null_decimal_alt(&alt_result);
    if (alt_value_1.sign == alt_value_2.sign) {
        // if (alt_value_1.exp == alt_value_2.exp) {
            return_code = s21_add_alt(alt_value_1, alt_value_2, &alt_result);
        // }
    } else {  // else вычитание вместо сложения
        if (alt_value_1.sign) {
            alt_value_1.sign = 0;
            value_1 = s21_convert_alt_to_std(alt_value_1);
            return_code = s21_sub(value_2, value_1, result);
        } else {
            alt_value_2.sign = 0;
            value_2 = s21_convert_alt_to_std(alt_value_2);
            return_code = s21_sub(value_1, value_2, result);
        }
    }
    *result = s21_convert_alt_to_std(alt_result);
    return return_code;
}

// перемножение децималов
// не хватает:
// сдвига точки вправо и округления при переполнении
// сообщения о переполнении при совсем переполнении
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int return_code = 0;
    s21_decimal_alt alt_value_1 = s21_convert_std_to_alt(value_1);
    s21_decimal_alt alt_value_2 = s21_convert_std_to_alt(value_2);
    s21_decimal_alt alt_result;
    s21_null_decimal_alt(&alt_result);
    s21_mul_alt(alt_value_1, alt_value_2, &alt_result);
    *result = s21_convert_alt_to_std(alt_result);
    return return_code;
}
