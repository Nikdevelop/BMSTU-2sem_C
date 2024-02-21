// 1 var

#include <stdio.h>
#include <math.h>

#define ERR_OK 0
#define ERR_IO 1
#define ERR_COUNT 2

#define ABS(X) (X) < 0 ? -(X) : (X)

int main(void)
{
    float input = 0, tmp = 0;
    int count = 0;
    float result = 0;
    printf("Input nums: ");

    while (input >= 0)
    {
        if (scanf("%f", &input) != 1)
        {
            printf("Error: i/o error\n");
            return ERR_IO;
        }
        if (input > 0)
            tmp += sqrt(input / (count + 1));
        count++;
    }
    if (count == 1)
    {
        printf("You have not entered positive values!\n");
        return ERR_COUNT;
    }
    result = sin(tmp);
    printf("g(x) = %f\n", result);
    return ERR_OK;
}