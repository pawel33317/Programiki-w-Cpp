#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class my_string{

	private:
  
	struct text_struct;
  	text_struct* data;

	public:
	
	class out_of_range{};
	class ref_class;
	my_string();
	my_string(const char*);
	my_string(const my_string&);
	~my_string();
	my_string& operator=(const char*);
	my_string& operator=(const my_string&);
	my_string& operator+=(const my_string &);
	my_string operator+(const my_string &) const;
	
	char* find_char(const char c);
	char* find_text(const char* s);
	char* reverse();
	int length();

	friend ostream& operator<<(ostream&, const my_string&);
	void check_range (unsigned int i) const;
	char read(unsigned int i) const;
	void write(unsigned int i, char c);
	char operator[](unsigned int i) const;
	ref_class operator[](unsigned int i);
	};

struct my_string::text_struct
{
  	char* s;
  	unsigned int size;
  	unsigned int n;

  	text_struct(unsigned int nsize, const char* p)
  	{
    		n=1;
    		size=nsize;
    		s=new char[size+1];
    		strncpy(s,p,size);
    		s[size]='\0';
  	};
  
	~text_struct()
	{
    		delete [] s;
  	};
  
	text_struct* detach()
  	{
    		if(n==1)return this;
    		text_struct* t=new text_struct(size, s);
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
    		}else  strncpy(s,p,size);
    		s[size]='\0';
  	}

	private:
	
	text_struct(const text_struct&);
	text_struct& operator=(const text_struct&);
};

class my_string::ref_class
{
  	friend class my_string;
  	my_string& s;
  	int i;
  
	ref_class (my_string& ss, unsigned int ii): s(ss), i(ii) {};
	
	public:
	
	operator char() const
	{
    		return s.read(i);
  	}
  
	my_string::ref_class& operator = (char c)
	{
		s.write(i,c);
    		return *this;
  	}
  
	my_string::ref_class& operator = (const ref_class& ref)
  	{
    		return operator= ((char)ref);
  	}
};

inline my_string::my_string()
{
    	data = new text_struct(0,"");
}

inline my_string::my_string(const my_string& x)
{
    	x.data->n++;
    	data=x.data;
}

inline my_string::~my_string()
{
  	if(--data->n==0) delete data;
}

my_string& my_string::operator=(const my_string & x)
{
  	x.data->n++;
  	if(--data->n == 0) delete data;
  	data=x.data;
  	return *this;
}

my_string::my_string(const char* s)
{
 	data=new text_struct(strlen(s),s);
}

my_string& my_string::operator=(const char* s)
{
  	if(data->n==1) data->assign(strlen(s),s);
  	else
  	{
    		text_struct* t = new text_struct(strlen(s),s);
    		data->n--;
    		data=t;
  	}
  	return *this;
}

ostream& operator << (ostream& o, const my_string& s)
{
  	return o<<s.data->s;
}

my_string& my_string::operator+=(const my_string & s)
{
	unsigned int newsize=data->size+s.data->size;
	text_struct *newdata=new text_struct(newsize,data->s);
	strcat(newdata->s,s.data->s);
	if(--data->n==0) delete data;
	data = newdata;
	return *this;
}

my_string my_string::operator+(const my_string & s) const
{
  	return my_string(*this)+=s;
}

char* my_string::find_char(const char c)
{
	int i = 0, nsize = data->size;
	while(nsize > 0)
	{
		if(read(i) == c) return (data->s + i);
		nsize--;		
		i++;
	}
	return NULL;
}

char* my_string::find_text(const char* s)
{
	int i = 0, nsize = data->size;
	while(nsize > strlen(s))
	{
		if(strncmp(data->s + i, s, strlen(s)) == 0) return (data->s + i);
		nsize--;
		i++;
	} 
	return NULL;
}

char* my_string::reverse()
{
	char* temp = new char[data->size];
	int j =	0;
	for(int i = data->size - 1; i >= 0; i--)
	{
		temp[j] = data->s[i];
		j++;
	}
	temp[j] = '\0';
	return temp;
}

int my_string::length()
{
	return data->size;
}

inline void my_string::check_range (unsigned int i) const
{
	if(data->size<=i) throw out_of_range();
}
inline char my_string::read(unsigned int i) const
{
 	return data->s[i];
}
inline void my_string::write(unsigned int i, char c)
{
  	data = data->detach();
  	data->s[i] = c;
}

char my_string::operator[](unsigned int i) const
{
  	check_range(i);
  	return data->s[i];
}

my_string::ref_class my_string::operator[](unsigned int i)
{
  	check_range(i);
  	return ref_class(*this,i);
}


int main()
{
my_string a,b,c;
a="10";
b="something";
cout << a << " " << b << endl; // 10 something
c=a+b;
cout << c<<endl; // 10something
c=a+my_string(" ")+b;
cout << c << endl; //10 something
my_string d("X");
cout << d <<endl; //X
d+="1337";
cout << d << endl; //X1337
d+=" leet";
cout << d << endl; //X1337 leet
cout << d[3]<<endl; //3
d[5]='_';
cout << d << endl; //X1337_leet
d[2]=d[1]=d[0];
cout << d << endl; //XXX37_leet
try
{
cout << d[40] << endl;
}catch(my_string::out_of_range&)
{
cout << "Index out of range!" << endl;
}


my_string temp("abcdefghijklmn");
cout << temp.find_char('g') << endl;
cout << temp.find_text("za") << endl;

char* tekst = temp.reverse();

cout << tekst << endl;

cout << "temp length = " << temp.length() << endl;

system("PAUSE");
return 0;
}

