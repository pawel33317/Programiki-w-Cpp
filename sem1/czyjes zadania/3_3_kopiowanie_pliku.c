#include <stdio.h>

int main()
{
    FILE *f1,*f2;
    char ch,sciezka_zrodl[100],sciezka_docel[100];
    printf("Podaj sciezke dostepu do pliku zrodlowego:\n");
    gets(sciezka_zrodl);    
    f1=fopen(sciezka_zrodl,"r");  
    if(f1==0)
    {
        printf("\nPlik nie istnieje!\n");
        system("pause");
        exit(1);
    }
    printf("Podaj sciezke dostepu do pliku docelowego:\n");
    gets(sciezka_docel);
    f2=fopen(sciezka_docel,"w");  
    while((ch=getc(f1))!=EOF)
        putc(ch,f2);
    printf("\nPlik: [%s] zostal skopiowany; utworzony plik: [%s]\n",sciezka_zrodl,sciezka_docel);
    fclose(f1);
    fclose(f2);
    system("pause");
    return 0;
}

