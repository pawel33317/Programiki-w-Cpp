#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <iostream>

using namespace std;

class Matrix
{
	public:
	double wartosci;
	double *wskazniki;
	int kolumny, wiersze;
	
	Matrix(int w = 1,int k = 1, double przekatna = 0, double reszta = 0);
	~Matrix();
	
	friend ostream & operator << (ostream & ekran,const Matrix & moja);
	Matrix operator +(const Matrix & moja);
	Matrix operator -(const Matrix & moja);
	Matrix & operator *(const Matrix & moja);
	Matrix & operator +=(const Matrix & moja);
	Matrix & operator -=(const Matrix & moja);
	Matrix & operator *=(const Matrix & moja);
	//Matrix & operator ()(const Matrix & moja1 , const Matrix & moja2);
	//Matrix & operator [](const Matrix & moja1 , const Matrix & moja2);
};

#endif /*__MATRIX_H__*/
