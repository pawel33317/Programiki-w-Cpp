#include <stdio.h>

int main()
{
    FILE *f;
    char ch,sciezka[100];
    int rozmiar=0;  
    printf("Podaj sciezke dostepu do pliku tekstowego:\n");
    gets(sciezka);
    f=fopen(sciezka,"r");  
    if(f==0)
    {
        printf("\nPlik nie istnieje!\n");
        system("pause");
        exit(1);
    }    
    while((ch=getc(f))!=EOF)
        if(ch=='\n')
           rozmiar+=2;
        else
           rozmiar++;
    printf("\nRozmiar pliku: %d",rozmiar);
    fclose(f);
    printf("\n");
    system("pause");
    return 0;
}

