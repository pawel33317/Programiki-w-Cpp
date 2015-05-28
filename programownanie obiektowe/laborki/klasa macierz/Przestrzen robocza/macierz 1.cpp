#include <iostream>
#include <string.h>
#include <stdio.h>
#include <malloc.h>

using namespace std;

class rcmatrix
{
       struct rcwart;
       rcwart* data;
      public:

}


struct rcmatrix::rcwart
{
  int** wart;
  unsigned int wiersze,kolumny;
  unsigned int odwolania;

rcwart(int w,unsigned int k, int wartosc)
  {
    int **wart;
    odwolania=1;
    wiersze=w;
    kolumny=k;
    wart=new int*[wiersze];
    for(int i=0;i<wiersze;i++)
    {
            wart[i]=new int[kolumny];
    }
  };
~rcwart()
{
    if(--odwolania==0)
    {
    for(int i=0;i<wiersze;i++)
    {
            delete [] wart[i];
    }
    delete []wart;
    }
};

rcwart* detach()
  {
    if(odwolania==1)
      return this;
    rcwart* t=new rcwart(wiersze,kolumny,**wart);
    odwolania--;
    return t;
  };
  
void assign(int kwiersze,int kkolumny, const int **kwartosci)
{
     int y,z;
    if(wiersze!=kwiersze||kolumny!=kkolumny)
    {
     int** ns;
     ns=new int*[kwiersze];
     for(int i=0;i<kwiersze;i++)
     {
            ns[i]=new int[kkolumny];
     }
      wiersze=kwiersze;
      kolumny=kkolumny;
      
      for(y=0;y<wiersze;y++)
	  {
		for(z=0;z<kolumny;z++)
		{
			ns[y][z]=kwartosci[y][z];
		}
	  }
      delete [] wart;
      wart = ns;
    }
    else
      {
          for(y=0;y<wiersze;y++)
	      {
	      	for(z=0;z<kolumny;z++)
		   {
			wart[y][z]=kwartosci[y][z];
           }
	      }
       }
      
   
}

private:
 rcwart(const rcwart&);
 rcwart& operator=(const rcwart&);
};

inline rcmatrix::rcmatrix()
  {
    data = new rcwart(1,1,0);
  }



inline rcmatrix::rcmatrix(const rcmatrix& x)
  {
    x.data->odwolania++;
    data=x.data;
  }
inline rcmatrix::~rcmatrix()
{
  if(--data->odwolania==0)
    delete data;
}

rcmatrix& rcmatrix::operator=(const rcmatrix & x)
{
  x.data->odwolania++;
  if(--data->n == 0)
    delete data;
  data=x.data;
  return *this;
}

rcmatrix::rcmatrix(const int** s)
{
// data=new rcwart(strlen(s),s);
}
/*
rcmatrix& rcmatrix::operator=(const char* s)
{
  if(data->n==1)
    data->assign(strlen(s),s);
  else
  {
    rctext* t = new rctext(strlen(s),s);
    data->n--;
    data= t;
  };
  return *this;
}
*/


int main()
{
    rcmatrix s(3,4,2);
    system("PAUSE");    
}
