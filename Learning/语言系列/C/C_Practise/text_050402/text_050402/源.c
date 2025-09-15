/*今天是我的生日，这段是我今天练习文件读写的代码
祝我生日快乐*/
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
	printf("不管打什么代码，先祝我生日快乐");
	FILE* pf = fopen("test.txt","r");
	if(pf == NULL)
	{
		char buffer[100];
		strerror_s(buffer, sizeof(buffer), errno);
		return 1;
	}
	//..
	//读文件

	//关闭文件
	fclose(pf);
	pf = NULL;

	return 0;
}