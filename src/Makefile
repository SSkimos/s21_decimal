CC      = gcc
WARNING = -Wall -Werror -Wextra

SRC_DIR  = .
TEST_DIR = tests

BUILD_DIR  = obj
TEST_BUILD = obj_test

SRC  := $(shell find $(SRC_DIR) -name "s21*.c" | sed -e 's/\.\///')
TEST := $(shell find $(TEST_DIR) -name "*.c" | sed -e 's/\.\///')
CHECK:= $(shell find $(TEST_DIR) -name "*.check" | sed -e 's/\/\///')

OBJS      := $(SRC:%.c=$(BUILD_DIR)/%.o)
TEST_OBJS := $(TEST:%.c=$(TEST_BUILD)/%.o)

INC_DIRS  := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I, $(INC_DIRS))

CFLAGS  = $(INC_FLAGS) -std=c11 -pedantic $(WARNING)
LFLAGS ?= $(shell pkg-config --cflags --libs check)

all: s21_decimal.a test

test: check $(TEST_OBJS)
	./$(TEST_OBJS)

s21_decimal.a: $(OBJS)
	@mkdir -p $(BUILD_DIR)
	ar rc s21_decimal.a $(OBJS)
	ranlib s21_decimal.a

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

$(TEST_BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) s21_decimal.a $(LFLAGS) $< -o $@

check:
	checkmk clean_mode=1 tests/conversion_test.check > tests/conversion_test.c
	checkmk clean_mode=1 tests/comparsion_test.check > tests/comparsion_test.c

clean: 
	@ echo $(SRC)
	@ echo $(OBJS)
	rm -r $(BUILD_DIR)
	rm tests/*.c

rebuild: clean all

