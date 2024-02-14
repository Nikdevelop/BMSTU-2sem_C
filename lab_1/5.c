#include <stdio.h>
#include <math.h>
// 3 var

#define ERR_OK 0
#define ERR_IO 1

#define MIN(a, b) (a) < (b) ? (a) : (b)


unsigned int NOD(unsigned int a, unsigned int b)
{
    unsigned int result = MIN(a, b);
    while (result)
    {
        if (a % result == 0 && b % result == 0)
            return result;
        result--;
    }

    return -1;
}
int main(void)
{
    unsigned int a, b;
    unsigned int nod;
    if (scanf("%d%d", &a,&b) != 2)
    {
        printf("IO error\n");
        return ERR_IO;
    }
    
    nod = NOD(a, b);
    printf("nod for %d and %d is %d\n", a, b, nod);

    return 0;
}