#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

Matrix::Matrix(int w,int k, double przekatna, double reszta)
{
	int i,j;
	lodwolan=1;
	//alokacja dwuwymiarowa (niestety ten gorszy model)
	wartosci = new double *[w];
	for(i=0;i<w;i++) { wartosci[i] = new double [k]; }
	kolumny=k; wiersze=w;
	
	//zapychanie calej macierzy wartoscia "reszta"
	for(i=0;i<w;i++)
	{
		for(j=0;j<k;j++) { wartosci[i][j]=reszta; }
	}
	
	//przekatna
	int temp;
	if(w<k) { temp = w; }
	else { temp = k; }
	for(i=0;i<temp; i++) { wartosci[i][i]=przekatna; }
}

Matrix::~Matrix()
{
	if(--lodwolan==0) delete wartosci;
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
			ekran << moja.wartosci[i][j];
			ekran << "   ";
		}
		ekran << endl;
	}
	ekran << "    ]";
	return ekran;
}

//wymiary musza sie zgadzac (puki co muahahahaha)
Matrix Matrix::operator+(const Matrix & moja)
{

	Matrix temp(wiersze,kolumny);
	int i,j;
	for(i=0 ; i<wiersze ; i++)
	{
		for(j=0 ; j<kolumny ; j++)
		{
			temp.wartosci[i][j]=wartosci[i][j]+moja.wartosci[i][j];
		}
	}
	return temp;
}

Matrix Matrix::operator-(const Matrix & moja)
{
	Matrix temp(wiersze,kolumny);
	for(int i=0,j ; i<wiersze ; i++)
	{
		for(j=0;j<kolumny ; j++)
		{
			temp.wartosci[i][j]=wartosci[i][j]-moja.wartosci[i][j];
		}
	}
	return temp;
}

Matrix & Matrix::operator +=(const Matrix & moja)
{
	for(int i=0,j ; i<wiersze ; i++)
	{
		for(j=0; j<kolumny; j++)
		{
			wartosci[i][j]+=moja.wartosci[i][j];
		}
	}
	return *this;
}

Matrix & Matrix::operator -=(const Matrix & moja)
{
	for(int i=0,j ; i<wiersze ; i++)
	{
		for(j=0; j<kolumny; j++)
		{
			wartosci[i][j]-=moja.wartosci[i][j];
		}
	}
	return *this;
}

Matrix & Matrix::operator =(const Matrix & moja)
{
	//zabezpieczenie przed glupota
	if(this==&moja) return *this;
	
	//wlasciwa tresc operatora
	//moja.lodwolan+=1;
	if(--lodwolan == 0)
	{
		delete wartosci;
	}
	int i,j;
	for(i=0;i<wiersze;i++)
	{
		for(j=0;j<kolumny;j++)
		{
			wartosci[i][j]=moja.wartosci[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator *(const Matrix & moja)
{
	Matrix temp(wiersze, moja.kolumny);
	
	int i,j,k;
	double suma;
	for(i=0;i<wiersze;i++)
	{
		for(j=0;j<moja.kolumny;j++)
		{
			suma=0;
			for(k=0;k<moja.wiersze;k++)
			{
				suma+=wartosci[i][k]*moja.wartosci[k][j];
			}
			temp.wartosci[i][j]=suma;
		}
	}
	return temp;
}

/*Matrix Matrix::operator *=(const Matrix & moja)
{
	Matrix temp(wiersze, moja.kolumny);
	
	int i,j,k;
	double suma;
	for(i=0;i<wiersze;i++)
	{
		for(j=0;j<moja.kolumny;j++)
		{
			suma=0;
			for(k=0;k<moja.wiersze;k++)
			{
				suma+=wartosci[i][k]*moja.wartosci[k][j];
			}
			temp.wartosci[i][j]=suma;
		}
	}
	return temp;
}*/

double & Matrix::operator ()(int a, int b)
{
	return wartosci[a][b];
}

/*Matrix load(char *nazwa)
{
	ifstream wczyt
}*/

void save(char* nazwa, Matrix moja)
{
	std::ofstream zapis;
	zapis.open(nazwa);
	zapis << moja.wiersze << " " << moja.kolumny << " ";
	for(int i=0,j;i<moja.wiersze;i++)
	{
		for(j=0;j<moja.kolumny;j++)
		{
			zapis << moja.wartosci[i][j] << " ";
		}
	}
	zapis.close();
}
