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
               
               Complex (const Complex &complex)  //konstruktor kopiujacy
               {
                       re=complex.re;
                       im=complex.im;
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
              
              Complex operator* (const Complex& co) const
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
              
              Complex operator/ (const Complex& co)const
              {
	           Complex n;
	           n.re = (this->re * co.re + this->im * co.im) / (pow(co.re,2)+pow(co.im,2));
	           n.im = (this->im * co.re - this->re * co.im) / (pow(co.re,2)+pow(co.im,2));
           	   return n;
              }
              
              
              Complex & operator/= (Complex co)
              {
                re = (this->re * co.re + this->im * co.im) / (pow(co.re,2)+pow(co.im,2));
                im = (this->im * co.re - this->re * co.im) / (pow(co.re,2)+pow(co.im,2));
                return *this;
              };
              
              
              Complex & operator-= (Complex co)
              {
                re -= co.re;
                im -= co.im;
                return *this;
              };
              
              double modul()
              {
	          return sqrt(re * re + im * im);
              }
              
              double argument()
              {
               return asin(re/modul());
              }
              
             
              friend ostream& operator<<(ostream& os,const Complex& ob)
              {
	          os << "" << ob.re << " + " << ob.im << "i";
	          return os;
              }
              
              friend Complex operator- (Complex, Complex);
              friend Complex sprzezenie(Complex );

};

Complex sprzezenie (Complex co)
{
      co.im=-co.im;
      return(co);
}       

Complex operator - (Complex co1, Complex co2)
{
	Complex n ;
	n=co1;
	n =co1 - co2;
	return n; 
}

int main()
{
    Complex s1(4,5);
    Complex s2(6,10);
    Complex s3(5,20);
    Complex s4;
s1/=s2;
    cout<<s1<<endl;
    
    system("PAUSE");
}
