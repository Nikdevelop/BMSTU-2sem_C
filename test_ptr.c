#include <stdio.h>

int main(void)
{
    int a = 1337;
    int* pA = &a;
    printf("%p %p", pA, &a);
    return 0;
}