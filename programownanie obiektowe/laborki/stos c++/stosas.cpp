#include <stdio.h>
#include <iostream>

class stos
{
      private:
              struct stos_struktura
              {
                     int dane;
                     stos_struktura *poprzedni;
              }*ostatni;
              int indeks;
      
      public:
             stos();
             ~stos();
             void czysc();
             void dodaj_el(int a);
             int zdejmij();
};

stos::stos() 
{
             indeks=0; 
             ostatni = NULL; 
}

stos::~stos()
{
  delete []stos_struktura ;
}

void stos::dodaj_el(int element)
{
 stos_struktura* pomocniczy = new stos_struktura;
 pomocniczy->poprzedni = (++indeks==1) ? NULL : ostatni;
 pomocniczy->dane = element;
 ostatni = pomocniczy;
}

int stos::zdejmij(DWORD ostatnia_zap)
{
 if(indeks<1) return;
 if(ostatnia_zap!=NULL) *ostatnia_zap=ostatni->dane; //zwróæ usuwany element
 stos_struktura *tmp = ostatni->poprzedni; //zapamiêtaj przedostatni element
 delete ostatni; //skasuj go
 ostatni = tmp;  //przedostatni element staje siê ostatnim
 if(--indeks==0) ostatni = NULL;
}
 
      
