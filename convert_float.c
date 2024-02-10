#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ABS(X) (X) < (0) ? (-X) : (X)
#define MAX_PREC 10
#define EPS 1e-4

double my_round(double x, unsigned int digits) 
{
    double fac = pow(10, digits);
    return round(x * fac) / fac;
}
char* convert(double number, int base)
{
    char* alph = "0123456789ABCDEF";
    char* result = (char*)malloc(sizeof(char) * 100);

    int integerPart = (int)number;
    double realPart = number - integerPart;

    // convert integral part of number into base
    size_t iSize = 0;
    while (integerPart > 0)
    {
        char* symbol = (char*)malloc(sizeof(char) * 2);
        symbol[0] = alph[integerPart % base];
        symbol[1] = '\0';
        strcat(result, symbol);
        integerPart /= base;
        ++iSize;

        free(symbol);
    }
    strcat(result, ".");
    for (int i = 0;i < iSize / 2;++i)
    {
        char temp = result[i];
        result[i] = result[iSize - i - 1];
        result[iSize - i - 1] = temp;
    }

    // convert real part of number into base
    int i = 0;
    while (i++ < MAX_PREC || (ABS(realPart)) <= EPS)
    {
        realPart *= base;
        char* curInt = (char*)malloc(sizeof(char) * 5);
        sprintf(curInt, "%d", (int) my_round(realPart, 2));
        strcat(result, curInt);

        if (realPart >= 1)
            realPart -= (int)realPart;
    }
    return result;
}

int main(void)
{
    printf("%s\n", convert(1231.156, 15));
    return 0;
}