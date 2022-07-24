#ifndef UTILITS_S21_STRUCTURES_H_
#define UTILITS_S21_STRUCTURES_H_

<<<<<<< HEAD
#define MINUS_SIGN 4294967295;

typedef struct {
    unsigned int bits[4];
=======
typedef union {
    uint64_t bits64[2];
    uint32_t bits32[4];
    uint16_t bits16[8];
    uint8_t bits8[16];
    int32_t bits[4];
>>>>>>> 53d082257116282ab6e02b564cfb1ecf245453c1
} s21_decimal;

typedef enum {
    CONVERTATION_OK = 0,
    CONVERTATION_ERROR = 1
} convertation_result;

#endif