#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int znajdz_min(int n,int *tab);

int main()     
{
    int i,n,tab[100];
    int *wsk=tab;
    printf("Podaj liczbe elementow tablicy: ");
    scanf("%d",&n);
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        *wsk=rand()%100;
        printf("%d\t",*wsk);
        wsk++;
    }    
    printf("\nElement minimalny w tablicy: %d\n",znajdz_min(n,tab));
    system("pause");
    return 0;
}  

int znajdz_min(int n,int *tab)
{
    int i,min;
    min=(*tab);
    for(i=1;i<n;i++)    
        if(min>*(tab+i))
            min=(*(tab+i));        
    return min;               
}    

