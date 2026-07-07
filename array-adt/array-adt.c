#include <stdio.h>

typedef struct {
    int* data;
    int size;
    int length;
} ArrayADT;

void menu();
ArrayADT createArrayADT(int*, int, int);
void set(int*, int, int);
void delete(int*, int, int);

int main() {
    return 0;
}