#include "../utilits/s21_utility.h"
#include "../s21_decimal.h"
#include <stdio.h>

int s21_negate(s21_decimal value, s21_decimal *res) {
    operation_result result;
    print_binary_representation_std(value);
    if (1) {
        result = OPERATION_OK;
        printf("before = ");
        print_binary_representation_std(value);
        if (value.bits[3] >> 31) {
           // res->bits[3] & 33423360;
        } else {
            int buffer = res->bits[3] & 33423360;
            res->bits[3] <<= 31;
            res->bits[3] += buffer;
        }
        printf("after = ");
        print_binary_representation_std(*res);
    } else {
        result = 1;
    }
    return result;
}
