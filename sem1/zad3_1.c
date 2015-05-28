#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main ()
{
    int i;int j;int k; int tab[10][10]; int lp; int *(*(wsk))=tab;
    i=0; lp = 2;
    while (i<=9)
    {
        j=0; 
        while (j<=9)
        {        
                k=2;
                while (k<lp)
                {
                      if (lp%k==0){k=2;lp++;}
                      k++;
                }
                *(*(tab+i)+j)=lp;
                lp++;
        j++;
        } 
        i++;
    }
    i=0;
    while (i<=9)
    {
        j=0; 
        while (j<=9)
        {       
                if(i%3==0 && j%3==0) 
                 printf("%6d",*(*(tab+i)+j));
         j++;
        } 
         printf("\n");
        i++;
    }




    system("pause");
    }
