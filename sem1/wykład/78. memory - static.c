#include <stdio.h>
#include <stdlib.h>
int fun()
{	
int k=5;
static int t=17; //  !=== static int t; t=17;
printf("k= %d\n static t= %d\n",k,t);
k=t=100;
}
int main()
{	
	fun();
	fun();
	fun();
	fun();
	fun();
	system("PAUSE");	
	return 0;
}
/* Je�eli mamy co� w pami�ci statycznej przy kolejnym 
wej�ciu do funkcji b�dzie to co ustawili�my przy poprzednim*/