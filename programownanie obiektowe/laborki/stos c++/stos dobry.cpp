#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class stos
{
	int *tab;		//do przechowywania danych u¿yjê dyanamicznie przydzialanej pamiêci
	long size;		//ile elementów mo¿emy pomieœciæ w stosie
	long wybrany;	//numer pierwszego wolnego elementu
 
	void powiekszSie();	//jeœli braknie miejsca, stos siê powiêkszy
 
public:
	stos();			//konstruktor domyœlny
//	stos(long rozm);//tu mo¿emy okreœliæ ile elementów bêdzie mo¿na pomieœciæ
	~stos();		//destruktor (zwróci zaalokowan¹ pamiêæ)
 
	void push(int co);	//funkcja do umieszczania elementu na stosie
	void pop();			//funkcja do zdejmowania elementu ze stosu
	const int& top();			//funkcja zwraca to co jest na górze stosu
    void wypisz();
};
 

stos::stos()
{
	wybrany = 0;	//na pocz¹tku stos jest pusty
	size = 10;		//na starcie dajemy mo¿liwoœæ wrzucenia 10 elementów
 
	tab = new int[size];	//dyaniecznie przydzielana pamiêæ
 
	if(tab == NULL)		//coœ siê nie powiod³o przy alokacji pamiêci
	{
		throw "B³¹d alokcacji pamiêci!";	//rzucamy wyj¹tek
	}
}
 
/*
stos::stos(long rozm)
{
	wybrany = 0;	//na stosie pusto
	size = rozm;	//ustawiamy zgodnie z zyczeniem
 
	tab = new int[size];	//tak jak wy¿ej
 
	if(tab == NULL)
	{
		throw "B³¹d alokcacji pamiêci!";
	}
}
*/

stos::~stos()
{
	delete []tab;	//zwalniamy pamiêæ 
}
 

void stos::push(int co)
{
	if(wybrany == size)	//jeœlo koñczy siê miejsce
		powiekszSie();	//stos siê powiêksza
 
	tab[wybrany ++] = co;	//umieszczamy element na stosie
}
 

void stos::pop()
{
	wybrany --;	//nie kasujemy obiektu, ale przy wywo³aniu push, i tak bêdzie nadpisany
}
 

const int& stos::top()
{
	return tab[wybrany - 1];	//zwracamy to co jest na sczycie (wybrany wskazuje na pierwszy WOLNY element tablicy, daltego zmniejszam o 1)
}
 

void stos::powiekszSie()
{
	int *nowa = new int[size + 10];		//nowa tablica jest o 10 el. wiêksza
 
	for(int i=0;i<size;++i)
		nowa[i] = tab[i];	//kopiujemy star¹ tablicê do nowej
 
	delete []tab;	//star¹ tablicê mo¿emy skasowaæ
 
	tab = nowa;		//teraz tab pokazuje na now¹, wiêksz¹ tablicê
 
	size += 10;		//trzeba zapisaæ o ile powiêkszyliœmy tablicê
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
