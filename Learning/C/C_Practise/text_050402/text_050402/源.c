/*�������ҵ����գ�������ҽ�����ϰ�ļ���д�Ĵ���
ף�����տ���*/
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
	printf("���ܴ�ʲô���룬��ף�����տ���");
	FILE* pf = fopen("test.txt","r");
	if(pf == NULL)
	{
		char buffer[100];
		strerror_s(buffer, sizeof(buffer), errno);
		return 1;
	}
	//..
	//���ļ�

	//�ر��ļ�
	fclose(pf);
	pf = NULL;

	return 0;
}