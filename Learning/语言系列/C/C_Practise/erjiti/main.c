#include<stdio. h>

void fun(char *c, int d)

{

    *c=*c+1;

    d=d+1;

    printf("%c, %c,", *c,d );

}

int main()

{

    char b=' a' ,a='A';

    fun(&b,a);
    printf("%c, %c\n”,b,a) ;

    return 0;
    }
