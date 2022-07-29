#include "s21_structures.h"
int s21_get_bit(int num, int pos) {
    return num >> pos & 1;
}

int s21_get_sign(int num) {
    return s21_get_bit(num, 7);
}

// this function is used for testing purposes
void print_binary_representation(int num) {
    for (int i = 7; i >= 0; i--)
        printf("%i", s21_get_bit(num, i));
}

void s21_convert_std_to_alt(s21);