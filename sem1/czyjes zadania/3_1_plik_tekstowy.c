#include <stdio.h>

int main()
{
    FILE *f;
    char ch,sciezka[100];
    printf("Podaj sciezke dostepu do pliku tekstowego:\n");
    gets(sciezka);
    f=fopen(sciezka,"r");  
    if(f==0)
    {
        printf("\nPlik nie istnieje!\n");
        system("pause");
        exit(1);
    }
    printf("\nZawartosc pliku:\n");
    while((ch=getc(f))!=EOF)
        printf("%c",ch);
    fclose(f);
    printf("\n");
    system("pause");
    return 0;
}

