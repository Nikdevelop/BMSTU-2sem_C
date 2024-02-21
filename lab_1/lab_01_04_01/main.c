#include <stdio.h>

#define ERR_OK 0
#define ERR_IO 1

int main(void)
{
    int num;
    int floor, entrance;
    printf("Введите номер квартиры: ");

    if (scanf("%d", &num) != 1)
    {
        printf("Ошибка!\n");
        return ERR_IO;
    }

    entrance = num / (9 * 4);
    floor = (num - entrance * 9*4) / 4;

    printf("%d квартира находится в %d подъезде, %d этаже.\n", num, entrance + 1, floor + 1);
    return ERR_OK;
}