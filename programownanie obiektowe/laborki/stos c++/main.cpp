#include <cstdlib>
#include <iostream>

using namespace std;

template <class typ>  //wi�ksza uniwersalnos� - szablon
class stos
{
	typ *tab;		//do przechowywania danych u�yj� dyanamicznie przydzialanej pami�ci
	long size;		//ile element�w mo�emy pomie�ci� w stosie
	long wybrany;	//numer pierwszego wolnego elementu
 
	void powiekszSie();	//je�li braknie miejsca, stos si� powi�kszy
 
public:
	stos();			//konstruktor domy�lny
	stos(long rozm);//tu mo�emy okre�li� ile element�w b�dzie mo�na pomie�ci�
	~stos();		//destruktor (zwr�ci zaalokowan� pami��)
 
	void push(typ &co);	//funkcja do umieszczania elementu na stosie
	void pop();			//funkcja do zdejmowania elementu ze stosu
	const typ& top();			//funkcja zwraca to co jest na g�rze stosu
};
 
template <class typ>
stos<typ>::stos()
{
	wybrany = 0;	//na pocz�tku stos jest pusty
	size = 10;		//na starcie dajemy mo�liwo�� wrzucenia 10 element�w
 
	tab = new typ[size];	//dyaniecznie przydzielana pami��
 
	if(tab == NULL)		//co� si� nie powiod�o przy alokacji pami�ci
	{
		throw "B��d alokcacji pami�ci!";	//rzucamy wyj�tek
	}
}
 
template <class typ>
stos<typ>::stos(long rozm)
{
	wybrany = 0;	//na stosie pusto
	size = rozm;	//ustawiamy zgodnie z zyczeniem
 
	tab = new typ[size];	//tak jak wy�ej
 
	if(tab == NULL)
	{
		throw "B��d alokcacji pami�ci!";
	}
}
 
template <class typ>
stos<typ>::~stos()
{
	delete []tab;	//zwalniamy pami�� 
}
 
template <class typ>
void stos<typ>::push(typ &co)
{
	if(wybrany == size)	//je�lo ko�czy si� miejsce
		powiekszSie();	//stos si� powi�ksza
 
	tab[wybrany ++] = co;	//umieszczamy element na stosie
}
 
template <class typ>
void stos<typ>::pop()
{
	wybrany --;	//nie kasujemy obiektu, ale przy wywo�aniu push, i tak b�dzie nadpisany
}
 
template <class typ>
const typ& stos<typ>::top()
{
	return tab[wybrany - 1];	//zwracamy to co jest na sczycie (wybrany wskazuje na pierwszy WOLNY element tablicy, daltego zmniejszam o 1)
}
 
template <class typ>
void stos<typ>::powiekszSie()
{
	typ *nowa = new typ[size + 10];		//nowa tablica jest o 10 el. wi�ksza
 
	for(int i=0;i<size;++i)
		nowa[i] = tab[i];	//kopiujemy star� tablic� do nowej
 
	delete []tab;	//star� tablic� mo�emy skasowa�
 
	tab = nowa;		//teraz tab pokazuje na now�, wi�ksz� tablic�
 
	size += 10;		//trzeba zapisa� o ile powi�kszyli�my tablic�
}
