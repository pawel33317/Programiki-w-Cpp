#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class stos
{
	int *tab;		
	long size;		
	long wybrany;	
	void powiekszSie();
 
public:
	stos();			
//	stos(long rozm);
	~stos();		
 
	void push(int co);	
	void pop();			
	const int& top();	
    void wypisz();
};
 

stos::stos()
{
	wybrany = 0;	
	size = 100;		
 
	tab = new int[size];	
 
	if(tab == NULL)		
	{
		throw "B³¹d alokcacji pamiêci!";	
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
	delete []tab;	
}
 

void stos::push(int co)
{
	if(wybrany == size)	
		powiekszSie();	
 
	tab[wybrany ++] = co;	
}
 

void stos::pop()
{
	wybrany --;	
}
 

const int& stos::top()
{
	return tab[wybrany - 1];	
}
 

void stos::powiekszSie()
{
	int *nowa = new int[size + 10];		
 
	for(int i=0;i<size;++i)
		nowa[i] = tab[i];	
 
	delete []tab;	
 
	tab = nowa;		
 
	size += 10;		
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

}
