#include <stdio.h>
#include<stdlib.h>
#define N 100

void bubble_sort(int arr[], int n) {
    int j, temp;
        for (j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    }

int main() {
    int n = 5;
    int arr[5] ={5,10,2,1,0};
    bubble_sort(arr, n);
    return 0;
}