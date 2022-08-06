CC         = gcc
SRC_DIR    = .
TEST_DIR   = tests
INC_DIRS  := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I, $(INC_DIRS))

SRC  := $(shell find $(SRC_DIR) -name "s21*.c" | sed -e 's/\.\///')
TEST := $(shell find $(TEST_DIR) -name "*.c" | sed -e 's/\.\///')
CHECK:= $(shell find $(TEST_DIR) -name "*.check" | sed -e 's/\/\///')

BUILD_DIR      = obj
BUILD_TEST_DIR = obj_test

OBJS      := $(SRC:%.c=$(BUILD_DIR)/%.o)
TEST_OBJS := $(TEST:%.c=$(BUILD_TEST_DIR)/%.o)

WARNING  = -Wall -Werror -Wextra
CFLAGS   = $(INC_FLAGS) -std=c11 -pedantic $(WARNING)
LFLAGS  ?= $(shell pkg-config --cflags --libs check)
INC_CHECK ?= $(shell pkg-config --cflags check)


all: s21_decimal.a test

test: check $(TEST_OBJS)
	./$(BUILD_TEST_DIR)/tests/conversion_test.o
	$(CC) $(LFLAGS) $(TEST_OBJS) $(BUILD_TEST_DIR)/main.o s21_decimal.a -o test
	./test
	#./$(BUILD_TEST_DIR)/tests/comparsion_test.o

s21_decimal.a: $(OBJS)
	@mkdir -p $(BUILD_DIR)
	ar rc s21_decimal.a $(OBJS)
	ranlib s21_decimal.a

gcov_report:

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

$(BUILD_TEST_DIR)/%.o: %.c
	@mkdir -p $(BUILD_TEST_DIR)
	$(CC) $(INC_CHECK) -c $^ -o $@

check:
	checkmk clean_mode=1 tests/conversion_test.check > tests/conversion_test.c
	checkmk clean_mode=1 tests/comparsion_test.check > tests/comparsion_test.c

clean: 
	@ echo $(SRC)
	@ echo $(OBJS)
	rm -r $(BUILD_DIR)
	rm tests/*.c

clean_lib:
	rm s21_decimal.a

rebuild: clean clean_lib all

lint:
	-cp ../materials/linters/CPPLINT.cfg .
	-find . -type f -name "*.c" | xargs python3 ../materials/linters/cpplint.py --extensions=c
	-find . -type f -name "*.h" | xargs python3 ../materials/linters/cpplint.py --extensions=c
	-find . -type f -name "*.c" | xargs cppcheck --enable=all --suppress=missingIncludeSystem
	rm -f CPPLINT.cfg

