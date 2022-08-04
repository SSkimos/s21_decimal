#include "s21_utility.h"

// побитовое сложение альтернативных децималов
// принимает два альтернативных децимала с одинаковыми знаками
// и положением запятой
// возвращает 1 при переполнении
int s21_add_alt(s21_decimal_alt alt_value_1, \
s21_decimal_alt alt_value_2, s21_decimal_alt *alt_result) {
    int return_code = 0;
    bool t_bit = 0;  // бит переноса
    for (int i = 0; i < 96; i++) {
        alt_result -> bits[i] = \
        (alt_value_1.bits[i] ^ alt_value_2.bits[i]) ^ t_bit;
        // нужно попробовать максимально упростить это выражение
        if ((alt_value_1.bits[i] & alt_value_2.bits[i]) || \
        (alt_value_1.bits[i] & t_bit) || \
        (alt_value_2.bits[i] & t_bit))
        // "если хотя бы два бита из трех равны единице"
            t_bit = 1;
        else
            t_bit = 0;
    }
    alt_result -> exp = alt_value_1.exp;
    if (t_bit == 1)
        return_code = 1;  // произошло переполнение
    return return_code;
}
