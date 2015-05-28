#include <stdio.h>
#include <stdlib.h>

void push(int element,int *stos,int *sp);
int pop(int *stos,int *sp);
int size(int *stos,int *sp);
int clear(int *stos,int *sp);
int isEmpty(int *stos,int *sp);
void print(int *stos,int *sp);
int getElement(int *stos, int indeks);

int main()
{
    int element,tmp,top=0;
    int *sp=&top,*wsk=NULL,*wsk_tmp;
    char odp,operacja;   
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
                    wsk_tmp=(int*)realloc(wsk,(*sp+1)*sizeof(int));
                    wsk=wsk_tmp;
                    printf("Podaj [%d] element stosu: ",top);
                    scanf("%d",&element);
                    push(element,wsk,sp);              
                    printf("\tPowtorzenie operacji[Enter] / Zmiana operacji[z]...\t");
                    fflush(stdin);
                    if((odp=getchar())=='z')
                        break;
                }
                while(1);
                break;
            case 'o':
                do
                {
                    tmp=top;
                    element=pop(wsk,sp);
                    if(tmp>0)
                    {
                        wsk_tmp=(int*)realloc(wsk,(*sp)*sizeof(int));
                        wsk=wsk_tmp;    
                        printf("Element [%d] o wartosci: %d zostal zdjety\n",top,element);
                    }    
                    printf("\tPowtorzenie operacji[Enter] / Zmiana operacji[z]...\t");
                    fflush(stdin);
                    if((odp=getchar())=='z')
                        break;
                }    
                while(1);
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
                while(1);
                break;
            case 'c':
                do
                {
                    tmp=top;
                    clear(wsk,sp);
                    if(tmp)
                    {
                        free(wsk);
                        printf("Wszystkie elementy zostaly usuniete\n");  
                    }    
                    printf("\tPowtorzenie operacji[Enter] / Zmiana operacji[z]...\t");
                    fflush(stdin); 
                    if((odp=getchar())=='z')
                        break;
                }    
                while(1);
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
                while(1); 
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
                while(1);
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
                while(1);
                break;
            case 'x':                 
                printf("Zakonczenie programu...\n");
                break;
        }    
    }
    while(operacja!='x');
    free(wsk);
    system("PAUSE");	
    return 0;
}

void push(int element,int *stos,int *sp)
{       
    *(stos+(*sp))=element;
    (*sp)++;         
}

int pop(int *stos,int *sp)
{
    int tmp;
    if(*sp==0)
        printf("Nie mozna pobrac elementu; stos jest pusty!\n");
    else
    {
        tmp=(*(stos+(--(*sp))));
        return tmp;
    }    
}

int size(int *stos,int *sp)
{    
    return *sp;
}    
    
int clear(int *stos,int *sp)
{
    if(*sp==0)
        printf("Na stosie nie ma elementow!\n");
    return *sp=0;
}    

int isEmpty(int *stos,int *sp)
{
    if(*sp==0)
        return 1;
    return 0;
}    
void print(int *stos,int *sp)
{
    int tmp=*sp;
    if(*sp)
    {
        *sp=0;
        do
        {
            printf("%d\t",*(stos+(*sp)));
            (*sp)++;
        }
        while(tmp!=*sp);  
        printf("\n"); 
    }    
    else
        printf("Brak elementow!\n");
}    

int getElement(int *stos, int indeks)
{
    return *(stos+indeks);
} 
