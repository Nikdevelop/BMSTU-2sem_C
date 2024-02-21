// 1 var

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define ERR_OK 0
#define ERR_IO 1
#define ERR_RANGE 2


void printBinary(uint32_t number)
{
    char isFirstZero = 1; // flag to avoid printing leading zero's
    for (int i = 0; i < sizeof(uint32_t) * CHAR_BIT; ++i)
    {
        if ((number & ((uint32_t)1 << (31 - i))) == 0)
        {
            if (!isFirstZero)
                printf("0");
        }
        else
        {
            isFirstZero = 0;
            printf("1");
        }
    }

    printf("\n");
}

void unpackBytes(uint32_t number, int *b1, int *b2, int *b3, int *b4)
{
    *b4 = number & 0xff;
    number >>= CHAR_BIT;
    *b3 = number & 0xff;
    number >>= CHAR_BIT;
    *b2 = number & 0xff;
    number >>= CHAR_BIT;
    *b1 = number & 0xff;
}

int main(void)
{
    uint32_t result = 0;
    printf("Input bytes: ");
    for (int i = 0; i < sizeof(uint32_t); ++i)
    {
        uint32_t byte;
        if (scanf("%u", &byte) != 1)
        {
            printf("Error: i/o error\n");
            return ERR_IO;
        }
        if (byte > 0xff)
        {
            printf("Error: entered value is not valid byte\n");
            return ERR_RANGE;
        }

        result += (uint32_t)byte << (CHAR_BIT * (sizeof(uint32_t) - 1 - i));
    }

    printf("Result: ");
    printBinary(result);
    int b1, b2, b3, b4;

    unpackBytes(result, &b1, &b2, &b3, &b4);
    printf("Result: %d %d %d %d\n", b1, b2, b3, b4);

    return ERR_OK;
}

// 225 115 45 1 e1 73 2d 1
// 11100001011100110010110100000001
