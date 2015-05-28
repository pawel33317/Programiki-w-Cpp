#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int znajdz(int,int[][]);

int main()     
{
    int i,j,k,szukany,tab[10][10];
    srand(time(NULL));
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
        {
            *(tab[i]+j)=rand()%100;
            printf("%d\t",*(tab[i]+j));
        }         
    printf("\nPodaj wartosc szukanego elementu [liczba calk. od 0 do 99]: ");
    scanf("%d",&szukany);
    k=znajdz(szukany,tab);  
    printf("Indeks szukanego elementu: ");
    if(k>10)
        printf("[%d]\n",k);
    else if(k>=0) 
        printf("[0%d]\n",k);
    else
        printf("Element o podanej wartosci nie zostal znaleziony\n");
    system("pause");
    return 0;
}  

int znajdz(int szukany,int tab[][10])
{
    int i,i_tmp,j,j_tmp=-1;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            if(*(tab[i]+j)==szukany)
            {
                i_tmp=i;
                j_tmp=j;
            }
    if(j_tmp==-1)
        return -1; 
    return i_tmp*10+j_tmp;               
}
