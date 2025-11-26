#include <stdio.h>

void sorting(float Arr[][5], int n) {
    for (int j = 1; j < n; j++) {
        float temp[5];
        for (int t = 0; t < 5; t++) {
            temp[t] = Arr[j][t];
        }
        int i = j - 1;
        while (i >= 0 && Arr[i][2] < temp[2]) {
            for (int t = 0; t < 5; t++) {
                Arr[i + 1][t] = Arr[i][t];
            }
            i--;
        }
        for (int t = 0; t < 5; t++) {
            Arr[i + 1][t] = temp[t];
        }
    }
}

int main() {
    int n;
    float capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of bag: ");
    scanf("%f", &capacity);

    float A[n][5];
    for (int i = 0; i < n; i++) {
        printf("Enter the value of item %d: ", i + 1);
        scanf("%f", &A[i][1]);
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%f", &A[i][0]);
        A[i][2] = A[i][1] / A[i][0];  // value/weight ratio
        A[i][3] = 0;  // fraction
        A[i][4] = i + 1; // item number
    }

    sorting(A, n);

    float value = 0;
    int i = n - 1;
    while (i >= 0 && capacity > 0) {
        if (A[i][0] <= capacity) {
            capacity -= A[i][0];
            value += A[i][1];
            A[i][3] = 1;
        } else {
            A[i][3] = capacity / A[i][0];
            value += A[i][1] * A[i][3];
            capacity = 0;
        }
        i--;
    }

    printf("Items selected (value, weight, ratio, fraction):\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f %.2f %.2f %.2f\n", A[i][1], A[i][0], A[i][2], A[i][3]);
    }
    printf("Value collected: %.2f\n", value);

    return 0;
}
