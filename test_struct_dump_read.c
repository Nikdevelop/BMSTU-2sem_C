#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 20

typedef struct
{
    char firstName[NAME_SIZE];
    char lastName[NAME_SIZE];
    unsigned age;
} myStruct;

void dumpMyStruct(myStruct* ptr, FILE* fp)
{
    if (fp == NULL)
        return;

    fwrite(ptr, sizeof(myStruct), 1, fp);
}
void readMyStruct(myStruct* ptr, FILE* fp)
{
    if (fp == NULL)
        return;

    fread(ptr, sizeof(myStruct), 1, fp);
}
int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);

    myStruct* data = (myStruct*)malloc(sizeof(myStruct));
    strcpy(data->firstName, "qwerty");
    strcpy(data->lastName, "uiop");
    data->age = 10;

    FILE* fp = fopen("test.bin", "wb");
    dumpMyStruct(data, fp);
    fclose(fp);

    myStruct *readFromFile = (myStruct*)malloc(sizeof(myStruct));
    fp = fopen("test.bin", "rb");
    readMyStruct(readFromFile, fp);
    fclose(fp);

    printf("%s %s %d\n", readFromFile->firstName, readFromFile->lastName, readFromFile->age);
    return 0;
}