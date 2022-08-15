#include "../utilits/s21_utility.h"
#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *res) {
    int return_code = 0;
    if (res) {
        s21_decimal_alt alt_value = s21_convert_std_to_alt(value);
        while (alt_value.exp > 0)
            div_by_ten(&alt_value);
        *res = s21_convert_alt_to_std(alt_value);
    } else {
        return_code = 1;
    }
    return return_code;
}
