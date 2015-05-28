#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 50
int szu(int *ww,int li)
{int *old=ww,tmp=0;
	do 
	{
		printf("%d ",*ww);
		if(li==*ww)tmp=(ww-old)+1;
	}
	while(*++ww>=0);
	return tmp;
}
int main()
{
	int tab[N],i=0,szukane=5;
	srand(time(0));
	while(i<N){tab[i]=rand()%100;i++;}
	printf("\n\nLiczba %d jest w tablicy o indeksie: %d  jezeli 0 to nie ma.\n",szukane,szu(tab,szukane));
	system("pause");
	return 0;
}
 