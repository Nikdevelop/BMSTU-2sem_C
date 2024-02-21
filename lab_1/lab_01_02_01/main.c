// TODO

#include <stdio.h>
#include <math.h>

#define ERR_OK 0
#define ERR_IO 1
#define ERR_INPUT 2

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define EPS 1e-8

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

    if (a <= 0 || b <= 0 || phi <= 0)
    {
        printf("a, b or phi is less or equal than 0.\n");
        return ERR_INPUT;
    }

    if (ABS(phi) - EPS > 90)
    {
        printf("Phi cannot be bigger than 90 degrees.\n");
        return ERR_INPUT;
    }

    if (ABS(phi - 90) <= EPS)
        printf("Area equals to %f.\n", a * b);
    else
    {
        s = (b * b - a * a) / 2.0 * tan(phi * 3.14159 / 180.0);
        printf("Area equals to %f\n", s);
    }
    return ERR_OK;
}