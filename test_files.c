#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("You didn't specify file to read!\n");
        return -1;
    }

    FILE* fp;
    fp = fopen(argv[1], "r");
    char cur;
    while ((cur = fgetc(fp)) != EOF)
        printf("%c", cur);
    fclose(fp);
    printf("\n");
    return 0;
}