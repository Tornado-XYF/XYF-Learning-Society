// #include <stdio.h>
// #define M 5
// #define N 5
// void Merge(int a[], int b[], int c[], int m, int n);
// int main(void)
// {
//     int a[N], b[N], c[M+N];
//     int i, m, n;
//     printf("Input m,n:");
//     scanf("%d,%d", &m, &n);
//     printf("Input array a:");
//     for (i=0; i<m; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//     printf("Input array b:");
//     for (i=0; i<n; i++)
//     {
//         scanf("%d", &b[i]);
//     }
//     Merge(a, b, c, m, n);
//     for (i=0; i<m+n; i++)
//     {
//         printf("%d\t", c[i]);
//     }
//     printf("\n");
//     return 0;
// }
// //函数功能：将升序排列的a数组中的m个元素和b数组中的n个元素合并到c数组中
// void Merge(int a[], int b[], int c[], int m, int n)
// {   int j , i ,temp=0;
//     /*************** Begin ***************/
//     for(j = 0,i = 0;i<m+n;i++)
//     {
//         if(i<m) {
//             c[i] = a[i];
//         }
//         else
//         {
//             c[i] = b[j];
//             j++;
//         }
//     }
//     for(i = 0;i<m+n-1;i++) {
//         for(j = 0;j<m+n-i-1;j++) {
//             if(c[j]>c[j+1])
//             {
//                 temp = c[j+1];
//                 c[j+1] = c[j];
//                 c[j] = temp;
//             }
//         }
//     }
//
// }
//
//     /*************** End ***************/
#include <stdio.h>
//定义main函数
int main()
{   char a;
    //请在此添加‘输入一个字符，按规定格式输出该字符ASCII码’的代码
    /*****************Begin******************/
    printf("输入一个字符，按规定格式输出该字符的ASCII码");
    a = getchar();
    printf("\"The ASCII of '%c' is %d\"",a,a);
    /***************** End ******************/
    return 0;
}
