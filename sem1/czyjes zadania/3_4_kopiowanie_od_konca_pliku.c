 #include <stdio.h>

void kopiowanie_od_konca_pliku(char*,char*);

int main()
{
    char sciezka_zrodl[100],sciezka_docel[100];
    printf("Podaj sciezke dostepu do pliku zrodlowego:\n");
    gets(sciezka_zrodl);
    printf("Podaj sciezke dostepu do pliku docelowego:\n");
    gets(sciezka_docel);
    kopiowanie_od_konca_pliku(sciezka_zrodl,sciezka_docel);
    printf("\nPlik: [%s] zostal skopiowany (od konca); utworzony plik: [%s]\n",sciezka_zrodl,sciezka_docel);    
    system("pause");
    return 0;
}

void kopiowanie_od_konca_pliku(char *sciezka_zrodl,char *sciezka_docel)
{
    FILE *f1,*f2;
    char ch;
    int a=-1,k=0;
    f1=fopen(sciezka_zrodl,"r"); 
    if(f1==0)
    {
        printf("\nPlik nie istnieje!\n");
        system("pause");
        exit(1);
    }
    f2=fopen(sciezka_docel,"w"); 
    while(a)
    {
        fseek(f1,a,SEEK_END);
        ch=getc(f1);
        a--;
        if(getc(f1)==EOF)
            k++;
        if(k==2)
            break;    
        putc(ch,f2);
    }      
    fclose(f1);
    fclose(f2);
}      

