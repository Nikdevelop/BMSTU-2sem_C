// 1 var

#include <stdio.h>
#include <math.h>

#define ERR_OK 0
#define ERR_IO 1
#define ERR_RANGE 2

#define uint unsigned int
#define ABS(X) (X) < 0 ? -(X) : (X)

void printBinary(uint number)
{
    char bin[32];
    for (int i = 0; i < 32; ++i)
    {
        bin[i] = number % 2;
        number /= 2;
    }

    for (int i = 31; i >= 0; --i)
        printf("%d", bin[i]);
    printf("\n");
}
void printBytes(uint number)
{
    for (int i = 0; i < 4; ++i)
    {
        printf("%u ", ((number & (0xff << (8 * (3 - i)))) >> (8 * (3 - i))));
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
        if (scanf("%d", &byte) != 1)
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
