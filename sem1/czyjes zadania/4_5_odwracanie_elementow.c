#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void odwracanie(int n,int *tab);

int main()     
{
    int i,n,tab[100];
    printf("Podaj liczbe elementow tablicy: ");
    scanf("%d",&n);
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        *(tab+i)=rand()%100;
        printf("%d\t",*(tab+i));
    }    
    odwracanie(n,tab);
    printf("\nElementy odwrocone wzgledem elementu srodkowego:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(tab+i));
    }        
    printf("\n");
    system("pause");
    return 0;
}  

void odwracanie(int n,int *tab)
{
    int i,j,tmp;
    for(i=0,j=n-1;i<n/2;i++,j--)
    {
        tmp=*(tab+i);
        *(tab+i)=*(tab+j);
        *(tab+j)=tmp;
    }
}    

