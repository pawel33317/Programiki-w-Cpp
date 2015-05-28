#include <iostream>
#include <math.h>

using namespace std;

class complex {
double re, im;
public:
complex(double x=0, double y=0)
{
cout << "KONSTRUKTOR" << endl;
re = x;
im = y;
}
~complex()
{
cout << "DESTRUKTOR" << endl;
}
complex(const complex &a)
{
this->re=a.re;
this->im=a.im;
cout << "KOPIA KONSTRUKTORA" << endl;
}
complex operator+(const complex &a)
{
complex result(*this);
result.add(a);
return result;
}
complex operator*(const complex &a)
{
complex result(*this);
result.mul(a);
return result;
}
complex operator-(const complex &a)
{
complex result(*this);
result.sub(a);
return result;
}
complex operator/(const complex &a)
{
complex result(*this);
result.div(a);
return result;
}
complex &operator=(const complex &a)
{
this->re=a.re;
this->im=a.im;
return *this;
}
void add(complex a)
{
setRe( getRe() + a.getRe() );
setIm( getIm() + a.getIm() );
}
void sub(complex a)
{
setRe( getRe() - a.getRe() );
setIm( getIm() - a.getIm() );
}
void mul(complex a)
{ double tre, tim;
tre = getRe()*a.getRe() - getIm()*a.getIm() ;
tim = getRe()*a.getIm() + getIm()*a.getRe() ;
setRe(tre);
setIm(tim);
}
void div(complex a)
{ double mod2, tre, tim;
mod2=sqrt( a.getRe()*a.getRe() + a.getIm()*a.getIm() );
tre=(getRe()*a.getRe()+getIm()*a.getIm())/(mod2*mod2);
tim=(getIm()*a.getRe()-getRe()*a.getIm())/(mod2*mod2);
setRe(tre);
setIm(tim);
}
double getRe()
{
return re;
}
double getIm()
{
return im;
}
void setRe(double r)
{
re = r;
}
void setIm(double i)
{
im = i;
}
};

int main()
{
double x,y;

cout << "Pierwsza liczba zespolona" << endl;
cout << "Czesc rzeczywista: ";
cin >> x;
cout << "Czesc urojona: ";
cin >> y;

complex a(x,y);

cout << "Druga liczba zespolona" << endl;
cout << "Czesc rzeczywista: ";
cin >> x;
cout << "Czesc urojona: ";
cin >> y;

complex b(x,y);
complex c;

cout << "DODANIE LICZB = ";
//a.add(b);
c=a+b;
cout << c.getRe() <<" + " << c.getIm() << "i" << endl;
cout << "ROZNICA = ";
c=a-b;
cout << c.getRe() <<" + " << c.getIm() << "i" << endl;

cout << "MNOZENIE = " ;
c=a*b;
cout << c.getRe() <<" + " << c.getIm() << "i" << endl;

cout << "DZIELENIE = " ;
c=a/b;
cout << c.getRe() <<" + " << c.getIm() << "i" << endl;

system("pause");
return 0;
} 
