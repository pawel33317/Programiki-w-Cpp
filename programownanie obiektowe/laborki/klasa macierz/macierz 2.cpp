#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

class CMatrix
       {
       private:
       	       struct CMdat;
	           CMdat* data;
       public:

CMatrix();
CMatrix(unsigned int x, unsigned int y);
CMatrix(unsigned int x, unsigned int y, double k);
CMatrix(unsigned int x, unsigned int y, double k, double l);
CMatrix(const CMatrix& x);

~CMatrix();
CMatrix & operator= (const CMatrix&);
CMatrix operator* (const CMatrix&);
CMatrix operator+ (const CMatrix&);
CMatrix operator- (const CMatrix&);
double & operator () (unsigned int, unsigned int);
CMatrix & operator+= (const CMatrix&);
CMatrix & operator-= (const CMatrix&);
CMatrix & operator*= (const CMatrix&);
void Rand();
CMatrix trans();
double Determinant(double** matrix, int size);
double dethelp();
friend ostream& operator<<(ostream&, const CMatrix&);

class IndexOutOfRange{};
class WrongDim{};
class Wrong_Matrix_Sizes{};
class bad_alloc{};

bool operator !=(const CMatrix&);

};


struct CMatrix::CMdat
{
double **matrix;
unsigned int n;
unsigned int x;
unsigned int y;

CMdat (unsigned int nx, unsigned int ny)
{
	n=1;
	x=nx;
	y=ny;

	int i;

	try
	{
	       	matrix=new double* [x];
		for (i=0;i<x; i++)
	        {
	       		matrix[i]=new double [y];
	       	}
	}catch(bad_alloc)
	{
		for(i; i >=0; i--) delete [] matrix[i];
		delete [] matrix;
		cout << "bad alloc!" << endl;
	}	
};

~CMdat()
{
 unsigned int i;
          
          for (i=0;i<x; i++)
            {
            delete [] matrix[i];
            }
            delete [] matrix;
};

 CMdat* detach()
  {
unsigned int i,j;
    if(n==1) return this;
    CMdat* nd=new CMdat(x, y);
    n--;


for (i=0;i<x;i++)
{
        for(j=0;j<y;j++)
	{		
	nd->matrix[i][j]=(double)(matrix[i][j]);
	}
	
}
    return nd;
  };


private:
  CMdat(const CMdat&);
  CMdat& operator=(const CMdat&);
};

inline CMatrix::CMatrix()
{

   data=new CMdat(0,0);


}

inline CMatrix::CMatrix(unsigned int x, unsigned int y)
{
unsigned int i,j;
   data=new CMdat(x,y);

for (i=0;i<x;i++)
{
    for(j=0;j<y;j++)
	{
 	data->matrix[i][j]=0;
	}
}

}
inline CMatrix::CMatrix(unsigned int x, unsigned int y, double k)
{
unsigned int i,j;
   data=new CMdat(x,y);
for (i=0;i<x;i++)
{
    for(j=0;j<y;j++)
	{
	{
	data->matrix[i][j]=k;
	} 
	}
}
}


inline CMatrix::CMatrix(unsigned int x, unsigned int y, double k, double l)
{
unsigned int i,j;
data=new CMdat(x,y);
for (i=0;i<x;i++)
{
    for(j=0;j<y;j++)
	{
	if(i==j)
	{
	data->matrix[i][j]=k;
	} else
 	data->matrix[i][j]=l;
	}
}
}

inline CMatrix::CMatrix(const CMatrix& x)
  {
    x.data->n++;
    data=x.data;
  }

inline CMatrix::~CMatrix()
{
   if(--data->n==0)
    delete data;
}

void CMatrix::Rand()
{
	for(int i=0;i<data->x;i++)
		for(int j=0; j<data->y;j++)
			data->matrix[i][j] = rand()%10;
}

CMatrix & CMatrix::operator= (const CMatrix& x)
{

data=data->detach();
x.data->n++;
if(--data->n==0)
    delete data;
data=x.data;
return *this;
}  

CMatrix CMatrix::operator* (const CMatrix& x)
{
unsigned int i,j,l;
double ele;
ele=0;

if(data->y==x.data->x)
{
CMatrix nm(data->x,x.data->y);

for (i=0;i<data->x;i++)
{
        for(j=0;j<x.data->y;j++)
	{
		for(l=0;l<data->y;l++)
		{
			ele+=(double)(data->matrix[i][l])*(double)(x.data->matrix[l][j]);
		}

		nm.data->matrix[i][j]=ele;
		ele=0;

	}
	
}
return nm;
}
throw WrongDim();
} 


CMatrix CMatrix::operator+ (const CMatrix& x)
{
unsigned int i,j;

if(data->x==x.data->x && data->y==x.data->y)
{
CMatrix nm(data->x,x.data->y);

for (i=0;i<data->x;i++)
{
        for(j=0;j<data->y;j++)
	{	
	nm.data->matrix[i][j]=(double)(data->matrix[i][j])+(double)(x.data->matrix[i][j]);
	}
	
}
return nm;

}
throw WrongDim();

} 

CMatrix CMatrix::operator- (const CMatrix& x)
{
unsigned int i,j;

if(data->x==x.data->x && data->y==x.data->y)
{
CMatrix nm(data->x,x.data->y);

for (i=0;i<data->x;i++)
{
        for(j=0;j<data->y;j++)
	{	
	nm.data->matrix[i][j]=(double)(data->matrix[i][j])-(double)(x.data->matrix[i][j]);
	}	
}
return nm;

}
throw WrongDim();

} 
CMatrix & CMatrix::operator+= (const CMatrix& x)
{
unsigned int i,j;

if(data->x==x.data->x && data->y==x.data->y)
{

CMatrix nm(data->x,data->y);

for (i=0;i<data->x;i++)
{
        for(j=0;j<data->y;j++)
	{		
	nm.data->matrix[i][j]=(double)(data->matrix[i][j])+(double)(x.data->matrix[i][j]);
	}
	
}

if(--data->n==0)
    delete data;
data=nm.data;
data->n++;
return *this;
}
throw WrongDim();

} 

CMatrix & CMatrix::operator-= (const CMatrix& x)
{
unsigned int i,j;

if(data->x==x.data->x && data->y==x.data->y)
{

CMatrix nm(data->x,data->y);

for (i=0;i<data->x;i++)
{
        for(j=0;j<data->y;j++)
	{		
	nm.data->matrix[i][j]=(double)(data->matrix[i][j])-(double)(x.data->matrix[i][j]);
	}	
}

if(--data->n==0)
    delete data;
data=nm.data;
data->n++;
return *this;
}
throw WrongDim();

} 

CMatrix & CMatrix::operator*= (const CMatrix& x)
{
	double suma = 0;

	if(data->y != x.data->x) throw Wrong_Matrix_Sizes();
	CMatrix temp(*this);
	
	if(data->n == 1) 
	{
		delete data;
		data = new CMdat(temp.data->x, x.data->y);
	}else
	{
		CMdat* nm = new CMdat(temp.data->x, x.data->y);
		data->n--;
		data = nm;
	}

	for (int i = 0; i < temp.data->x; i++)
	{
       		for(int j = 0; j < x.data->y; j++)
		{
			for(int l = 0; l < temp.data->y; l++)
			{
				suma+=(double)(temp.data->matrix[i][l])*(double)(x.data->matrix[l][j]);
			}
			data->matrix[i][j]=suma;
			suma=0;
		}
	}
	return *this;
} 



ostream& operator << (ostream& o, const CMatrix& m)
{
unsigned int i,j;

for (i=0;i<m.data->x;i++)
{ o<<endl;
    for(j=0;j<m.data->y;j++)
	{
	cout.width(4);
	cout.precision(4);
 	o<<" "<<m.data->matrix[i][j];
	}

}
o<<"  "<<"Ref:"<<m.data->n;
return o;
}


double & CMatrix::operator () (unsigned int x, unsigned int y)
{
if(data->x<x || data->y<y)
{
throw IndexOutOfRange();  
}
data=data->detach();
return data->matrix[x][y];
}

CMatrix CMatrix::trans()
{
	CMatrix temp(data->x, data->y);

	for(int i=0;i<data->x;i++)
		for(int j=0; j<data->y;j++)
			temp.data->matrix[j][i] = data->matrix[i][j];
	return temp;
}

double CMatrix::Determinant(double** matrix, int size)
{
   int rozmiar;
   double wyznacznik = 0;
   double **temp;

   if (data->x != data->y) throw Wrong_Matrix_Sizes();
   if (size == 1) 
   { 
      wyznacznik = matrix[0][0];
   }else if (size == 2) 
   {
      wyznacznik = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
   }else 
   {
      wyznacznik = 0;
      for (int k = 0; k < size; k++) 
      {
	 int i;
	 try
	 {
	    temp = new double* [size-1];
	    for (i = 0; i < size-1; i++) temp[i] = new double [size-1];
       	 }catch(bad_alloc)
	 { 
	    for(i; i >=0; i--) delete [] temp[i];
	    delete [] temp;
	    cout << "Nie udalo sie przydzielic pamieci!" << endl;
	 }
         for (int i = 1; i < size; i++) 
         {
            rozmiar = 0;
            for (int j = 0; j < size; j++) 
            {
               if(j == k) continue;
               temp[i-1][rozmiar] = matrix[i][j];
              rozmiar++;
            }
         }
         
         if(k%2 == 0)
         {
              wyznacznik += matrix[0][k] * Determinant(temp,size-1);
         }else
         {
              wyznacznik -= matrix[0][k] * Determinant(temp,size-1);
         }
         
         for (int z = 0; z < size-1; z++) delete [] temp[z];
         delete [] temp;
      }
   }
   return wyznacznik;
}
double CMatrix::dethelp()
{
	return Determinant(data->matrix, data->x);
}

/*bool CMatrix:: operator !=(const CMatrix& a)
{
if(data->x==a.data->x && data->y==a.data->y)
{
for(int i=0;i<data->x;i++)
{
        for(int j=0;j<data->y;j++)
        {
                if(data->matrix[i][j]!=a.data->matrix[i][j]) return true;
        }
}
else return false;
}
else
{cout<<"zly wymiar"<<endl;}
}
*/
int main ()
{
try
{
CMatrix tab1(3,3);
CMatrix tab2(3,3,7);


cout << tab1 << endl;
cout << tab2 << endl;

CMatrix tab4(3,3);
CMatrix tab3(3,3);
tab3.Rand();
CMatrix tab5(3,3);
tab5.Rand();

cout<<"tablica z wylosowanymi elementami\n" <<endl;
cout<<tab3<<endl;
tab4 = tab3 * tab5;
cout<<"pomnozone tablice dróga i trzecia"<<endl;
cout <<tab4 << endl;

cout<<"wyznacznik tab 3"<<endl;
cout<<tab3.dethelp()<<endl;

cout<<"transpozycja"<<endl;
cout<<tab4.trans()<<endl;

CMatrix taba(1,4);
CMatrix tabb(3,2);
CMatrix tabc(5,2);

tabc=taba*tabb;

cout<<tabc<<cout;

}catch(CMatrix::IndexOutOfRange&)
{
	cout << "Odwolanie do elementu macierzy poza dozwolonym zakresem!" << endl;
}catch(CMatrix::WrongDim&)
{
	cout << "Nieprawidlowy wymiar!" << endl;
}

system("PAUSE");
}
