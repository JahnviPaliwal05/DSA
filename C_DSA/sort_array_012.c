//Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

#include <stdio.h>

void sortArr(int arr[], int n) {
    int ct0 = 0;
    int ct1 = 0;
    int ct2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            ct0++;
        } else if (arr[i] == 1) {
            ct1++;
        } else {
            ct2++;
        }
    }

    for (int i = 0; i < ct0; i++) {
        arr[i] = 0;
    }

    for (int i = ct0; i < ct0 + ct1; i++) {
        arr[i] = 1;
    }

    for (int i = ct0 + ct1; i < n; i++) {
        arr[i] = 2;
    }
}

int main() {
    int n = 6;
    int arr[6] = {0, 2, 1, 2, 0, 1};
    sortArr(arr, n);
    printf("After sorting the array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
