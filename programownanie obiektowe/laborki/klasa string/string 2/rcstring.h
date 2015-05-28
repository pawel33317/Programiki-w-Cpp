#ifndef __RCSTRING_H__
#define __RCSTRING_H__
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;

class rcstring{
       struct rctext;
       rctext* data;
public:
       class Range{};
       rcstring();
       rcstring(const char*);
       rcstring(const rcstring&);
       ~rcstring();
       rcstring& operator=(const char*);
       rcstring& operator=(const rcstring&);
       rcstring& operator+=(const rcstring &);
       rcstring operator+(const rcstring &) const;
       friend ostream& operator<<(ostream&, const rcstring&);
       void check (unsigned int i) const;
       char read(unsigned int i) const;
       void write(unsigned int i, char c);

       char operator[](unsigned int i) const;
       char& operator[](unsigned int i);
       int atoi();
       void left(unsigned int n);
       void tolower();
};

struct rcstring::rctext
{
  char* s;
  unsigned int size;
  unsigned int n;

  rctext(unsigned int nsize, const char* p)
  {
    n=1;
    size=nsize;
    s=new char[size+1];
    strncpy(s,p,size);
    s[size]='\0';
  };
  ~rctext()
  {
    delete [] s;
  };
  rctext* detach()
  {
    if(n==1)
      return this;
    rctext* t=new rctext(size, s);
    n--;
    return t;
  };
  void assign(unsigned int nsize, const char *p)
  {
    if(size!=nsize)
    {
      char* ns=new char[nsize+1];
      size = nsize;
      strncpy(ns,p,size);
      delete [] s;
      s = ns;
    }
    else
      strncpy(s,p,size);
    s[size]='\0';
  }
private:
  rctext(const rctext&);
  rctext& operator=(const rctext&);
};

inline rcstring::rcstring()
  {
    data = new rctext(0,"");
  }

inline rcstring::rcstring(const rcstring& x)
  {
    x.data->n++;
    data=x.data;
  }
inline rcstring::~rcstring()
{
  if(--data->n==0)
    delete data;
}

rcstring& rcstring::operator=(const rcstring & x)
{
  x.data->n++;
  if(--data->n == 0)
    delete data;
  data=x.data;
  return *this;
}

rcstring::rcstring(const char* s)
{
 data=new rctext(strlen(s),s);
}

rcstring& rcstring::operator=(const char* s)
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

ostream& operator << (ostream& o, const rcstring& s)
{
	return o<<s.data->s;
}

rcstring& rcstring::operator+=(const rcstring & s)
{
unsigned int newsize=data->size+s.data->size;
rctext *newdata=new rctext(newsize,data->s);
strcat(newdata->s,s.data->s);
if(--data->n==0)
  delete data;
data = newdata;
return *this;
}

rcstring rcstring::operator+(const rcstring & s) const
{
  return rcstring(*this)+=s;
}

inline void rcstring::check (unsigned int i) const
{
if(data->size<=i)
  throw Range();
}

inline char rcstring::read(unsigned int i) const
{
 return data->s[i];
}

inline void rcstring::write(unsigned int i, char c)
{
  data = data->detach();
  data->s[i] = c;
}

char rcstring::operator[](unsigned int i) const
{
  cout << "char rcstring::operator[](unsigned int i) const"<<endl;
  check(i);
  return data->s[i];
}

char& rcstring::operator[](unsigned int i)
{
  cout << "char& rcstring::operator[](unsigned int i)"<<endl;
  check(i);
  data = data->detach();
  return data->s[i];
}

int rcstring::atoi()
{
  unsigned int i, j=1;
  int liczba=0;
  if((data->s[0]==45)||((data->s[0]>48)&&(data->s[0]<57))){
     for(i=1; i<(data->size-1); i++){
        if((data->s[i]<48)||(data->s[i]>57)){
        cout << "atoi niemozliwe1"<<endl;
        return 0;
        };
     };
     for(i=(data->size-1); i>0; i--, j*=10){
        liczba+=(data->s[i]-48)*j;
     }
     if(data->s[0]==45){
        return liczba*=(-1);
     }
     else{
        liczba+=(data->s[0]-48)*j;
        return liczba;
     }
  }
  cout << "atoi niemozliwe2"<<endl;
  return 0;
}

/*void rcstring::left(unsigned int n)
{
     if(n>data->size){
        cout << data->s <<endl;
        }
     else{
        unsigned int i;
            rctext *ndata=new rctext(n+1,"");
            for (i=0;i<n;i++){
               ndata->s[i]=data->s[i];
               }
            ndata->s[n]='\0';
            cout << ndata->s <<endl;
            delete ndata;
        }
}*/

/*void rcstring::tolower()
{
     unsigned int i;
     rctext *ndata=new rctext(data->size," ");
     for(i=0; i<data->size; i++){
        if((data->s[i]>64)&&(data->s[i]<91)){
           ndata->s[i]=(data->s[i])+32;
        }
        else{
           ndata->s[i]=data->s[i];
        }
     }
     cout << ndata->s <<endl;
     delete ndata;
}*/

void rcstring::tolower()
{
		int zm=0;
		for(unsigned int i=0;i<=data->size;i++)
		{
			if((data->s[i]>64)&&(data->s[i]<91))
			{
				zm=1;
			}
		}
		//krok2
		if(zm==1)
		{
			if(data->n==1)
			{
				for(unsigned i=0;i<=data->size;i++)
				{
					if((data->s[i]>64)&&(data->s[i]<91))
					{
						data->s[i]+=32;
					}
				}
			}
			else
			{
				data->n--;
				rcstring nowy;
				for(unsigned int i = 0; i < data->size; i++)
				{
					nowy.data->s[i]=data->s[i];
				}
				
				for(unsigned i=0;i<=data->size;i++)
				{
					if((nowy.data->s[i]>64)&&(nowy.data->s[i]<91))
					{
						nowy.data->s[i]+=32;
					}
				}
				this->data=nowy.data;
			}
		}

	
}

void rcstring::left(unsigned int n)
{
	if(n<data->size)
	{
		if(data->n==1)
		{
			char* ns;
			ns =new char[n+1];
			for (unsigned int i=0;i<n;i++){
				ns[i]=data->s[i];
			}
			ns[n]='\0';
			
			delete data->s;
			data->s=ns;
		}
		else
		{
			data->n--;
			rcstring nowy;
			for (unsigned int i=0;i<n;i++){
				nowy.data->s[i]=data->s[i];
			}
			nowy.data->s[n]='\0';
			this->data=nowy.data;
		}
	}

	
}

	
#endif /* __RCSTRING_H__ */
