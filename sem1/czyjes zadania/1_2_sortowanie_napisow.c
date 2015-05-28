#include <stdio.h>
#include <string.h>
#include <ctype.h>

int zliczanie_malych_liter(char[][],int);
void sort_proste(char[][],int[],int);
void wypisywanie_tablicy(char[][],int);

int main()
{
    int i,n,tab_male_litery[10];
    char tab[10][50];
    printf("Program wczytujacy n napisow podanych przez uzytkownika, [n<10]\n");
    printf("Podaj ilosc napisow: n = ");
    scanf("%d",&n);    
    fflush(stdin);
    for(i=0;i<n;i++)
    {
        printf("\nPodaj %d napis: ",i+1);
        gets(tab[i]);
        tab_male_litery[i]=zliczanie_malych_liter(tab,i);
    } 
    sort_proste(tab,tab_male_litery,n);
    printf("\nNapisy posortowane malejaco wzgledem liczby malych liter:\n"); 
    wypisywanie_tablicy(tab,n);
    system("pause");
    return 0;
}

int zliczanie_malych_liter(char tab[][50],int j)
{
    int i=0,male_litery=0;
    while(tab[j][i]!='\0')
    {
        if(islower(tab[j][i]))
            male_litery++; 
        i++;
    }     
    return male_litery;     
}    

void sort_proste(char tab_napisy[][50],int tab_male_litery[],int n)
{
    int i,j,k,tmp;
    char tmp_napisy[50];
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(tab_male_litery[j]>tab_male_litery[k])
                k=j;
        }    
        tmp=tab_male_litery[i];        
        tab_male_litery[i]=tab_male_litery[k];
        tab_male_litery[k]=tmp;    
        strcpy(tmp_napisy,tab_napisy[i]);
        strcpy(tab_napisy[i],tab_napisy[k]);
        strcpy(tab_napisy[k],tmp_napisy);   
    }        
}

void wypisywanie_tablicy(char tab[][50],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%s\n",tab[i]);     
}      
        
  
