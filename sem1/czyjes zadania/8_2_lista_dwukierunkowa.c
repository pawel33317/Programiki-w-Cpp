#include <stdio.h>
#include <stdlib.h>

struct node
{          
    struct node *next;
    struct node *prev;  
    int val;  
};
      
struct list
{
    struct node *head;
    struct node *tail;
};

void add_begin(int val,struct list *l);
void add_end(int val,struct list *l);
void add_el(int val,int n,struct list *l);
void print_forward(struct list *l);
void print_backward(struct list *l);
void print_el(int n,struct list *l);
void remove_el(int n,struct list *l);
int size_l(struct list *l);

int main()
{
    char operacja,wybor;
    int element,n;
    struct list *wsk_list;
    wsk_list=(struct list*)malloc(sizeof(struct list));
    do
    {
        system("cls");
        printf("Wybierz operacje, ktora zostanie przeprowadzona na liscie:\n");
        printf("\n\tDodaj element [d] / Usun element [u] / Wyswietl [w] / Rozmiar [r]\n");
        printf("\tZakonczenie [x]: ");
        fflush(stdin);
        scanf("%c",&operacja);
        system("cls");  
        switch(operacja)
        {
            case 'd':
                do
                {
                    printf("Podaj element: ");
                    fflush(stdin);
                    scanf("%d",&element);
                    printf("\tUmiesc element na liscie:\n");
                    printf("\tna poczatek [Enter] / na koniec [z] / na wybrana pozycje [q]: ");   
                    fflush(stdin);                 
                    scanf("%c",&wybor); 
                    if(wybor=='q')
                    {
                        printf("Podaj indeks, pod ktory zostanie dodany element: ");  
                        scanf("%d",&n);  
                        add_el(element,n,wsk_list); 
                    }                            
                    else if(wybor=='z')
                        add_end(element,wsk_list);  
                    else
                        add_begin(element,wsk_list);
                    printf("\n\tPowtorzenie operacji [Enter] / Zmiana operacji [z]: ");
                    fflush(stdin);
                    if(getchar()=='z')
                        break;         
                    printf("\n");           
                }    
                while(1);
                break;
            case 'u':     
                printf("Podaj indeks elementu, ktory zostanie usuniety: ");   
                scanf("%d",&n);        
                remove_el(n,wsk_list);
                system("pause");
                break;
            case 'r':
                printf("Rozmiar listy: %d\n",size_l(wsk_list));
                system("pause");
                break;
            case 'w':
                printf("Wyswietlenie listy: od poczatku [Enter] / od konca [z] / dowolny element [d]: ");
                fflush(stdin);
                scanf("%c",&wybor);        
                if(wybor=='d')
                {
                    printf("Podaj indeks elementu, ktory zostanie wyswietlony: ");  
                    scanf("%d",&n);                    
                    print_el(n,wsk_list);
                }
                else if(wybor=='z')
                    print_backward(wsk_list);
                else
                    print_forward(wsk_list);
                printf("\n");
                system("pause");
                break;
            case 'x':
                printf("Zakonczenie programu...");
                break;
        }
    }
    while(operacja!='x'); 
    free(wsk_list);
    printf("\n");
    system("pause");
    return 0;
}   

void add_begin(int val,struct list *l)
{
    struct node *wsk=(struct node*)malloc(sizeof(struct node));
    wsk->next=NULL;
    wsk->prev=NULL;
    wsk->val=val;
    if(l->head==NULL)
    {
        l->head=wsk;
        l->tail=wsk;
    }
    else
    {
        wsk->next=l->head;
        l->head->prev=wsk;
        l->head=wsk;
    }
}

void add_end(int val,struct list *l)
{
    struct node *wsk=(struct node*)malloc(sizeof(struct node));
    wsk->next=NULL;
    wsk->prev=NULL;
    wsk->val=val;
    if(l->head==NULL)
    {
        l->head=wsk;
        l->tail=wsk;
    }
    else
    {
        wsk->prev=l->tail;
        l->tail->next=wsk;
        l->tail=wsk;
    }
}

void add_el(int val,int n,struct list *l)
{
    int i=0,rozmiar;
    struct node *wsk;
    struct node *el;
    rozmiar=size_l(l);    
    if(n>rozmiar)
    {
        printf("Podany indeks wykracza poza pozycje, na ktorej moze zostac umieszczony element!\n");        
        free(wsk);
    }  
    else
    {
        if(n==0)     
            add_begin(val,l);
        else if(n==rozmiar)   
            add_end(val,l); 
        else
        {
            wsk=(struct node*)malloc(sizeof(struct node));
            el=l->head;
            while(i!=n) 
            {
                el=el->next;
                i++;
            }                 
            wsk->next=el;           
            wsk->prev=el->prev;           
            wsk->val=val;           
            wsk->next->prev=wsk;   
            wsk->prev->next=wsk;            
        }          
    }        
} 

void print_forward(struct list *l)
{    
    struct node *el;
    el=l->head;    
    do
    {
        if(l->head==NULL)
        {
            printf("Brak elementow!"); 
            break;
        }    
        printf("%d\t",el->val);
        el=el->next;
    }
    while(el!=l->tail->next);
}

void print_backward(struct list *l)
{
    struct node *el;
    el=l->tail;
    do
    {
        if(l->head==NULL)
        {
            printf("Brak elementow!");
            break;
        }    
        printf("%d\t",el->val);
        el=el->prev;
    }
    while(el!=l->head->prev);
}

void print_el(int n,struct list *l)
{
    int i=0,rozmiar;
    struct node *el;    
    rozmiar=size_l(l);    
    if(l->head==NULL)
        printf("Brak elementu - lista nie zawiera zadnych elementow!");
    else if(n>=rozmiar)
        printf("Podany indeks wykracza poza rozmiar listy!");
    else if(l->head==l->tail)
        printf("[%d] element: %d",n,l->head->val);
    else
    {        
            el=l->head;    
            while(i!=n) 
            {
                el=el->next;
                i++;
            }     
            printf("[%d] element: %d",n,el->val);
    }
}

void remove_el(int n,struct list *l)
{
    int i=0,rozmiar;
    struct node *el;
    rozmiar=size_l(l);    
    if(l->head==NULL)
        printf("Brak elementu - lista nie zawiera zadnych elementow!\n");
    else if(n>=rozmiar)
        printf("Podany indeks wykracza poza rozmiar listy!\n");
    else if(l->head==l->tail)
    {
        printf("Usuwany [%d] element: %d\n",n,l->head->val);
        free(l->head);
        l->head=NULL;       
        l->tail=NULL;
    }
    else
    {             
        if(n==0) 
        {
            printf("Usuwany [%d] element: %d\n",n,l->head->val);
            l->head=l->head->next;            
            free(l->head->prev);
            l->head->prev=NULL;             
        }
        else if(n==rozmiar-1)
        {
            printf("Usuwany [%d] element: %d\n",n,l->tail->val);
            l->tail=l->tail->prev;            
            free(l->tail->next);
            l->tail->next=NULL;            
        }     
        else
        {
            el=l->head;
            while(i!=n) 
            {
                el=el->next;
                i++;
            }     
            printf("Usuwany [%d] element: %d\n",n,el->val);
            el->next->prev=el->prev;            
            el->prev->next=el->next;    
            free(el);           
        }          
    }    
} 

int size_l(struct list *l)
{
    int rozmiar=0;
    struct node *el;
    el=l->head;    
    if(l->head==NULL)
        return rozmiar;    
    do
    {
        rozmiar++;
        el=el->next;
    }
    while(el!=l->tail->next);
    return rozmiar;
}
