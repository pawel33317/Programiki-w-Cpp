#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "time.h"
#define N 50
 /*Napisa� program wczytuj�cy do tablicy jednowymiarowej ci�g liczb
ca�kowitych. Wydrukowa� na ekranie kolejno te liczby, kt�re maj� wszystkie
cyfry parzyste. Do przemieszczania si� po elementach tablicy wykorzysta�
wska�niki.*/
int parzyste(int liczba)
{
    int a=1, b, wynik=0;
    while(liczba>10*a)
    a*=10;
    do
    {
          b=liczba/a;
          wynik+=b%2;
          liczba-=b*a;
          a/=10;
    }
    while(a>0);
    if(wynik==0)
    return 1;
    else return 0;
}
int main()
{
	int tab[N];
	int *wtab;
	int i;
	srand(time(0));
	for(wtab=tab;wtab<tab+N;wtab++) *wtab=rand()%1000;
	i=0;
	while (i<N){
	printf("%d: %d\n",i+1,tab[i]);i++;}
	for(wtab=tab;wtab<tab+N;wtab++)if(parzyste(*wtab))printf("\n%d ", *wtab);
	system("pause");
	return 0;
}
