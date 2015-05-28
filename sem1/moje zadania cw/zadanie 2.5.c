#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
int lenstr(char *ta){int i=0;do i++;while(*ta++);return i-1;}
int lenstrr(char *ta){char *old=ta; do {} while(*ta++); return (ta-old-1);}
int main()
{
	char tab[20],*d=tab;int i;
	printf("Podaj wyraz: ");
	scanf("%s",tab);
	printf("Wyraz %s ma %d znakow.\n",tab,lenstr(tab));
	printf("Wyraz %s ma %d znakow. (inna metoda)\n",tab,lenstrr(tab));
system("pause");
return 0;
}