#ifndef __Complex_H__
#define __Complex_H__
#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
private:
  double Real, Imag;
public:
    Complex ():Real (0), Imag (0)
  {
  };

  Complex (double co)
  {
    Real = co;
    Imag = 0;
  };

  Complex (double Real, double Imag)
  {
    this->Real = Real;
    this->Imag = Imag;
  };

  Complex & operator= (const Complex & s)
  {
    Real = s.Real;
    Imag = s.Imag;
    return *this;
  };

  Complex operator- () const
  {
    return Complex(-Real,-Imag);
  };

  Complex & operator= (double co)
  {
    Real = co;
    Imag = 0;
    return *this;
  };

  Complex operator+ (const Complex& co) const
  {
    Complex n;
    n.Real = this->Real + co.Real;
    n.Imag = this->Imag + co.Imag;
    return n;
  };


  Complex & operator+= (Complex co)
  {
    Real += co.Real;
    Imag += co.Imag;
    return *this;
  };

  Complex & operator-= (Complex co)
  {
    Real -= co.Real;
    Imag -= co.Imag;
    return *this;
  };


  friend Complex operator- (Complex, Complex);
  friend ostream & operator << (ostream & s, const Complex & c)
  {
    s << "(" << c.Real << "," << c.Imag << ")";
    return s;
  };
};

inline Complex
operator - (Complex s1, Complex s2)
{
  Complex n (s1);
  return n -= s2;
};

#endif /* __Complex_H__ */
