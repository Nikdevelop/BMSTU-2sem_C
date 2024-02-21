#include <stdio.h>

#define ERR_OK 0
#define ERR_IO 1

int main(void)
{
    float v1, t1, v2, t2, resV, resT;
    printf("Enter data: ");
    if (scanf("%f%f%f%f", &v1, &t1, &v2, &t2) != 4)
    {
        printf("IO error\n");
        return ERR_IO;
    }

    resV = v1 + v2;
    resT = (v1 * t1 + v2 * t2) / (v1 + v2);
    printf("Total water: %f l. Total temp: %.2f C*\n", resV, resT);

    return ERR_OK;
}