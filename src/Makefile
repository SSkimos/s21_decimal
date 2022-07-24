CC      := gcc
WARNING := -Wall -Werror -Wextra
CFLAGS  := -std=c11 -pedantic $(WARNING)

<<<<<<< HEAD
TARGET      := s21_decimal
TEST_TARGET := decimal_test

# Use CLANGD
LFLAGS  := $(shell pkg-config --cflags --libs check)
OBJ_DIR := ./obj/
DEC_OBJ := $(addprefix)

#all: conversion_test #comparsion_test

all: s21_decimal.a test 

s21_decimal.a: $(
	$(CC) 

test: consversion_test

conversion_test:
	$(CC) $(CFLAGS) ./conversion/s21_from_int_to_decimal.c ./tests/conversion_test.c $(TST_LIBS) -o ./tests/conversion_test
	./tests/conversion_test

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm $(TEST_TARGET) *.o

check:
	checkmk clean_mode=1 ./tests/conversion_test.check > ./tests/conversion_test.c
	@# checkmk clean_mode=1 ./tests/conversion_test.check > ./tests/conversion_test.c
	@# checkmk clean_mode=1 ./tests/conversion_test.check > ./tests/conversion_test.c
	@# checkmk clean_mode=1 ./tests/conversion_test.check > ./tests/conversion_test.c
	@# checkmk clean_mode=1 ./tests/conversion_test.check > ./tests/conversion_test.c

