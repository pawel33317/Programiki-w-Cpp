#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cyfry_parzyste(int);

int main()     
{    
    int i,n,tab[100];
    printf("Podaj liczbe elementow tablicy: ");
    scanf("%d",&n);
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        *(tab+i)=rand()%10000;
        printf("%d\t",*(tab+i));
    }
    printf("\nLiczby utworzone wylacznie z cyfr parzystych:\n");    
    for(i=0;i<n;i++)
    {
        if(cyfry_parzyste(*(tab+i)))
            printf("%d",*(tab+i));
        printf("\t");
    }   
    printf("\n"); 
    system("pause");
    return 0;
}  

int cyfry_parzyste(int liczba)
{
    int cyfra,pozycja=1000,wynik=0;
    do
    {
        cyfra=liczba/pozycja;
        wynik+=cyfra%2;
        liczba-=cyfra*pozycja;
        pozycja/=10;
    }    
    while(pozycja>0);
    if(wynik==0)
        return 1;
    return 0;          
}   
