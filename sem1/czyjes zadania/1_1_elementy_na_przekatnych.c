#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()     
{
    int i,j,k,l,m,n,tab[10][10];
    double wynik=1;
    printf("Podaj liczbe wierszy macierzy: ");
    scanf("%d",&m);
    printf("Podaj liczbe kolumn macierzy: ");
    scanf("%d",&n);
    srand(time(0));
    printf("\nUtworzona macierz:\n");       
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            tab[i][j]=1+rand()%100;
            printf("%d\t",tab[i][j]);                   
        }
        printf("\n");  
    }
    printf("\nPodaj wspolrzedne punktu, w ktorym przecinaja sie przekatne [indeksy >= 0]:\n");
    do
    {        
        scanf("%d%d",&k,&l);
        if(k<0 || k>m-1 || l<0 || l>n-1)
            printf("Bledne wspolrzedne!, podaj ponownie:\n");
    }  
    while((k<0) || (k>m-1) || (l<0) || (l>n-1));  
    printf("\nelementy w lewo-gora od punktu:\n");
    for(i=k-1;i>=0;i--)
    {
        j=l-k+i;
        if(j<0)
            break;
        printf("%d\t",tab[i][j]);
        wynik*=tab[i][j];    
    }
    printf("\nelementy w prawo-dol od punktu:\n");
    for(i=k+1;i<m;i++)
    {
        j=l-k+i;
        if(j>=n)
            break;
        printf("%d\t",tab[i][j]);
        wynik*=tab[i][j];  
    }   
    printf("\nelementy w prawo-gora od punktu:\n"); 
    for(i=k-1;i>=0;i--)
    {
        j=l+k-i;
        if(j>=n)
            break;
        printf("%d\t",tab[i][j]); 
        wynik*=tab[i][j];         
    }
    printf("\nelementy w lewo-dol od punktu:\n");
    for(i=k+1;i<m;i++)
    {
        j=l+k-i;
        if(j<0)
            break;
        printf("%d\t",tab[i][j]);    
        wynik*=tab[i][j];         
    }   
    printf("\nIloczyn elementow na przekatnych przecietych w podanym punkcie: %.lf\n",wynik*tab[k][l]);
    system("pause");
    return 0;
}  

