#include <iostream>
#include "matrix.h"

using namespace std;

Matrix::Matrix(int w,int k, double przekatna, double reszta)
{
	int i,j;
	double **wskazniki = new double *[w];
	double *wartosci = new double [w*k];
	//alokacja dwuwymiarowa (niestety ten gorszy model)
	
	for(i=0;i<k;i++) 
	{ 
		wskazniki[i]=&wartosci[i*k]; 
	}
	kolumny=k; wiersze=w;
	
	//zapychanie calej macierzy wartoscia "reszta"
	for(i=0;i<w;i++)
	{
		for(j=0;j<k;j++) { *(wskazniki[0]+i)=reszta; }
	}
	
	//przekatna
	int temp;
	if(w<k) { temp = w; }
	else { temp = k; }
	for(i=0;i<temp; i++) { *(wskazniki[i]+i)=przekatna; }
}

Matrix::~Matrix()
{
	delete [] wartosci;
	delete [] wskazniki;
}

ostream & operator << (ostream & ekran, const Matrix & moja)
{
	int i,j;
	ekran << "M = [ " << endl;
	for(i=0;i<moja.wiersze;i++)
	{
		ekran << "      ";
		for(j=0;j<moja.kolumny;j++)
		{
			ekran << *(moja.wskazniki[i*moja.wiersze+j]);
			ekran << "   ";
		}
		ekran << endl;
	}
	ekran << "    ]";
	return ekran;
}

/*
//wymiary musza sie zgadzac (puki co muahahahaha)
Matrix Matrix::operator+(const Matrix & moja)
{
	Matrix temp(moja.wiersze,moja.kolumny);
	for(int i=0,j ; i<moja.wiersze ; i++)
	{
		for(j=0;j<moja.kolumny ; j++)
		{
			temp.wartosci[i][j]=this->wartosci[i][j]+moja.wartosci[i][j];
		}
	}
	return temp;
}*/
/*
Matrix Matrix::operator-(const Matrix & moja)
{
	Matrix temp(moja.wiersze,moja.kolumny);
	for(int i=0,j ; i<moja.wiersze ; i++)
	{
		for(j=0;j<moja.kolumny ; j++)
		{
			temp.wartosci[i][j]=this->wartosci[i][j]-moja.wartosci[i][j];
		}
	}
	return temp;
}*/

/*Matrix & Matrix::operator *(const Matrix & moja)
{
	Matrix moja3 = Matrix(moja1.w , moja2.k);
	
	int i,j;
	for(i=0;i<moja1.w*moja2.k;i++)
	{
		double suma = 0;
		for(j=0;j<moja1.k;j++)
		{
			suma+=moja1.wartosci[j]*moja2.wartosci[j+j*k];
		}
		moja3.wartosci[i]=suma;
	}
}*/
/*
Matrix & Matrix::operator +=(const Matrix & moja)
{
	for(int i=0,j ; i<this->wiersze ; i++)
	{
		for(j=0; j<this->kolumny; j++)
		{
			wartosci[i][j]+=moja.wartosci[i][j];
		}
	}
	return *this;
}*/
/*
Matrix & Matrix::operator -=(const Matrix & moja)
{
	for(int i=0,j ; i<this->wiersze ; i++)
	{
		for(j=0; j<this->kolumny; j++)
		{
			wartosci[i][j]-=moja.wartosci[i][j];
		}
	}
	return *this;
}*/

/*
Matrix & Matrix::operator *=(const Matrix & moja)
{
	int i,j;
	for(i=0;i<this->wiersze*moja.kolumny;i++)
	{
		double suma = 0;
		for(j=0;j<this->kolumny;j++)
		{
			suma+=this->wartosci[j]*moja.wartosci[j+j*this->kolumny];
		}
		this->wartosci[i]=suma;
	}
	return *this;
}
*/
