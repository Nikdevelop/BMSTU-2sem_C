#include <stdio.h>
#define __USE_MISC
#include <math.h>

int main()
{
    float a, b, phi;
    float s;
    printf("Enter a, b, phi: ");
    scanf("%f%f%f", &a, &b, &phi);

    s = (a + b) / 2.0 * tan(phi * M_PI / 180.0) * (b - a) / 2;
    printf("Area equals to %f\n", s);
    return 0;
}