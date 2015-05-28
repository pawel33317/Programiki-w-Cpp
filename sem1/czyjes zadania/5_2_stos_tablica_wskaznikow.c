#include <stdio.h>
#include <stdlib.h>

void push(int element,int *stos[],int *sp,int max);
int pop(int *stos[],int *sp);
int size(int *stos[],int *sp);
int clear(int *stos[],int *sp);
int isEmpty(int *stos[],int *sp);
void print(int *stos[],int *sp);
int getElement(int *stos[], int indeks);

int main()
{
    int element,i,rozmiar,tmp,top=0;
    int *wsk[100],*sp=&top;
    char odp,operacja;    
    printf("Podaj maksymalny rozmiar stosu: ");    
    scanf("%d",&rozmiar);
    for(i=0;i<rozmiar;i++)
        wsk[i]=(int*)malloc(sizeof(int)); 
    do
    {
        system("cls");
        printf("Wybierz operacje, ktora zostanie przeprowadzona na stosie:\n");
        printf("\n\tPush[p] / Pop[o] / Size[s] / Clear[c] / Is empty[e] / Print[r]\n");
        printf("\n\tGet element[g] / Exit[x]...\t");
        fflush(stdin);
        scanf("%c",&operacja);
        system("cls");  
        switch(operacja)
        {
            case 'p':
                do
                {
                    printf("Podaj [%d] element stosu: ",top);
                    scanf("%d",&element);
                    push(element,wsk,sp,rozmiar);                    
                    printf("\tPowtorzenie operacji[Enter] / Zmiana operacji[z]...\t");
                    fflush(stdin);
                    if((odp=getchar())=='z')
                        break;
                }
                while(top<=rozmiar);
                break;
            case 'o':
                do
                {
                    tmp=top;
                    element=pop(wsk,sp);
                    if(tmp>0)
                        printf("Element [%d] o wartosci: %d zostal zdjety\n",top,element);
                    printf("\tPowtorzenie operacji[Enter] / Zmiana operacji[z]...\t");
                    fflush(stdin);
                    if((odp=getchar())=='z')
                        break;
                }    
                while(top>=0);
                break;
            case 's':
                do
                {
                    printf("Aktualny rozmiar stosu: %d\n",size(wsk,sp));  
                    printf("\tPowtorzenie operacji[Enter] / Zmiana operacji[z]...\t");
                    fflush(stdin); 
                    if((odp=getchar())=='z')
                        break;
                }    
                while(top>=0);
                break;
            case 'c':
                do
                {
                    tmp=top;
                    clear(wsk,sp);
                    if(tmp)
                        printf("Wszystkie elementy zostaly usuniete\n");  
                    printf("\tPowtorzenie operacji[Enter] / Zmiana operacji[z]...\t");
                    fflush(stdin); 
                    if((odp=getchar())=='z')
                        break;
                }    
                while(top>=0);
                break;
            case 'e':
                do
                {
                    if(isEmpty(wsk,sp))
                        printf("Stos jest pusty\n");
                    else
                        printf("Stos nie jest pusty\n");
                    printf("\tPowtorzenie operacji[Enter] / Zmiana operacji[z]...\t");
                    fflush(stdin); 
                    if((odp=getchar())=='z')
                        break;
                }   
                while(top>=0); 
                break;
            case 'r':
                do
                {
                    print(wsk,sp);
                    printf("\tPowtorzenie operacji[Enter] / Zmiana operacji[z]...\t");
                    fflush(stdin); 
                    if((odp=getchar())=='z')
                        break;
                }    
                while(top>=0);
                break;
            case 'g':
                do
                {
                    printf("Podaj indeks elementu, ktory ma zostac wyswietlony: ");
                    scanf("%d",&tmp);
                    if(!top)
                        printf("Brak elementow na stosie!\n");
                    else if(tmp>top-1)
                        printf("Niepoprawny indeks; aktualny rozmiar stosu zostal przekroczony!\n");
                    else 
                        printf("Wartosc wybranego elementu: %d\n",getElement(wsk,tmp));     
                    printf("\tPowtorzenie operacji[Enter] / Zmiana operacji[z]...\t");
                    fflush(stdin); 
                    if((odp=getchar())=='z')
                        break;
                }    
                while(top>=0);
                break;
            case 'x': 
                printf("Zakonczenie programu...\n");
                break;
        }    
    }
    while(operacja!='x');
    for(i=0;i<rozmiar;i++)
        free(wsk[i]);
    system("PAUSE");	
    return 0;
}

void push(int element,int *stos[],int *sp,int max)
{
    if(*sp>=max)
        printf("Stos jest pelny - element [%d] nie zostanie dolaczony!\n",*sp);    
    else
    {
        *(stos[*sp])=element;
        (*sp)++;
    }         
}

int pop(int *stos[],int *sp)
{
    if(*sp==0)
        printf("Nie mozna pobrac elementu; stos jest pusty!\n");
    else
        return *(stos[(--(*sp))]);
}

int size(int *stos[],int *sp)
{    
    return *sp;
}    
    
int clear(int *stos[],int *sp)
{
    if(*sp==0)
        printf("Na stosie nie ma elementow!\n");
    return *sp=0;
}    

int isEmpty(int *stos[],int *sp)
{
    if(*sp==0)
        return 1;
    return 0;
}    
void print(int *stos[],int *sp)
{
    int tmp=*sp;
    if(*sp)
    {
        *sp=0;
        do
        {
            printf("%d\t",*(stos[*sp]));
            (*sp)++;
        }
        while(tmp!=*sp);  
        printf("\n"); 
    }    
    else
        printf("Brak elementow!\n");
}    

int getElement(int *stos[], int indeks)
{
    return *(stos[indeks]);
} 
