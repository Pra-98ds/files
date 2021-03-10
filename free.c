#include<stdio.h>
int main()
{       FILE *fp;
	char c;
	int len;
	fp = fopen("abfile","r");
	if(fp == NULL)
	{

	printf("file error");
	return;
	}
	c= fgetc(fp);
	printf("%c",c);
	fseek(fp,0,SEEK_END);
	len = ftell(fp);
	printf("size is %d",len);
	fclose(fp);
}

