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
    }

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int x = 0;x<n;x++) {
        scanf("%d",arr[x]);
    }
    bubble_sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}