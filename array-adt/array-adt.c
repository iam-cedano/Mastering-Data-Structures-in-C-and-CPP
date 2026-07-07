#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NO_VALUE INT_MIN

typedef struct
{
    int *data;
    int size;
    int length;
} ArrayADT;

void menu();
void startup(ArrayADT *);
void updateValue(ArrayADT *);
void deleteValue(ArrayADT *);

void set(int *, int, int);
void delete(int *, int, int);

int main()
{
    ArrayADT arr;
    arr.data = NULL;
    arr.size = 0;
    arr.length = NO_VALUE;

    startup(&arr);

    int selection = NO_VALUE;

    do
    {
        menu();

        switch (selection)
        {
        case 1:
            // updateValue(&arr);
            break;
        case 2:
            // deleteValue(&arr);
            break;
        }

        printf("#: ");
        scanf("%i", &selection);
    } while (selection != 3);

    printf("Goodbye 🎮");

    return 0;
}

void menu()
{
    printf("1. Set \n");
    printf("2. Delete \n");
    printf("3. Exit \n");
}

void startup(ArrayADT *arr)
{
    int size = 0;
    int length = NO_VALUE;
    int *data = NULL;

    printf("Length -> ");
    scanf("%i", &length);

    data = (int *)malloc(sizeof(int) * length);

    for (int i = 0; i < length; i++)
    {
        data[i] = NO_VALUE;
    }

    for (int i = 0; i < length; i++)
    {
        int value = NO_VALUE;

        printf("#: ");
        scanf("%i", &value);

        data[i] = value;

        size++;
    }

    arr->data = data;
    arr->length = length;
    arr->size = size;

    system("clear");
}