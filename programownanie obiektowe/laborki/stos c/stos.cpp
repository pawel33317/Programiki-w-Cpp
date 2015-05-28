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
int zdejmowanie (wsk,int,int);
void wartosci(wsk,int);
void nakladanie (wsk,int,int,int);

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

printf("TWORZENIE NOWEGO STOSU ...\n* wpisanie 123 spowoduje zakonczenie wprowadzania liczb\n* stos moze zawierac tylko 10 elementow\n");
przelacznik='1';

do
{
switch(przelacznik)
{
    case '1':      wsk *wskaznik;
                   free(wskaznik);
                   wskaznik =(wsk*)malloc(10*sizeof(struct stos));

                   inic (wskaznik);
                   rozmiar=1;
                    
                   printf("chcesz recznie wprowadzac elementy [1] czy chcesz zeby zrobil to komputer[2]\n");
                   random=getch();

                   if(random=='1')
                   {
                   printf("podaj wartosc pierwszego elementu stosu");
                   scanf("%d",&el);
                  
                   while(el!=123)
                    {
                    if(rozmiar<10) 
                    {
                    push(wskaznik,el);
                    rozmiar++;
                    printf("podaj wartosc %d elementu stosu = ",rozmiar);
                    scanf("%d",&el);
                    }
                    else
                    {
                        printf ("blad stos moze miec tylko 10 elementow\n");
                        break;
                    }
                    }
                    }
                    else 
                    {printf("ile elementow ma zawierac stos <10\n");
                    scanf("%d",&wybrana);
                    r=0;
                        while(r<wybrana)
                        {el=rand()%20;
                        push(wskaznik,el);
                        r++;}
                        }
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

    case '5':      zwolnij(wskaznik); 
                   break;

}

printf("co chcesz zrobic\n 1.stworz stos\n 2.dodaj kolejny element\n 3.usun element\n 4.wypisz stos\n 5.zwolnj stos\n 6. zakoncz dzialanie programu\n");

przelacznik=getch();
printf("********************************************************************************");
}
while(przelacznik!='6');



system("PAUSE");
}


