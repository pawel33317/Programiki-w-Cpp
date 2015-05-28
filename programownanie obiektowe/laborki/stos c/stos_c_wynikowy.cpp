#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


typedef struct stos *wsk;

struct stos{
       int element;
       wsk prev;  
       };         

void push(wsk,int);
int pop(wsk);
void wypisz(wsk);
void inic(wsk);
void zwolnij(wsk);
//int zdejmowanie (wsk,int,int);
//void wartosci(wsk,int);
//void nakladanie (wsk,int,int,int);

void push(wsk *wskaz,int wartosc)
{
    int i;
    wsk tmp=(wsk)malloc(sizeof(struct stos));
    tmp->element=wartosc;
    tmp->prev=*wskaz;
    *wskaz=tmp;
}

int pop(wsk *wskaz)
{
  if(wskaz!=NULL)
  {
                wsk tmp=*wskaz;
                free(wskaz);
                (*wskaz)=tmp->prev;
                return tmp->element;  
   }
   else return 0;
}    
void wypisz(wsk *wskaz)
{
    wsk tmp=*wskaz;
    while(tmp!=NULL)
    {
                      printf("%d\n",tmp->element);
                      tmp=tmp->prev;
    }
}

void inic(wsk *wskaz)
{
     *wskaz=NULL;
}

void zwolnij(wsk *wskaznik)
{
     free(wskaznik);
     
}

int main()
{
    int przelacznik,i,rozmiar,nevelement,zdjety,wartosc,el,random,r,il,wybrana;

printf("TWORZENIE NOWEGO STOSU\n" );
przelacznik='1';

do
{
switch(przelacznik)
{
    case '1':      wsk *wskaznik;
                   wskaznik =(wsk*)malloc(10*sizeof(struct stos));

                   inic (wskaznik);
                   rozmiar=1;
                    
                  
                   printf("podaj wartosc pierwszego elementu stosu");
                   scanf("%d",&el);
                   push(wskaznik,el);
                     break;
    
    case '2': if(rozmiar<10) 
            {
                          printf("podaj wartosc kolejnego elementu\n");
                          scanf("%d",&nevelement); 
                          push(wskaznik,nevelement);
                          rozmiar++;
            }
            else {printf("stos jest juz pelen\n");}
         break;
    
    case '3':if(rozmiar==1)  
                           {
                           printf("stos pusty\n");
                           break;
                           }
            else
            { 
            zdjety=pop(wskaznik);
            rozmiar--;
            printf("wartosc zdjetego elementu to %d\n",zdjety);
            }
         break;
         
    
    
    case '4':      wypisz(wskaznik); 
                   break;

    case '5':      if(rozmiar==0)
                   {
                                 printf("stos jest juz pusty");
                   }
                   else
                   { 
                   zwolnij(wskaznik); 
                   rozmiar=0;
                   }
                   break;

}

printf("co chcesz zrobic\n 1.stworz stos\n 2.dodaj kolejny element\n 3.usun element\n 4.wypisz stos\n 5.zwolnj stos\n 6. zakoncz dzialanie programu\n");

przelacznik=getch();
if(przelacznik='6'){free(*wskaznik)};
system("cls");  
}
while(przelacznik!='6');



system("PAUSE");
}


