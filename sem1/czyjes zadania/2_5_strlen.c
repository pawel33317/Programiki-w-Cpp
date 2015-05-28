#include <stdio.h>

int strlen(char *tekst);

int main()
{
    char tab[50];
    printf("Podaj lancuch znakowy: ");
    gets(tab);
    printf("Podany lancuch znakowy sklada sie z %d znakow\n",strlen(tab));
    system("pause");
    return 0;
}

int strlen(char *tekst) 
{
    int dlugosc=0;
    while(*tekst!='\0')
    {
        dlugosc++;
        tekst++;
    } 
    return dlugosc;
}    
    
