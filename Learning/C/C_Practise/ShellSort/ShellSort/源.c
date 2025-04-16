#include <stdio.h>
void ShellSort(int k[], int n)
{
	int i, j, gap;
	int temp;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			temp = k[i];
			for (j = i - gap; j >= 0 && k[j] > temp; j -= gap)
			{
				k[j + gap] = k[j];
			}
			k[j + gap] = temp;
		}
	}
}
int main() {
	int i, a[10] = { 5,2,6,0,3,9,1,7,4,8 };
	ShellSort(a, 10);
	for (i = 0; i < 10; i++)
	{
		printf("%d", a[i]);
	}
	return 0;
}