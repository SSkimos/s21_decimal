#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "tests/s21_decimal_test.h"
#include "s21_decimal.h"

int main() {
    int no_failed = 0;
    Suite *compare;
    Suite *add;
    Suite *sub;
    Suite *mul;
    Suite *conv;
    SRunner* runner;
    compare = comparsion_suite();
    add = add_suite();
    sub = sub_suite();
    mul = mul_suite();
    conv = conversion_suite();
    runner = srunner_create(compare);
    srunner_add_suite(runner, add);
    srunner_add_suite(runner, sub);
    srunner_add_suite(runner, mul);
    srunner_add_suite(runner, conv);
    srunner_set_log(runner, "tests/test.log");
    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

