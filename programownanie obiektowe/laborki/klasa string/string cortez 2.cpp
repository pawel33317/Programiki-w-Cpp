#include<stdio.h>
#include<iostream>

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
       unsigned int lenght();
       char*sstrchr(const char*);
       friend ostream& operator<<(ostream&, const rcstring&);
       void check (unsigned int i) const;
       char read(unsigned int i) const;
       void write(unsigned int i, char c);

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

char* rcstring::sstrchr(const char* key)
{
 char* temp;
 temp=this->data->s;
 
 while(*temp&&*temp!=*key)temp++;
 if(*temp=='\0')return NULL;
 return temp;
}
/*          
char *strchr(const char *s, int c)
{
char* temp = (char*)s;
while (*temp && *temp != c) temp++;
if (*temp == '\0')
return NULL;
return temp;
}
*/
unsigned int rcstring::lenght()
{
 return(data->size);
}

ostream& operator << (ostream& o, const rcstring& s)
{
	return o<<s.data->s;
}

//char sstrcat(rcstring a, rcstring b)
//{
     


int main()
{

   rcstring a;
   char*s="a";
   a=("adrian");
   cout<<a<<endl;
   cout<<a.lenght()<<endl;
   s=a.sstrchr(s);
   cout<<s<<endl;
   system("PAUSE");


}    
