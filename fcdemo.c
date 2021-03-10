#include<stdio.h>
int main()
{       FILE *fp;
	char c;
	fp = fopen("abfile","r");
	if(fp == NULL)
	{

	printf("file error");
	return;
	}
	c= fgetc(fp);
	printf("%c",c);
	fclose(fp);
}

