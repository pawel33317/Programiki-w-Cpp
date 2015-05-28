#include <stdio.h>
#include <string.h>
#include <ctype.h>

void wielkie(char *tekst);
void male(char *tekst);

int main()
{
    char tab[30],m,w,wybor;
    printf("Podaj wyraz: ");
    gets(tab);
    printf("Wybierz wielkosc liter, ktorymi zostanie wypisny wyraz: [w] / [m]\n");
    scanf("%c",&wybor);
    switch(wybor)
    {
        case 'w':
            wielkie(tab);   
            break;
        case 'm':
            male(tab);
            break;
    }
    printf("Wyraz przeksztalcony: %s\n",tab);
    system("pause");
    return 0;
}

void wielkie(char *tekst)
{
    while(*tekst!='\0')
    {
        *tekst=toupper(*tekst);
        tekst++;
    }    
}     

void male(char *tekst)
{
    while(*tekst!='\0')
    {
        *tekst=tolower(*tekst);
        tekst++;
    }
}     
    
    
    
    
    
    
    
    
    
    
