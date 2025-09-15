#include <stdio.h>
void sort(int k[],int n)
{
    int x,i,j,temp;
    for(i = 1;i<n;i++) {
        if(k[i]<k[i-1]) {
            temp = k[i];
            for(j = i-1;j>=0&&k[j]>temp;j--) {
               k[j+1] = k[j];
                k[j] = temp;
            }
        }
        for(x = 0;x<n;x++) {
            printf("%d ",k[x]);
        }
    }

}
int main(void) {
    int a,c = 0;
    scanf_s("%d",&a);
    int k[a];
    for(c=0;c<a;c++) {
        scanf("%d",&k[c]);
    }
    sort(k,a);
    return 0;
}
