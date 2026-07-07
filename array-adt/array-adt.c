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
void impress(ArrayADT);

int set(ArrayADT *, int, int);
int delete(ArrayADT *, int);

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
        switch (selection)
        {
        case 1:
            impress(arr);
            break;
        case 2:
            updateValue(&arr);
            break;
        }

        menu();

        printf("#: ");
        scanf("%i", &selection);
    } while (selection != 4);

    printf("Goodbye 🎮");

    return 0;
}

void menu()
{
    printf("1. Print \n");
    printf("2. Set \n");
    printf("3. Delete \n");
    printf("4. Exit \n");
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

void updateValue(ArrayADT *arr)
{
    int index = NO_VALUE;
    int value = NO_VALUE;

    int *data = arr->data;
    int size = arr->size;
    int length = arr->length;

    printf(" 🚩 Assigning Index 🚩 \n");

    do
    {
        printf("Index -> ");
        scanf("%i", &index);

        if (index <= 0)
        {
            printf("Index cannot be equal or lower than zero. \n");
        }
        else if (index > length)
        {
            printf("Index cannot be higher than the length. \n");
        }
    } while (index == NO_VALUE || index <= 0 || index > length);

    printf("🚩 Assigning Value 🚩\n");

    do
    {
        printf("Value (-100000 to 100000) -> ");
        scanf("%i", &value);

        if (value < -100000 || value > 100000)
        {
            printf("Value out of bounds! Please try again.\n");
        }
    } while (value < -100000 || value > 100000);

    int result = set(arr, (index - 1), value);

    if (result == -1)
    {
        printf("❌ Error! There was an error updating the index");
    }
    else
    {
        printf("✅ Value updated!");
    }

    printf("\n");
}

void deleteValue(ArrayADT *arr)
{
}

void impress(ArrayADT arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        printf("| %i | ", arr.data[i]);
    }

    printf("\n");
}

int set(ArrayADT *arr, int index, int value)
{
    int prev = arr->data[index];

    arr->data[index] = value;

    printf("Prev: %i -> New: %i", prev, value);

    return 0;
}

int delete(ArrayADT *arr, int index)
{
    return -1;
}