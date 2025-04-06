#include<stdio.h>

void bubble_sort(int arr[], int n) 
{
	int i, j, temp;
	for(i = 0; i < n-1;i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
};
int main(void) {
	int arr[] = { 6,5,3,1,8,7,2,4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
