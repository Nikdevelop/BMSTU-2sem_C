#include <stdio.h>

#define ERR_OK 0
#define ERR_IO 1

int main(void)
{
    int t;
    printf("Введите время в секундах: ");

    if (scanf("%d", &t) != 1)
    {
        printf("Ошибка!\n");
        return ERR_IO;
    }

    int h = t / 3600, m = (t % 3600) / 60, s = t % 60;

    printf("Это равно %d часов, %d минут, %d секунд.\n", h, m, s);
    return ERR_OK;
}