#include <fstream>
#include <iostream>
using namespace std;


class IndexOutOfRange{};
class WrongDim{};
//class bad_alloc{};

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
CMatrix(fstream & f);


~CMatrix();
CMatrix & operator= (const CMatrix&);
CMatrix operator* (const CMatrix&);
CMatrix operator+ (const CMatrix&);
CMatrix operator- (const CMatrix&);
double & operator () (unsigned int, unsigned int);
CMatrix & operator+= (const CMatrix&);
CMatrix & operator-= (const CMatrix&);

friend ostream& operator<<(ostream&, const CMatrix&);

};


struct CMatrix::CMdat
{
double **matrix;
unsigned int n;
unsigned int x;
unsigned int y;

CMdat (unsigned int nx, unsigned int ny)
{
 unsigned int i;
	n=1;
	x=nx;
	y=ny;

          matrix=new double* [x];

          	for (i=0;i<x; i++)
            {
           	matrix[i]=new double [y];
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
	if(i==j)
	{
	data->matrix[i][j]=k;
	} else
 	data->matrix[i][j]=k;
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


inline CMatrix::CMatrix(fstream & f)
{
unsigned int i,j,x,y;
f >> x;
f >> y;

   data=new CMdat(x,y);
for (i=0;i<x;i++)
{
    for(j=0;j<y;j++)
	{
 	f >> data->matrix[i][j];
	}
}
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


ostream& operator << (ostream& o, const CMatrix& m)
{
unsigned int i,j;

for (i=0;i<m.data->x;i++)
{ o<<endl;
    for(j=0;j<m.data->y;j++)
	{
	cout.width(4);                                 //odstepy                          
	cout.precision(4);                             //dokladnosc
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


