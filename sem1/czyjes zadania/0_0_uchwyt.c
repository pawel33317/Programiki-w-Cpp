#include <io.h>
#include <fcntl.h>

int main()
{
    char sciezka[100],tekst[100],wybor,znak;
    int plik;
    do
    {
        system("cls");
        printf("Utworzenie nowego pliku     [1]\n");
        printf("Otwarcie istniejacego pliku [2]\n");
        printf("Zakonczenie programu        [3]\n");
        scanf("%c",&wybor);
        switch(wybor)
        {
            case '1':
                printf("Podaj sciezke do pliku, ktory zostanie utworzony:\n");
                scanf("%s",sciezka);
                printf("Podaj tekst, ktory zostanie zapisany w pliku:\n");
                scanf("%s",tekst);
                plik=open(sciezka,O_CREAT|O_WRONLY|O_TEXT);
                write(plik,tekst,strlen(tekst));
                close(plik);
                break;
            case '2':
                printf("Podaj sciezke do pliku, ktory zostanie otworzony:\n");
                scanf("%s",sciezka);
                plik=open(sciezka,O_RDONLY|O_TEXT);
                printf("Zawartosc pliku:\n");
                do
                {
                    read(plik,&znak,1);
                    printf("%c",znak);
                }   
                while(!eof(plik));
                printf("\n");
                system("pause");
                close(plik);
                break;
            case '3':
                printf("Zakonczenie programu\n");
                break;
        }    
    }    
    while(wybor!='3');                          
    system("PAUSE");	
    return 0;
}
