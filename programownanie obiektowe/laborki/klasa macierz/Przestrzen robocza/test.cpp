#include <iostream>
#include <fstream>



using namespace std;

class Matrix
{
	public:
	double **wartosci;
	int kolumny, wiersze;
	int lodwolan;
	
	Matrix(int w = 1,int k = 1, double przekatna = 0, double reszta = 0);
	~Matrix();
	
	friend ostream & operator << (ostream & ekran,const Matrix & moja);
	Matrix operator +(const Matrix & moja);
	Matrix operator -(const Matrix & moja);
	Matrix & operator +=(const Matrix & moja);
	Matrix & operator -=(const Matrix & moja);
	Matrix & operator =(const Matrix & moja);
	Matrix operator *(const Matrix & moja);
	//Matrix & operator *=(const Matrix & moja);
	double & operator ()(int a, int b);
	
	//void save(char* nazwa);
};


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
	//Matrix m0(2,3,3,2);
	//Matrix m1(3,2,2,1);
	
//	cout << m0 << endl << m1 << endl;
//	Matrix m2 = m0 * m1;
//	cout << "OPERATOR * " << endl << m2 << endl;
	
int** a;	
int i;
	a = new int *[5];
	for(i=0;i<5;i++) { a[i] = new int [5]; }
	
	a=(1,2,3,4,5,
    6,7,8,9,0,
    1,2,3,4,5,
    6,7,8,9,0,
    1,2,3,4,5);
	
	//m0 *= m1;
	//cout << "OPERATOR *= " << endl << m0 << endl;
	
//	save("moja1.txt",m0);
	//moja = moja2 *= moja3;
	//cout << "OPERATOR *= " << endl << moja1 << endl;
	
	//test wczytywania z pliku
	//f1.open("matrix1.txt");
	
	//testy indeksowania
		//moja1[0][0]=10;
		//moja2(5,1)=1;

system("PAUSE");
}
