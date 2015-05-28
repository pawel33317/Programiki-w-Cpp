#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float tab[100];
    int i,n;
    float *wsk;
    printf("Podaj ilosc elementow tablicy: ");
    scanf("%d",&n);
    srand(time(0));
    wsk=tab;
    printf("\nUtworzona tablica:\n");
    for(i=0;i<n;i++)
    {
        *wsk=((float)rand()/(RAND_MAX))*20;
        printf("%f\t",*wsk);
        wsk++;
    }  
    printf("\nCo drugi element tablicy:\n");
    wsk=&tab[1];
    for(i=0;i<n/2;i++)
    {
        printf("\t%f\t",*wsk);
        wsk+=2;
    }  
    printf("\n");
    system("pause");
    return 0;
}
