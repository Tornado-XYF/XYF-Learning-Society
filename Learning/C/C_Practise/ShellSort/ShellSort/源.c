#include <stdio.h>
#include<stdlib.h>
#define N 100
void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (int x = 0; x < n; x++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    
    }

}
int main()
{
    /********** Begin **********/
    int i, n;
    scanf_s("%d", &n);
    int arr[10];
    for (i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }
    bubble_sort(arr, n);

    /********** End **********/
    return 0;
}

//#include <stdio.h>
//void ShellSort(int k[], int n)
//{
//	int i, j, gap;
//	int temp;
//	for (gap = n / 2; gap > 0; gap /= 2)
//	{
//		for (i = gap; i < n; i++)
//		{
//			temp = k[i];
//			for (j = i - gap; j >= 0 && k[j] > temp; j -= gap)
//			{
//				k[j + gap] = k[j];
//			}
//			k[j + gap] = temp;
//		}
//	}
//}
//int main() {
//	int i, a[10] = { 5,2,6,0,3,9,1,7,4,8 };
//	ShellSort(a, 10);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d", a[i]);
//	}
//	return 0;
//}