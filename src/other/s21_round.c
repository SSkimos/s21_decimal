#include "../utilits/s21_utility.h"
#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *res) {
    int return_code = 0;
    if (res) {
        *res = value;
    } else {
        return_code = 1;
    }
    return return_code;
}
