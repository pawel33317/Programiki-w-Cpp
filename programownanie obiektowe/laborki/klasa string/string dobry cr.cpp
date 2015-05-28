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
       char *sstrchr(char*);                                                    //wyszukuje znak    
       friend ostream& operator<<(ostream&, const rcstring&);                   
       void check (unsigned int i) const;
       char read(unsigned int i) const;
       void write(unsigned int i, char c);
       char* my_strstr(char*)const;                                             //wyszukuje tekst
       char* change();                                                //zmienia kolejnoœæ znaków
       rcstring& operator+=(const rcstring &);
       rcstring operator+(const rcstring &) const;
       char operator[](unsigned int i) const;
       char& operator[](unsigned int i);
       bool rcstring::operator==(const rcstring & string);
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

bool rcstring::operator==(const rcstring & string)
{
           char* temp;
           temp=this->data->s;
           char* temp1 = (string.data->s);
           
     //      if ((*temp == '\0') && (*(s->data->s) == '\0'))
      //     return true;
           
           if ((this->data->size)==(string.data->size))
           {
            while(*temp)
            {
                                if (*temp!=*temp1)
                                {return false;}
            temp++;
            temp1++;
           }
           return true;
           }
           else return false;
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
  check(i);
  return data->s[i];
}

char& rcstring::operator[](unsigned int i)
{
  check(i);
  data = data->detach();
  return data->s[i];
}


char *rcstring::sstrchr(char  *key)
{
 char* temp;
 temp=this->data->s;
 
 while(*temp&&*temp!=*key)temp++;
 if(*temp=='\0')return NULL;
 return temp;
}

char* rcstring::my_strstr(char* txt) const
{
 char* temp=new char[data->size];;
 temp=this->data->s;

 if ((*temp == '\0') || (*txt == '\0'))
 return NULL;

while (*temp)
{
 char* temp1 = temp;
 char* temp2 = txt;
 while (*temp1 == *temp2 && *temp1 && *temp2)
 temp1++, temp2++;
 if (*temp2 == '\0')
 return temp;
 else
 if (*temp1 == '\0')
 return NULL;
 temp++;
}
}

unsigned int rcstring::lenght()
{
 return(data->size);
}

ostream& operator << (ostream& o, const rcstring& s)
{
	return o<<s.data->s;
}

char* rcstring::change()
{
	char* temp = new char[data->size];
	int i = data->size - 1;
    int j =	0;
	for(i; i >= 0; i--)
	{
		temp[j] = data->s[i];
		j++;
	}
	temp[j] = '\0';
	return temp;
}




int main()
{
   rcstring a;
   rcstring b;
   rcstring c;
   char *txt="r";
   a=("adrian");
   cout<<a<<endl;
   cout<<a.lenght()<<endl;
   txt=a.sstrchr(txt);
   cout<<*txt<<endl;
   cout<<a<<endl;
   //cout<<a.my_strstr("zad")<<endl;
   cout<<a.change()<<endl;
   b=("zdunczyk");
   cout<<(a+=b)<<endl;
   c=("qwerty");
   cout<<c[2]<<endl;
   c.write(2,'a');
   cout<<c<<endl;
   
   cout<<(c==c)<<endl;
   system("PAUSE");

}    
