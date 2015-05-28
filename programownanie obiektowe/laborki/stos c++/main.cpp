#include <cstdlib>
#include <iostream>

using namespace std;

template <class typ>  //wiêksza uniwersalnosæ - szablon
class stos
{
	typ *tab;		//do przechowywania danych u¿yjê dyanamicznie przydzialanej pamiêci
	long size;		//ile elementów mo¿emy pomieœciæ w stosie
	long wybrany;	//numer pierwszego wolnego elementu
 
	void powiekszSie();	//jeœli braknie miejsca, stos siê powiêkszy
 
public:
	stos();			//konstruktor domyœlny
	stos(long rozm);//tu mo¿emy okreœliæ ile elementów bêdzie mo¿na pomieœciæ
	~stos();		//destruktor (zwróci zaalokowan¹ pamiêæ)
 
	void push(typ &co);	//funkcja do umieszczania elementu na stosie
	void pop();			//funkcja do zdejmowania elementu ze stosu
	const typ& top();			//funkcja zwraca to co jest na górze stosu
};
 
template <class typ>
stos<typ>::stos()
{
	wybrany = 0;	//na pocz¹tku stos jest pusty
	size = 10;		//na starcie dajemy mo¿liwoœæ wrzucenia 10 elementów
 
	tab = new typ[size];	//dyaniecznie przydzielana pamiêæ
 
	if(tab == NULL)		//coœ siê nie powiod³o przy alokacji pamiêci
	{
		throw "B³¹d alokcacji pamiêci!";	//rzucamy wyj¹tek
	}
}
 
template <class typ>
stos<typ>::stos(long rozm)
{
	wybrany = 0;	//na stosie pusto
	size = rozm;	//ustawiamy zgodnie z zyczeniem
 
	tab = new typ[size];	//tak jak wy¿ej
 
	if(tab == NULL)
	{
		throw "B³¹d alokcacji pamiêci!";
	}
}
 
template <class typ>
stos<typ>::~stos()
{
	delete []tab;	//zwalniamy pamiêæ 
}
 
template <class typ>
void stos<typ>::push(typ &co)
{
	if(wybrany == size)	//jeœlo koñczy siê miejsce
		powiekszSie();	//stos siê powiêksza
 
	tab[wybrany ++] = co;	//umieszczamy element na stosie
}
 
template <class typ>
void stos<typ>::pop()
{
	wybrany --;	//nie kasujemy obiektu, ale przy wywo³aniu push, i tak bêdzie nadpisany
}
 
template <class typ>
const typ& stos<typ>::top()
{
	return tab[wybrany - 1];	//zwracamy to co jest na sczycie (wybrany wskazuje na pierwszy WOLNY element tablicy, daltego zmniejszam o 1)
}
 
template <class typ>
void stos<typ>::powiekszSie()
{
	typ *nowa = new typ[size + 10];		//nowa tablica jest o 10 el. wiêksza
 
	for(int i=0;i<size;++i)
		nowa[i] = tab[i];	//kopiujemy star¹ tablicê do nowej
 
	delete []tab;	//star¹ tablicê mo¿emy skasowaæ
 
	tab = nowa;		//teraz tab pokazuje na now¹, wiêksz¹ tablicê
 
	size += 10;		//trzeba zapisaæ o ile powiêkszyliœmy tablicê
}
