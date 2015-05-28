#include <stdio.h>

int liczba_pierwsza(int);

int main()
{
    int tab[10][10];
    int i,j,n=2;
    int *wsk=&tab[0][0];
    printf("Program wczytujacy do tablicy 10 x 10 liczby pierwsze:\n");
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
        {
            while(liczba_pierwsza(n)!=1)
                n++;
            *(wsk+i*10+j)=n;
            printf("%d\t",*(wsk+i*10+j));
            n++;           
        } 
    printf("Liczby znajdujace sie na polach o obu indeksach podzielnych przez 3:\n");
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            if(i%3==0 && j%3==0)
                printf("%-3d [%d,%d]\t",*(tab[i]+j),i,j); // *(tab[i]+j) = *(*(tab+i)+j) = *(wsk+i*liczba_kolumn+j)
    printf("\n");
    system("pause");
    return 0;
}

int liczba_pierwsza(int n)
{  
    int i;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return 0;
    }    
    return 1;
}
