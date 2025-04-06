# Date Structures and Algorithms

## 排序算法

### 冒泡排序

冒泡排序是一种简单的排序算法。它重复地走访过要排序的数列，一次比较两个相邻元素，如果它们的顺序错误就把它们交换过来。走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。

冒泡排序算法的运作如下：

1. 比较相邻的元素。如果第一个比第二个大，就交换它们两个；
2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
3. 针对所有的元素重复以上的步骤，除了最后一个；

例如，用C语言对数列[6, 5, 3, 1, 8, 7, 2, 4]进行冒泡排序：

```.
#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; 
            } 
        } 
    }

}
int main() {
    int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, n); 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
```

### 选择排序

选择排序是一种简单直观的排序算法，无论什么数据进去都是 O(n²) 的时间复杂度。所以用到它的时候，数据规模越小越好。唯一的好处可能就是不占用额外的内存空间了吧。

选择排序(Selection-sort)是一种简单直观的排序算法。它的工作原理：首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。

例：

```.
#include <stdio.h>

void SelectSort(int k[], int n)
{
int i, j, min, temp;
for (i = 0; i < n - 1 ; i++)
{
min = i;
for (j = i + 1; j < n; j++)
{
if (k[j] < k[min])
{
min = j;
}
}

if (min != i) 
{
temp = k[min];
k[min] = k[i];
k[i] = temp;
}
}
}
int main() {
int i, a[10] = { 5,2,6,0,3,9,1,7,4,8 };

SelectSort(a, 10);
for (i = 0; i < 10; i++)
{
printf("%d", a[i]);
}
return 0;
}
```

### 插入排序

插入排序（Insertion Sort）的算法描述是一种简单直观的排序算法。它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。

插入排序算法的运作如下：

1. 从第一个元素开始，该元素可以认为已经被排序；
2. 取出下一个元素，在已经排序的元素序列中从后向前扫描；
3. 如果该元素（已排序）大于新元素，将该元素移到下一位置；
4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
5. 将新元素插入到该位置后；

例：

```.
#include <stdio.h>

void InsertSort(int k[], int n)
{
int i, j, temp;
for (i = 1; i < n; i++)
{
if (k[i] < k[i - 1])
{temp = k[i];
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
```

### 希尔排序

希尔排序是希尔（Donald Shell）于1959年提出的一种排序算法。希尔排序也是一种插入排序，它是简单插入排序经过改进之后的一个更高效的版本，也称为缩小增量排序，同时该算法是冲破O（n2）的第一批算法之一。
希尔排序是把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；随着增量逐渐减少，每组包含的关键词越来越多，当增量减至1时，整个文件恰被分成一组，算法便终止。

例：

```.
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

```

### 堆排序

堆排序（Heapsort）是指利用堆这种数据结构所设计的一种排序算法。堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。

例：
