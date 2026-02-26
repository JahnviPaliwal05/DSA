// Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.
//If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).



#include <stdio.h>
#include <stdlib.h>

void reverse(int* arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void nextGreaterPermutation(int* A, int n) {
    int ind = -1;

    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        reverse(A, 0, n - 1);
        return;
    }

    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            int temp = A[i];
            A[i] = A[ind];
            A[ind] = temp;
            break;
        }
    }
    reverse(A, ind + 1, n - 1);
}

int main() {
    int A[] = {2, 1, 5, 4, 3, 0, 0};
    // int ct = 0;
    // printf("The series: [");
    // while(A != NULL){
    //     printf("%d",A[ct]);
    //     ct++;
    // }


   
    int n = sizeof(A) / sizeof(A[0]);
    
    nextGreaterPermutation(A, n);

    printf("The next permutation is: [");
    for (int i = 0; i < n; i++) {
        printf("%d", A[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("]\n");

    return 0;
}