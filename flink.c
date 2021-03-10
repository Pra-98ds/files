#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct employees
{
   int data;
   char name[30];
};
FILE *fp=NULL,*fp1=NULL;
void searchu(int,int *,int *);
typedef struct employees emp;
int ch=0;
int main()
{
	do
	{
	 menu();
	 printf("enter your choice");
	scanf("%d",&ch);
	 switch(ch)
	 {
	   case 1: create(); break;
	   case 2: read(); break;
	   case 3: update(); break;
	 //  case 4: delete(); break;
	 // case 5: search(); break;
	  case 6:exit(1); break;
	  default : printf("wrong choice..");
	}
	}while(ch!=6);
	 return 0;
}
void menu()
{
	printf("\n1.create \n 2.read \n 3.update\n 4.delete\n5.search\n 6.exit");
}
void create()
{ 
   emp e1,e2,e3;
   fp = fopen("afile","wb");
   if(fp == NULL)
  {
     printf("file error");
     return;
  }
	e1.data=10;
	e2.data=20;
	e3.data=30;
	strcpy(e1.name,"raj");
	strcpy(e2.name,"sarj");
	strcpy(e3.name,"mrig");

	fwrite(&e1,1,sizeof(e1),fp);
	fwrite(&e2,1,sizeof(e2),fp);
	fwrite(&e3,1,sizeof(e3),fp);
   
    fclose(fp);
}
void read()
{
	emp e1,e2,e3;
	fp=fopen("afile","rb");
	if(fp==NULL)
	{
		printf("file error");
		return;
	}
	fread(&e1,1,sizeof(e1),fp);
	printf("[%d %s]\n",e1.data,e1.name);

	fread(&e2,1,sizeof(e2),fp);
	printf("[%d %s]\n",e2.data,e2.name);

	fread(&e3,1,sizeof(e3),fp);
	printf("[%d %s]\n",e3.data,e3.name);
	
	fclose(fp);
}
void update()
{
	emp e;
	int found=0,pos=0;

	
	printf("enter emp id and new name to update");
	scanf("%d",&e.data);
	scanf("%s",e.name);
	fp = fopen("afile","r+");
	searchu(e.data,&found,&pos);
	if(fp==NULL)
	{
		printf("file error");
		return;
	}
	fseek(fp,sizeof(e) * (pos-1),SEEK_SET);
	fwrite(&e,1,sizeof(e),fp);
	fclose(fp);
	
}
void searchu(int data1,int *found,int *pos)
{
	emp e1;
	int count=0,flag=0;
	fp1 = fopen("afile","rb");
	while(fread(&e1,1,sizeof(e1),fp) > 0)
	{	
		count++;
		if(e1.data == data1)
		{
			flag=1;
			break;
		}

	}	
	if(flag==0)
	{
		printf("not found");
		fclose(fp1);
		exit(1);
	}
	else
	{
		*pos=count;
		*found=1;
	}
	fclose(fp1);
	
}
