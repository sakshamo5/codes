#include <stdio.h>

void insertionSort(int A[], int n) {
    int i, j, key;
    for (j = 1; j < n; j++) {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

int main() {
    int A[] = {12, 11, 13, 5, 6};
    int n = sizeof(A) / sizeof(A[0]);

    insertionSort(A, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
