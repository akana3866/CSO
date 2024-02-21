#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void selectionsort(int *arr, int size) {
    int i, j, min, temp;
    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (*(arr + j) < *(arr + min)) {
                min = j;
            }
        }
        if (min != i) {
            temp = *(arr + i);
            *(arr + i) = *(arr + min);
            *(arr + min) = temp;
        }
    }
    printArray(arr, size);
}

void bubbleSort(int *arr, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
    printArray(arr, size);
}

int main() {
    srand(42);

    int arr[20];
    int i;
    for (i = 0; i < 20; i++) {
        int num = (rand() % 50) + 1;
        *(arr + i) = num;
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);

    printf("Bubble Sorted array: \n");
    bubbleSort(arr, n);

    printf("Selection Sorted array: \n");
    selectionsort(arr, n);

    return 0;
}
