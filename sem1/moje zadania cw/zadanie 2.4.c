#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
void duze(char *ta){do *ta=toupper(*ta);while(*ta++);}
void male(char *ta){do *ta=tolower(*ta);while(*ta++);}
int main()
{
	char tab[20],int i;
	printf("Podaj wyraz: ");
	scanf("%s",tab);
	printf("1 - duze\n2 - male");
	scanf("%d",&i);
	if(i==1)duze(tab);
	else male(tab);
	printf("%s\n",tab);

system("pause");
return 0;
}