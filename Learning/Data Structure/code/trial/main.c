#include <stdio.h>
#include <string.h>
int strStr(char* haystack, char* needle) {
    int m = strlen(needle);
    int n = strlen(haystack);
    int x[10000];
    x[0] = -1;
    int z = 0;
    for(int j = 0;j<n;j++)
    {   int y = 0;
        int k = j;
        for(int i = 0;i < m;i++)
        {
            if(haystack[k++] == needle[i])
            {
                continue;
            }
            else
            {
                y = -1;
                break;
            }
        }
        if( y != -1)
        {
            x[z++] = j;
        }
    }
    return x[0];
}

int main()
{
    char a[] = "hello";
    char b[] = "ll";
    printf("%d",strStr(a,b));
    return 0;
}