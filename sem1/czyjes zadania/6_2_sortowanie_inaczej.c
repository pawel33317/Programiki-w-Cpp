#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sortowanie_przez_scalanie(int *tab,int poczatek,int koniec);
void scalanie(int *tab,int poczatek,int koniec);

int main(void)
{
    int i,n,tab[100],tmp[100];
    printf("Podaj liczbe elementow ciagu: ");
    scanf("%d",&n);
    srand(time(NULL));
    for(i=0;i<n;i++)
        *(tab+i)=rand()%10;
    printf("\nCiag przed sortowaniem:\n");
    for(i=0;i<n;i++)
        printf("%d\t",*(tab+i));
    sortowanie_przez_scalanie(tab,0,n-1);
    printf("\nCiag po sortowaniu:\n");
    for(i=0;i<n;i++)
        printf("%d\t",*(tab+i));
    printf("\n");
    system("pause");
    return 0;
}

void sortowanie_przez_scalanie(int *tab,int poczatek,int koniec)
{    
    int srodek;
    srodek=(poczatek+koniec)/2;
    if(poczatek<srodek)
        sortowanie_przez_scalanie(tab,poczatek,srodek);
    if(srodek+1<koniec)
        sortowanie_przez_scalanie(tab,srodek+1,koniec);
    scalanie(tab,poczatek,koniec);
}

void scalanie(int *tab,int poczatek,int koniec)
{
    int i,j,k,tmp;
    for(i=poczatek;i<=koniec;i++)
    {
        k=i;
        for(j=i+1;j<=koniec;j++)
            if(tab[j]<tab[k])
                k=j;
        tmp=tab[k];
        tab[k]=tab[i];
        tab[i]=tmp;  
    }
}
