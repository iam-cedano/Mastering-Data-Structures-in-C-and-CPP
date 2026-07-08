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
void impress(ArrayADT);

void setValue(ArrayADT *);
void deleteValue(ArrayADT *);
void insertValue(ArrayADT *);

int set(ArrayADT *, int, int);
int delete(ArrayADT *, int);

void rearrange(ArrayADT *);

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
            setValue(&arr);
            break;
        case 3:
            deleteValue(&arr);
            break;
        case 4:
            rearrange(&arr);
            break;
        }

        menu();

        printf("#: ");
        scanf("%i", &selection);
    } while (selection != 5);

    printf("Goodbye 🎮");

    return 0;
}

void menu()
{
    printf("1. Print \n");
    printf("2. Set \n");
    printf("3. Delete \n");
    printf("4. Rearrange \n");
    printf("5. Exit \n");
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

void setValue(ArrayADT *arr)
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
        printf("❌ Error! There was an error updating the index \n");
    }
    else
    {
        printf("✅ Value updated! \n");
    }

    printf("\n");
}

void deleteValue(ArrayADT *arr)
{
    int index = NO_VALUE;
    int lenght = arr->length;

    do
    {
        printf("Index (1 to %i) -> ", lenght);
        scanf("%i", &index);

        if (index <= 0 || index > lenght)
        {
            printf("❌ Error! Index is out of the bonds! \n");
            printf("Insert the value again \n");
        }
        else
        {
            printf("✅ Value updated!");
        }
    } while (index <= 0 || index > lenght);

    printf("🚩 Deleting the value 🚩");

    int realIndex = index - 1;

    int result = delete(arr, realIndex);

    if (result == -1)
    {
        printf("❌ Deletion failed! \n");
    }
    else
    {
        printf("✅ Deletion successful \n");
    }
}

void impress(ArrayADT arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        if (arr.data[i] == NO_VALUE)
        {
            printf("| NULL |");
        }
        else
        {
            printf("| %i | ", arr.data[i]);
        }
    }

    printf("\n");
}

int set(ArrayADT *arr, int index, int value)
{
    int prev = arr->data[index];

    arr->data[index] = value;

    return 0;
}

int delete(ArrayADT *arr, int index)
{
    int valueToDelete = arr->data[index];

    if (valueToDelete == NO_VALUE)
    {
        return -1;
    }

    arr->data[index] = NO_VALUE;

    return 0;
}

void rearrange(ArrayADT *arr)
{
    int replacerCheckpoint = 0;

    for (int i = 0; i < arr->length; i++)
    {
        int value = arr->data[i];

        if (value == NO_VALUE && replacerCheckpoint == 0)
        {
            int j = i + 1;

            while (j < arr->length)
            {
                int replacer = arr->data[j];

                if (j == arr->length - 1)
                {
                    replacerCheckpoint = -1;
                }

                if (replacer != NO_VALUE)
                {
                    arr->data[i] = replacer;
                    arr->data[j] = NO_VALUE;
                }

                j++;
            }
        }
    }
}