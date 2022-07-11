TARGET = s21_decimal
TEST_TARGET = decimal_test

CC = gcc -D MAC_OSc
CFLAGS = -Wall -Werror -Wextra
TST_LIBS = -lcheck -lm -lpthread

INT = "./conversion/s21_from_int_to_decimal.c"
FLOAT = "./conversion/s21_from_float_to_decimal.c"
SPACE = " "

FILES = $(INT) \
		$(FLOAT) \

# LFLAGS:= $(shell pkg-config --cflags --libs check)
OBJ_DIR = ./obj/
OBJ = (patsubst %.c, %.o, *.c)

all: conversion_test

conversion_test:
	$(CC) $(CFLAGS) $(FILES) ./tests/conversion_test.c $(TST_LIBS) -o ./tests/conversion_test
	./tests/conversion_test

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm $(TEST_TARGET) *.o

check:
	checkmk clean_mode=1 ./tests/conversion_test.check > ./tests/conversion_test.c

