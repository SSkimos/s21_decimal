#include "../utilits/s21_utility.h"
#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int return_code = 0;
    if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
        return_code = 3;  // деление на ноль
    } else {
        // побитовое деление
        s21_decimal_alt alt_value_1 = s21_convert_std_to_alt(value_1);
        s21_decimal_alt alt_value_2 = s21_convert_std_to_alt(value_2);
        s21_decimal_alt alt_result;
        s21_null_decimal_alt(&alt_result);
        while (alt_value_1.bits[0] == 0 && alt_value_2.bits[0] == 0) {
            s21_right_shift(&alt_value_1);
            s21_right_shift(&alt_value_2);
        }
        ////////////////////////////////////
        // пока что совсем не думаю о положении точки
        ////////////////////////////////////
        alt_value_1.sign = 0;
        alt_value_2.sign = 0;
        // очень важное значение:
        // нужно для того чтобы я ненароком не уменьшила знаменатель
        int denominator_left_bit = last_bit(alt_value_2);
        // TODO(hotblack): эта конструкция используется в div_by_ten,
        // вынеси в отдельную функцию
        while (last_bit(alt_value_1) != last_bit(alt_value_2))
            if (compare_bits(alt_value_1, alt_value_2))
                s21_left_shift(&alt_value_2);
            else
                s21_left_shift(&alt_value_1);
        if (!compare_bits(alt_value_1, alt_value_2))
            s21_left_shift(&alt_value_1);
        // вот это

        for (int i = 0; i < 97; i++) {
            printf("%i!\n", denominator_left_bit);
            print_binary_representation_alt_s(alt_value_1);
            print_binary_representation_alt_s(alt_value_2);
            print_binary_representation_alt_s(alt_result);
            if (compare_bits(alt_value_1, alt_value_2)) {
                s21_sub_alt(alt_value_1, alt_value_2, &alt_value_1);
                alt_result.bits[0] = 1;
            }
            if (is_null(alt_value_1) && \
            last_bit(alt_value_2) == denominator_left_bit)
                break;
            if (last_bit(alt_value_2) > denominator_left_bit) {
                s21_right_shift(&alt_value_2);
            } else {
                s21_left_shift(&alt_value_1);
            }

            s21_left_shift(&alt_result);
        }

        printf("!\n");
        print_binary_representation_alt_s(alt_value_1);
        print_binary_representation_alt_s(alt_value_2);
        print_binary_representation_alt_s(alt_result);
        printf("!\n");

        *result = s21_convert_alt_to_std(alt_result);
        value_1 = s21_convert_alt_to_std(alt_value_1);
        value_2 = s21_convert_alt_to_std(alt_value_2);
    }
    return return_code;
}
