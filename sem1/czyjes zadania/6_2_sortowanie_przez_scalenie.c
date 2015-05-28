#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sortowanie_przez_scalanie(int *tab,int poczatek,int koniec);
void scalanie(int *tab,int poczatek,int koniec);

int main(void)
{
    int i,n,tab[100];
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
    int i,i1,i2,srodek,temp[koniec+1];
    for(i=0;i<=koniec;i++)
        *(temp+i)=*(tab+i);
    srodek=(poczatek+koniec)/2;
    i=poczatek;
    i1=poczatek;
    i2=srodek+1;
    while(i1<=srodek && i2<=koniec)
    {
        if(*(temp+i1)<*(temp+i2))
        {
            *(tab+i)=*(temp+i1);
            i1++;                    
        }        
        else
        {
            *(tab+i)=*(temp+i2);
            i2++;   
        }    
        i++;
    }    
    if(i1>srodek)
        while(i2<=koniec)
        {
            *(tab+i)=*(temp+i2);
            i2++;
            i++;                    
        }        
    else
        while(i1<=srodek)
        {
            *(tab+i)=*(temp+i1);
            i1++;
            i++;                    
        }        
}    
