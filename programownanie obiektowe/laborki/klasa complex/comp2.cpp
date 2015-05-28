#include<iostream>
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
               double re2,im2;
               re2=re;
               im2=im;
                re = (re2 * co.re - im2 * co.im);
                im = (re2 *co.im + im2 * co.re);
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
               double re2,im2;
               re2=re;
               im2=im;
                re = (re2 * co.re + im2 * co.im) / (pow(co.re,2)+pow(co.im,2));
                im = (im2 * co.re - re2 * co.im) / (pow(co.re,2)+pow(co.im,2));
                return *this;
              };
              
              
              Complex & operator-= (Complex co)
              {
                re -= co.re;
                im -= co.im;
                return *this;
              };
              
 	          bool operator== (const Complex & co)
	          {
		       return (re == co.re && im == co.im);
	          };

              bool operator!= (const Complex & co)
              {
		       return !(*this == co);
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
inline Complex
operator - (Complex s1, Complex s2)
{
  Complex n (s1);
  return n -= s2;
};


int main()
{
    Complex s1(4,5);
    cout<<"s1="<<s1<<endl;
    Complex s2(2,6);
    cout<<"s2="<<s2<<endl;
    cout<<"s1+s2="<<s1+s2<<endl;
    cout<<"s1-s2="<<s1-s2<<endl;
    cout<<"s1*s2="<<s1*s2<<endl;
    cout<<"s1/s2="<<s1/s2<<endl;
    
    cout<<"s1+="<<(s1+=s2)<<endl;
    
    Complex s3(1,2);
    Complex s4(5,2);    
    cout<<"s3-="<<(s3-=s4)<<endl;
    
    Complex s5(5,2);
    Complex s6(5,2);
    cout<<"s5*="<<(s5*=s6)<<endl;
    
    Complex s7(2,6);
    Complex s8(3,3);
    cout<<"s1/="<<(s1/=s2)<<endl;
        
    Complex s(3,5);
    cout<<"modul s="<<s.modul()<<endl;
    cout<<"argument s="<<s8.argument()<<endl;
    cout<<"sprzezenie s="<<sprzezenie(s)<<endl;    
    
    
    Complex sa(2,2);
    Complex sb(2,2);
    
    if(sa==sb)cout<<"liczby sa rowne"<<endl;
    else cout<<"liczby sa rozne"<<endl;

    system("PAUSE");
}
