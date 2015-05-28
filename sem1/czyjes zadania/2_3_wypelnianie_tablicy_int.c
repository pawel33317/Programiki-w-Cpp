#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,n,tab[100];
    int *wsk=tab;
    printf("Podaj ilosc elementow tablicy: ");
    scanf("%d",&n);
    srand(time(0));
    printf("\nUtworzona tablica:\n");
    for(i=0;i<n;i++)
    {
        *wsk=rand()%100;
        printf("%d\t",*wsk);
        wsk++;
    }  
    printf("\nCo drugi element tablicy:\n");
    wsk=&tab[1];
    for(i=0;i<n/2;i++)
    {
        printf("\t%d\t",*wsk);
        wsk+=2;
    }  
    printf("\n");
    system("pause");
    return 0;
}
