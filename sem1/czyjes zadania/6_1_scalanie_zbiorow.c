#include<stdio.h>
#include<stdlib.h>

void sort_proste(int *tab,int n);
void scalanie(int *tab1,int *tab2,int *tab,int ilosc1,int ilosc2);

int main(void)
{
    int i,ilosc1,ilosc2;
    int *tab1,*tab2,*tab;
    printf("Podaj ilosc elementow pierwszego zbioru: ");
    scanf("%d",&ilosc1);
    tab1=(int*)malloc(ilosc1*sizeof(int));
    for(i=0;i<ilosc1;i++)
    {
        printf("\tPodaj %d element pierwszego zbioru: ",i+1);
        scanf("%d",&*(tab1+i));
    }    
    sort_proste(tab1,ilosc1);
    printf("Podaj ilosc elementow drugiego zbioru: ");
    scanf("%d",&ilosc2);
    tab2=(int*)malloc(ilosc2*sizeof(int));
    for(i=0;i<ilosc2;i++)
    {
        printf("\tPodaj %d element drugiego zbioru: ",i+1);
        scanf("%d",&*(tab2+i));
    }    
    sort_proste(tab2,ilosc2);
    system("cls");
    printf("Pierwszy zbior:\n");
    for(i=0;i<ilosc1;i++)
        printf("%d\t",*(tab1+i));
    printf("\nDrugi zbior:\n");
    for(i=0;i<ilosc2;i++)
        printf("%d\t",*(tab2+i));
    tab=(int*)malloc((ilosc1+ilosc2)*sizeof(int));
    scalanie(tab1,tab2,tab,ilosc1,ilosc2);
    printf("\nZbior utworzony przez scalenie:\n");    
    for(i=0;i<ilosc1+ilosc2;i++)
        printf("%d\t",*(tab+i));
    printf("\n");
    system("pause");
    free(tab1);
    free(tab2);
    free(tab);
    return 0;
}

void sort_proste(int *tab,int n)
{
    int i,j,k,tmp;
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(tab[j]<tab[k])
                k=j;
        }    
        tmp=tab[i];
        tab[i]=tab[k];
        tab[k]=tmp;          
    }
}  

void scalanie(int *tab1,int *tab2,int *tab,int ilosc1,int ilosc2)
{    
    int i=0,j=0,k,ilosc;
    ilosc=ilosc1+ilosc2;
    for(k=0;k<ilosc;k++)
    {
        if(tab1[i]<tab2[j])
        {
            tab[k]=tab1[i];
            i++;
        }
        else
        {
            tab[k]=tab2[j];
            j++;
        }     
    }
}
    
              
    
