#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

//KLASA MATRIX
//PISANA ZGODNIE Z WYTYCZNYMI LABORATORYJNYMI

/*
Postep prac:
podzial na pliki OK
konstruktory destruktory OK
operatory + - += -= OK
operatory * *= Prawie dziala
alokacja pamieci OK
zliczanie odwolan Brak
operator << Czesciowo OK
obsluga wyjatkow Brak
wczytywanie do pliku Brak


*/



int main()
{
	Matrix m0(2,3,3,2);
	Matrix m1(3,2,2,1);
	
	cout << m0 << endl << m1 << endl;
	Matrix m2 = m0 * m1;
	cout << "OPERATOR * " << endl << m2 << endl;
	
	//m0 *= m1;
	//cout << "OPERATOR *= " << endl << m0 << endl;
	
	save("moja1.txt",m0);
	//moja = moja2 *= moja3;
	//cout << "OPERATOR *= " << endl << moja1 << endl;
	
	//test wczytywania z pliku
	//f1.open("matrix1.txt");
	
	//testy indeksowania
		//moja1[0][0]=10;
		//moja2(5,1)=1;

}
