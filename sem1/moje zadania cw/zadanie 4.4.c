#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
int minn(int *ww,int li)
{
	int tmp=*ww,i=0;
	while(i<li)
	{
		printf("%d ",*(ww+i));
		if(tmp>=*(ww+i))tmp=*(ww+i);
		i++;
	}
	/*do 
	{
		printf("%d ",*ww);
		if(tmp>=*ww)tmp=*ww;
	}
	while(*++ww>0);*/
	return tmp;
}
int main()
{
	int tab[20],i=0;
	srand(time(0));
	while(i<20){tab[i]=rand()%100;i++;}
	printf("\n\nMin: %d\n",minn(tab,N));
	system("pause");
	return 0;
}
 