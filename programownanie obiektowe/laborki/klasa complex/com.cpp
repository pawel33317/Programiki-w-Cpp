#include<iostream>;
#include <math.h>

using namespace std;

class Complex
{
      private:
              double re,im;
      public:
               
               Complex ():re (0), im (0)
               {
               };
               
               Complex (double co)
               {
                    re = co;
                    im = 0;
               };
               
               Complex (double re, double im)
               {
                this->re = re;
                this->im = im;
               };
               
               ~Complex()
               {
               }
                         
               
               Complex & operator= (const Complex & s)
              {
                re = s.re;
                im = s.im;
                return *this;
              };
            
              Complex operator- () const
              {
                return Complex(-re,-im);
              };
            
              Complex & operator= (double co)
              {
                re = co;
                im = 0;
                return *this;
              };
            
              Complex operator+ (const Complex& co) const
              {
                Complex n;
                n.re = this->re + co.re;
                n.im = this->im + co.im;
                return n;
              };
            
            
              Complex & operator+= (Complex co)
              {
                re += co.re;
                im += co.im;
                return *this;
              };
              
              Complex operator* (Complex co)
              {
	           Complex n;
	           n.re = (this->re * co.re - this->im * co.im);
	           n.im = (this->re * co.im + this->im * co.re);
	           return n;
              };
            
            
              Complex & operator*= (Complex co)
              {
                re = (this->re * this->re - this->im * this->im);
                im = (this->re *this->im + this->im * this->re);
                return *this;
              };
              
              Complex operator/ (Complex co)
              {
	           Complex n;
	           n.re = (this->re * co.re + this->im * co.im) / co.modul(co);
	           n.im = (this->im * co.re - this->re * co.im) / co.modul(co);
           	   return n;
              }
              
              /*
              Complex & operator/= (Complex co)
              {
                re = (this->re * this->re + this->im * this->im)/this->modul(this);
                im = (this->re *this->im - this->im * this->re)this->modul(this);
                return *this;
              };
              */
              
              Complex & operator-= (Complex co)
              {
                re -= co.re;
                im -= co.im;
                return *this;
              };
              
              double Complex::modul(Complex co)
              {
	          return sqrt(co.re * co.re + co.im * co.im);
              }
              
              Complex :: sprzezenie()
              {
               this->im=-(this->im);
               return *this;
              };
/*              
              Complex operator - (Complex s1, Complex s2)
              {
	           Complex n (s1);
	           return n -= s2;
              };
*/              
              friend ostream& operator<<(ostream& os,const Complex& ob)
              {
	          os << "" << ob.re << " + " << ob.im << "i";
	          return os;
              }

};

int main()
{
    Complex s1(4,5);
    Complex s2(6,10);
    Complex s3(5,20);
    cout<<s1.sprzezenie<<endl;

    system("PAUSE");
}
