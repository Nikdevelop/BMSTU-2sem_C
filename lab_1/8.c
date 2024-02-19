// 1 var

#include <math.h>
#include <stdio.h>

#define ERR_OK 0
#define ERR_IO 1
#define ERR_RANGE 2

#define uint unsigned int

void printBinary(uint number)
{
    char isFirstZero = 1; // flag to avoid printing leading zero's
    for (int i = 0; i < 32; ++i)
    {
        if ((number & (1u << (31 - i))) == 0)
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
void printBytes(uint number)
{
    for (int i = 0; i < 4; ++i)
    {
        printf("%u ", ((number & (0xffU << (8 * (3 - i)))) >> (8 * (3 - i))));
    }
    printf("\n");
}
int main(void)
{
    uint result = 0;
    printf("Input bytes: ");
    for (int i = 0; i < 4; ++i)
    {
        uint byte;
        if (scanf("%u", &byte) != 1)
        {
            printf("Error: i/o error\n");
            return ERR_IO;
        }
        if (byte > 255)
        {
            printf("Error: entered value is not valid byte\n");
            return ERR_RANGE;
        }

        result += (uint)byte << (8 * (3 - i));
    }

    printf("Result: ");
    printBinary(result);

    printf("Result: ");
    printBytes(result);
    return ERR_OK;
}

// 225 115 45 1 e1 73 2d 1
// 11100001011100110010110100000001