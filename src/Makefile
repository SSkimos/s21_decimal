CC          = gcc
SRC_DIR     = .
TEST_DIR    = tests
INC_DIRS   := $(shell find $(SRC_DIR) -type d)
INC_FLAGS  := $(addprefix -I, $(INC_DIRS))
TEST_FLAGS := --coverage -c -g

SRC  := $(shell find $(SRC_DIR) -name "s21*.c" | sed -e 's/\.\///')
TEST := $(shell find $(TEST_DIR) -name "*.c" | sed -e 's/\.\///')

BUILD_DIR      = obj
BUILD_TEST_DIR = obj_test
GCOV_OBJ_DIR  := gcov_res

OBJS      := $(SRC:%.c=$(BUILD_DIR)/%.o)
TEST_OBJS := $(TEST:%.c=$(BUILD_TEST_DIR)/%.o)
GCOV_OBJS := $(SRC:%.c=$(GCOV_OBJ_DIR)/%.o)

WARNING    = -Wall -Werror -Wextra
CFLAGS     = -std=c11 -pedantic $(WARNING)
LFLAGS    ?= $(shell pkg-config --cflags --libs check)
INC_CHECK ?= $(shell pkg-config --cflags check)
DEC_TEST  := decimal_test.c


all: s21_decimal.a test

test: $(TEST_OBJS) $(BUILD_TEST_DIR)/main.o
	$(CC) $(LFLAGS) $(TEST_OBJS) $(BUILD_TEST_DIR)/main.o s21_decimal.a -o test.out
	./test.out

s21_decimal.a: $(OBJS)
	@mkdir -p $(BUILD_DIR)
	ar rc s21_decimal.a $(OBJS)
	ranlib s21_decimal.a

gcov_report: $(GCOV_OBJS) $(BUILD_TEST_DIR)/main.o $(SRC)
	@mkdir -p $(GCOV_OBJ_DIR)
	ar rc s21_decimal.a $(GCOV_OBJS)
	ranlib s21_decimal.a
	$(CC) $(LFLAGS) --coverage $(TEST_OBJS) $(BUILD_TEST_DIR)/main.o s21_decimal.a -o test.out
	- ./test.out
	./../materials/lcov/bin/lcov -f -c --directory . -o ./gcov_res/coverage.info 
	./../materials/lcov/bin/genhtml gcov_res/coverage.info --output-directory=gcov_res
	open gcov_res/index.html

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_TEST_DIR)/main.o: $(DEC_TEST) 
	@mkdir -p $(BUILD_TEST_DIR)
	$(CC) $(INC_CHECK) -c -o $(BUILD_TEST_DIR)/main.o $(DEC_TEST)

$(BUILD_TEST_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(INC_CHECK) -c $^ -o $@

$(GCOV_OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(TEST_FLAGS) -c $< -o $@

.PHONY: clean rebuild lint test
clean: 
	rm -f *.gcda *.gcov *.o *.gcno
	rm -f s21_decimal.a
	rm -rf $(BUILD_DIR)
	rm -rf $(BUILD_TEST_DIR)
	rm -rf $(GCOV_OBJ_DIR)
	rm -f test.out

rebuild: clean all

lint:
	-cp ../materials/linters/CPPLINT.cfg .
	-find . -type f -name "*.c" | xargs python3 ../materials/linters/cpplint.py --extensions=c
	-find . -type f -name "*.h" | xargs python3 ../materials/linters/cpplint.py --extensions=c
	#-find . -type f -name "*.c" | xargs cppcheck --enable=all --suppress=missingIncludeSystem
	rm -f CPPLINT.cfg

