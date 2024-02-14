// 3 var

#include <stdio.h>
#include <math.h>

#define ERR_OK 0
#define ERR_IO 1

#define ABS(X) (X) < 0 ? -(X) : (X)

int main(void)
{
    float x, e;
    float s, f, cur;
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

    printf("f(x): %f s(x): %f\n", f, s);
    return ERR_OK;
}