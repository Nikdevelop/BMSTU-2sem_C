#include <stdio.h>
#include <math.h>

#define ERR_OK 0
#define ERR_IO 1

int main()
{
    float a, b, phi;
    float s;
    printf("Enter a, b, phi: ");
    if (scanf("%f%f%f", &a, &b, &phi) != 3)
    {
        printf("IO error\n");
        return ERR_IO;
    }

    s = (a + b) / 2.0 * tan(phi * 3.14 / 180.0) * (b - a) / 2;
    printf("Area equals to %f\n", s);
    return ERR_OK;
}