// 3 var

#include <stdio.h>
#include <math.h>

#define ERR_OK 0
#define ERR_IO 1

#define ABS(X) ((X) < 0 ? -(X) : (X))

int main(void)
{
    float x, e;
    float s, f, cur;
    float errRateAbs, errRateRel;

    int i = 1;

    printf("Input numbers: ");
    if (scanf("%f%f", &x, &e) != 2)
    {
        printf("IO error\n");
        return ERR_IO;
    }

    f = atan(x);
    s = x;
    cur = -pow(x, 3) / (float)(2 * i + 1);
    s += cur;

    while (ABS(cur) > e)
    {
        ++i;
        cur = pow(-1, i) * pow(x, (2 * i + 1)) / (2 * i + 1);
        s += cur;
        // printf("cur %f; prev %f; cur-prev %f\n", cur, prev, ABS(cur - prev)); // dbg
    }

    errRateAbs = ABS(f - s);
    errRateRel = ABS(f - s) / ABS(f);
    
    printf("f(x): %f\ns(x): %f\n", f, s);
    printf("Absolute error rate: %f\nRelative error rate: %f\n", errRateAbs, errRateRel);

    return ERR_OK;
}