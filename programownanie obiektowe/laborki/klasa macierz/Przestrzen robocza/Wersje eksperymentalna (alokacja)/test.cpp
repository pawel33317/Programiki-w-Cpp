#include <iostream>
#include "matrix.h"

using namespace std;

//KLASA MATRIX
//PISANA ZGODNIE Z WYTYCZNYMI LABORATORYJNYMI

/*
Postep prac:
podzial na pliki OK
konstruktor destruktor OK
operatory + - += -= OK
operatory * *= Nie dziala
dwupoziomowa dynamiczna alokacja pamieci Jest w wersji ciut gorszej ale jest
zliczanie odwolan Brak
operator << Czesciowo (operator dziala jednak wyswietla troche pokracznie)
obsluga wyjatkow Brak


*/

int main()
{
	//testy konstruktorow
	Matrix moja1(2,4); //wymiary
	Matrix moja2(2,2,2); //wymiary i wartosci na przekatnej
	Matrix moja3(3,3,1,9); //wymiary, wartosci na przekatnej i reszta
	cout << moja1 << endl;
	cout << moja2 << endl;
	cout << moja3 << endl;
	
	//testy operatorow (+ - * += -= *= cout)
	/*
	moja1 = moja2 + moja3;
	cout << "OPERATOR + " << endl << moja1 << endl;
	
	moja1 = moja2 - moja3;
	cout << "OPERATOR - " << endl << moja1 << endl;
	
	moja1 = moja2 * moja3;
	cout << "OPERATOR * " << endl << moja1 << endl;
	
	moja1 = moja2 += moja3;
	cout << "OPERATOR += " << endl << moja1 << endl;
	
	moja1 = moja2 -= moja3;
	cout << "OPERATOR -= " << endl << moja1 << endl;
	
	moja1 = moja2 *= moja3;
	cout << "OPERATOR *= " << endl << moja1 << endl;
	*/
	//test wczytywania z pliku
	//f1.open("matrix1.txt");
	
	//testy indeksowania
		//moja1[0][0]=10;
		//moja2(5,1)=1;

}
