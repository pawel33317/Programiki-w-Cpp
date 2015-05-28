#include <stdio.h>

int rozmiar(char *sciezka);

int main()
{    
    char sciezka[100];
    printf("Podaj sciezke dostepu do pliku tekstowego:\n");
    gets(sciezka);
    printf("\nRozmiar pliku: %d",rozmiar(sciezka));
    printf("\n");
    system("pause");
    return 0;
}

int rozmiar(char *sciezka)
{
    FILE *f;
    char ch;
    int rozmiar;
    f=fopen(sciezka,"r");  
    if(f==0)
    {
        printf("\nPlik nie istnieje!\n");
        system("pause");
        exit(1);
    }    
    fseek(f,0,SEEK_END);
    rozmiar=ftell(f);
    fclose(f);
    return rozmiar;
}


