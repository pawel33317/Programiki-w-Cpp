#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int copyss(char *tab,char *tabb)
{
	int i=0;
	do
	{
		*(tabb+i)=*tab;
		i++;
	}
	while(*tab++);
	return 0;
}
int main()
{
	char tab[]="dziala :D";
	char tabc[10]="";
	copyss(tab,tabc);
	printf("%s\n",tabc);
	system("pause");
	return 0;
}
 