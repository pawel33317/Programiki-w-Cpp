#include <iostream>
#include <map>

using namespace std;

void dolacz(multimap <char*,char*> *wsk,char *klucz,char *wartosc)
{
    wsk->insert(pair<char*,char*>(klucz,wartosc));
}

void szukaj(multimap <char*,char*> *wsk,char *klucz)
{
    multimap <char*,char*> :: iterator i;        
    for(i=wsk->begin();i!=wsk->end();i++)
        if(strcmp(i->first,klucz)==0)   
            printf("%-20s %s\n",i->first,i->second); 
}

int main(void)
{
    char klucz[20],wartosc[20],szukane[20];
    multimap <char*,char*> slownik;
    multimap <char*,char*> :: iterator i;
    multimap <char*,char*> *wsk=&slownik;
    slownik.insert(pair<char*,char*>("dzien","day"));
    slownik.insert(pair<char*,char*>("poniedzialek","monday"));    
    for(i=slownik.begin();i!=slownik.end();i++)
        printf("%-20s %s\n",i->first,i->second);   
    printf("\nPodaj klucz i wartosc, aby dolaczyc:\n");
    scanf("%s%s",klucz,wartosc);
    dolacz(wsk,klucz,wartosc);
    printf("\n");
    for(i=slownik.begin();i!=slownik.end();i++)
        printf("%-20s %s\n",i->first,i->second);  
    printf("\nPodaj szukane slowo: ");        
    scanf("%s",szukane);    
    szukaj(wsk,szukane);  
    system("PAUSE");
    return 0;
}
