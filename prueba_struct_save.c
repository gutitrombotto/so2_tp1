#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    char nim[11];
    char name[50];
    int year;
};

#define BUFFER_SIZE 100

struct student saveToStruct (char* str)
{
    struct student res;
    int flag = 0;
    char *token = strtok(str, "#"); 

    while( token != NULL )
    {
        if (0 == flag)
            strcpy(res.nim, token);
        else if (1 == flag)
            strcpy(res.name, token);
        else
            res.year = atoi(token);

        flag++;
        token = strtok( NULL, "#" ); 
    }
    return res;
}
void print(struct student* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s, %s, %d\n", arr[i].nim, arr[i].name, arr[i].year);
    }
}
int cmp(const void* l, const void* r)
{
    return strcmp(((const student*)l)->name, ((const student*)r)->name);
}
int main()
{
    struct student arr[10];
    FILE* file = fopen("mhs.txt", "r");
    if (!file)
        return -1;

    char buffer[BUFFER_SIZE];
    int flag = 0;
    while (fgets(buffer, BUFFER_SIZE, file))
    {
        arr[flag] = saveToStruct(buffer);
        flag++;
    }
    print(arr, 10);

    qsort(arr, 10, sizeof(struct student), cmp);
    printf("After sort by name!\n");
    print(arr, 10);
    return 0;
}