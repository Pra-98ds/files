`#include<stdio.h>
int main()
{
	FILE *fp1,*fp2;
	char ch;
	fp1 = fopen("file1","r");
	fp2 = fopen("file2","w");
	do
	{
		ch = fgetc(fp1);
		if(ch == EOF)
		{
		break;
	}
	else

		fputc(ch,fp2);
	}

	while(ch !=EOF);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
