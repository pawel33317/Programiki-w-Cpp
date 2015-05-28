#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class stos
{
	int *tab;		//do przechowywania danych u�yj� dyanamicznie przydzialanej pami�ci
	long size;		//ile element�w mo�emy pomie�ci� w stosie
	long wybrany;	//numer pierwszego wolnego elementu
 
	void powiekszSie();	//je�li braknie miejsca, stos si� powi�kszy
 
public:
	stos();			//konstruktor domy�lny
//	stos(long rozm);//tu mo�emy okre�li� ile element�w b�dzie mo�na pomie�ci�
	~stos();		//destruktor (zwr�ci zaalokowan� pami��)
 
	void push(int co);	//funkcja do umieszczania elementu na stosie
	void pop();			//funkcja do zdejmowania elementu ze stosu
	const int& top();			//funkcja zwraca to co jest na g�rze stosu
    void wypisz();
};
 

stos::stos()
{
	wybrany = 0;	//na pocz�tku stos jest pusty
	size = 10;		//na starcie dajemy mo�liwo�� wrzucenia 10 element�w
 
	tab = new int[size];	//dyaniecznie przydzielana pami��
 
	if(tab == NULL)		//co� si� nie powiod�o przy alokacji pami�ci
	{
		throw "B��d alokcacji pami�ci!";	//rzucamy wyj�tek
	}
}
 
/*
stos::stos(long rozm)
{
	wybrany = 0;	//na stosie pusto
	size = rozm;	//ustawiamy zgodnie z zyczeniem
 
	tab = new int[size];	//tak jak wy�ej
 
	if(tab == NULL)
	{
		throw "B��d alokcacji pami�ci!";
	}
}
*/

stos::~stos()
{
	delete []tab;	//zwalniamy pami�� 
}
 

void stos::push(int co)
{
	if(wybrany == size)	//je�lo ko�czy si� miejsce
		powiekszSie();	//stos si� powi�ksza
 
	tab[wybrany ++] = co;	//umieszczamy element na stosie
}
 

void stos::pop()
{
	wybrany --;	//nie kasujemy obiektu, ale przy wywo�aniu push, i tak b�dzie nadpisany
}
 

const int& stos::top()
{
	return tab[wybrany - 1];	//zwracamy to co jest na sczycie (wybrany wskazuje na pierwszy WOLNY element tablicy, daltego zmniejszam o 1)
}
 

void stos::powiekszSie()
{
	int *nowa = new int[size + 10];		//nowa tablica jest o 10 el. wi�ksza
 
	for(int i=0;i<size;++i)
		nowa[i] = tab[i];	//kopiujemy star� tablic� do nowej
 
	delete []tab;	//star� tablic� mo�emy skasowa�
 
	tab = nowa;		//teraz tab pokazuje na now�, wi�ksz� tablic�
 
	size += 10;		//trzeba zapisa� o ile powi�kszyli�my tablic�
}

void stos::wypisz()
{
     int i;
     int *nowa = new int[size];

    
		nowa = tab;
        int k=0;
     do
     {
                   printf("%d\n",nowa[k]);
                   k++;
     }
     while(k<wybrany);
} 

int main()
{

	stos s1;
	stos s2;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s2.push(5);
	s2.push(6);
	
    printf("%d %d\n",s1.top(),s2.top());
    
    s1.wypisz();
	
    getchar();

	return 0;
/*do
{
switch(przelacznik)
{
    case '1':      
                    break;
    
    case '2': 
         break;
    
    case '3':
         break;
         
    
    
    case '4':      
                   break;

    case '5':      
                   break;

}
*/
}
