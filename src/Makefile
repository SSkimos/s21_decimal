CC      = gcc
WARNING = -Wall -Werror -Wextra

SRC_DIR = .

BUILD_DIR  = obj

SRC := $(shell find $(SRC_DIR) -name "s21*.c")
OBJS:= $(SRC:%=$(BUILD_DIR)/%.o)

INC_DIRS := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I, $(INC_DIRS))

CFLAGS  = $(INC_FLAGS) -std=c11 -pedantic $(WARNING)

all: s21_decimal.a check

s21_decimal.a: $(OBJS)
	@mkdir -p $(BUILD_DIR)
	ar rc s21_decimal.a $(OBJS)
	ranlib s21_decimal.a

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(CC)  -c $< -o $@

check:
	checkmk clean_mode=1 tests/conversion_test.check > tests/conversion_test.c
	checkmk clean_mode=1 tests/comparsion_test.check > tests/comparsion_test.c

clean: 
	rm -f $(OBJS)	

rebuild: clean all
