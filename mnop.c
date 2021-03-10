#include<stdio.h>
int main()
{       FILE *fp;
	char c;
	int len,i,count=0;
	fp = fopen("abfile","r");
	if(fp == NULL)
	{

	printf("file error");
	return;
	}
	for(i=1;i<=21;i++)
	{
	count++;
	fseek(fp,-(i),SEEK_END);
	c=fgetc(fp);
	printf("%c",c);
	}
	fclose(fp);
}

