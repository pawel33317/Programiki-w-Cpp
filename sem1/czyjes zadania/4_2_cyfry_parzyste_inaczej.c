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
    if((liczba/1000)%2+((liczba%1000)/100)%2+((liczba%100)/10)%2+((liczba%10))%2==0)
        return 1;
    return 0;            
}      
