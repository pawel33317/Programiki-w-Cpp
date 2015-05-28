#include <stdio.h>

void Strcpy(char *strTo,char *strFrom);

int main()
{
    char napis1[100],napis2[100];
    printf("Program kopiujacy ciag znakow\n");
    printf("Podaj znaki, ktore zostana wczytane do pierwszej tablicy:\n");
    gets(napis1);    
    Strcpy(napis2,napis1);
    printf("Znaki po skopiowaniu do drugiej tablicy: %s\n",napis2);
    system("pause");
    return 0;
}

void Strcpy(char *strTo,char *strFrom)
{
    while(*strFrom!=EOF)
    {
        *strTo=*strFrom;
        strFrom++;
        strTo++;
    }    
}      
        
  
