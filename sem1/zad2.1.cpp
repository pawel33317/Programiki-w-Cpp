#include<stdlib.h>
#include<stdio.h>

int main()
{
int a;
int *wsk;

a=5;
wsk=&a;
printf("wartosc zmiennej a (bezposrednio): %d\n",a);
printf("wartosc zmiennej a poprzez wskaznik wsk: %d\n",*wsk);
*wsk=10;
printf("zmiana wartosci zmiennej na 10n");
printf("wartosc zmiennej a po zmianie: %d\n",a);
       
    
system("pause");
return 0;
}
