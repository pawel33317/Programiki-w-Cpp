#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char tab[100];
    int i,n;
    printf("Podaj ilosc elementow tablicy: ");
    scanf("%d",&n);
    srand(time(0));
    printf("\nUtworzona tablica:\n");
    for(i=0;i<n;i++)
    {
        *(tab+i)=(char)65+rand()%26;
        printf("%c\t",*(tab+i));
    }  
    printf("\nCo drugi element tablicy:\n");
    for(i=1;i<n/2+1;i++)
        printf("\t%c\t",*(tab+2*i-1));
    printf("\n");
    system("pause");
    return 0;
}
