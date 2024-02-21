// 3 var

#include <stdio.h>

#define ERR_OK 0
#define ERR_IO 1

int main(void)
{
    float xq, yq, xr, yr, xp, yp;
    float k, b, yRes;

    printf("Input numbers: ");
    if (scanf("%f%f%f%f%f%f", &xq, &yq, &xr, &yr, &xp, &yp) != 6)
    {
        printf("IO error\n");
        return ERR_IO;
    }

    k = (yr - yq) / (xr - xq);
    b = yq - k * xq;

    yRes = k * xp + b;

    if (yRes < yp)
        printf("0\n");
    else if (yRes == yp)
        printf("1\n");
    else
        printf("2\n");

    return 0;
}