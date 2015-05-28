#include<stdlib.h>
#include<stdio.h>
 
int main()
{
	int a=5;
	int *wsk=&a;
	printf("wartosc zmiennej a (bezposrednio): %d\n",a);
	printf("wartosc zmiennej a poprzez wskaznik wsk: %d\n",*wsk);
	printf("wartosc adresu zmiennej a bezpoœrednio: %d\n",&a);
	printf("wartosc adresu zmiennej a poprzez wskaznik wsk: %d\n",wsk);
 
system("pause");
return 0;
}
 