#include<stdio.h>
#include<string.h>

struct student 
{
    char imie[20];
    char nazwisko[20];    
    int numer_indeksu;
    char kierunek[20];
    char wydzial[20];
    int rok_studiow;
    
};    //    s1;    lub    struct student s1;

void drukuj(struct student *s);
void wypelnij(struct student *s,char *imie,char *nazwisko,int numer_indeksu,char *kierunek,char *wydzial,int rok_studiow);

int main(void)
{
    char imie[20],nazwisko[20],kierunek[20],wydzial[20];
    int i=0,n,numer_indeksu,rok_studiow;
    struct student *wsk_student;
    printf("Podaj liczbe studenow: ");
    scanf("%d",&n);
    wsk_student=(struct student*)malloc(n*sizeof(struct student));
    do
    {
        printf("\nPodaj imie %d studenta: ",i+1);
        scanf("%s",imie);
        printf("Podaj nazwisko %d studenta: ",i+1);
        scanf("%s",nazwisko);        
        printf("Podaj numer indeksu %d studenta: ",i+1);    
        scanf("%d",&numer_indeksu);
        printf("Podaj kierunek studiow %d studenta: ",i+1);    
        scanf("%s",kierunek);
        printf("Podaj wydzial %d studenta: ",i+1);    
        scanf("%s",wydzial);
        printf("Podaj rok studiow %d studenta: ",i+1);    
        scanf("%d",&rok_studiow);
        wypelnij(wsk_student+i,imie,nazwisko,numer_indeksu,kierunek,wydzial,rok_studiow);
        i++;
    }
    while(i<n);
    i=0;
    printf("\nDane studentow:\n");
    do
    {
        drukuj(wsk_student+i);  
        i++;
    }
    while(i<n);
    printf("\n");  
    free(wsk_student);
    system("pause");    
    return 0;
}

void drukuj(struct student *s)
{
    printf("\n%20s\t%20s\t%20d\n",s->nazwisko,s->imie,s->numer_indeksu);
    printf("%20s\t%20s\t%20d\n",s->kierunek,s->wydzial,s->rok_studiow);
}

void wypelnij(struct student *s,char *imie,char *nazwisko,int numer_indeksu,char *kierunek,char *wydzial,int rok_studiow)
{
    strcpy(s->nazwisko,nazwisko);
    strcpy(s->imie,imie);  
    s->numer_indeksu = numer_indeksu;
    strcpy(s->kierunek,kierunek); 
    strcpy(s->wydzial,wydzial); 
    s->rok_studiow = rok_studiow;
}

