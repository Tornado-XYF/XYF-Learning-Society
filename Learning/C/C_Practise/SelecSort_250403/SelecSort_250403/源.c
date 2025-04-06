#include <stdio.h>

void InsertSort(int k[], int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		if (k[i] < k[i - 1])
		{
			temp = k[i];
			for (j = i - 1; j >= 0 && k[j] > temp; j--)
			{
				k[j + 1] = k[j];
			}
			k[j + 1] = temp;
		}
	}
}
int main() {
	int i, a[10] = { 5,2,6,0,3,9,1,7,4,8 };
	InsertSort(a, 10);
	for (i = 0; i < 10; i++)
	{
		printf("%d", a[i]);
	}

	return 0;
}
//#include <stdio.h>
//
//void SelectSort(int k[], int n)
//{
//	int i, j, min, temp;
//	for (i = 0; i < n - 1 ; i++)
//	{
//		min = i;
//		for (j = i + 1; j < n; j++)
//		{
//			if (k[j] < k[min])
//			{
//				min = j;
//			}
//		}
//	
//		if (min != i) 
//		{
//		temp = k[min];
//		k[min] = k[i];
//		k[i] = temp;
//		}
//	}
//}
//int main() {
//	int i, a[10] = { 5,2,6,0,3,9,1,7,4,8 };
//
//	SelectSort(a, 10);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d", a[i]);
//	}
//	return 0;
//}
