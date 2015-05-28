// DLA ZMIENNO PRZECINKOWYCH
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int main()
{
	int tabi[10],i,*wski=tabi;
	char tabc[10], *wskc=tabc;
	float tabf[10], *wskf=tabf;
	srand(time(0));

	printf("TABLICA LICZB CALKOWITYCH\n");
	for(i=0;i<10;i++){*(wski+i)=rand()%100;printf("%d   ",*(wski+i));}
	printf("\n");
	for(i=0;i<10;i+=2){printf("%d   ",*(wski+i));}
	printf("\n");
 
	printf("TABLICA LICZB ZMIENNOPRZECINKOWYCH\n");
	for(i=0;i<10;i++){*(wskf+i)=rand()%1000;*(wskf+i)=*(wskf+i)/100;printf("%.2f   ",*(wskf+i));}
	printf("\n");
	for(i=0;i<10;i+=2){printf("%.2f   ",*(wskf+i));}
	printf("\n");
	
	printf("TABLICA TYPU ZNAKOWEGO\n");
	for(i=0;i<10;i++){    *(wskc+i)=rand()%25+65;    printf("%c   ",*(wskc+i));}
	printf("\n");
	for(i=0;i<10;i+=2){printf("%c   ",*(wskc+i));}
	printf("\n");
 
system("pause");
return 0;
}