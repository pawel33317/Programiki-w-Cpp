#include <iostream>
#include <math.h>

using namespace std;

class Cmplx
{
	private:
	double Re, Im;
	
	public:
	Cmplx ():Re (0), Im (0) { };

	Cmplx (double liczba)
	{
    		Re = liczba;
    		Im = 0;
  	};

	Cmplx (double Re, double Im)
	{
		this->Re = Re;
    		this->Im = Im;
  	};

	Cmplx & operator= (const Cmplx & s)
	{
		Re = s.Re;
		Im = s.Im;
		return *this;
	};

	Cmplx operator- () const
	{
		return Cmplx(-Re,-Im);
	};

	Cmplx & operator= (double liczba)
	{
		Re = liczba;
		Im = 0;
		return *this;
	};

	Cmplx operator+ (const Cmplx& c) const
	{
		Cmplx n;
		n.Re = this->Re + c.Re;
		n.Im = this->Im + c.Im;
		return n;
	};

	Cmplx & operator+= (Cmplx c)
	{
		Re += c.Re;
		Im += c.Im;
		return *this;
	};

	Cmplx & operator-= (Cmplx c)
	{
		Re -= c.Re;
		Im -= c.Im;
		return *this;
	};

	Cmplx operator* (const Cmplx& c) const
	{
		Cmplx n;
		n.Re = this->Re * c.Re;
		n.Im = this->Im * c.Im;
		return n;
	};

	Cmplx & operator*= (Cmplx c)
	{
		Re *= c.Re;
		Im *= c.Im;
		return *this;
	};

	Cmplx operator/ (const Cmplx& c) const
	{
		Cmplx n;
		n.Re = this->Re / c.Re;
		n.Im = this->Im / c.Im;
		return n;
	};

	Cmplx & operator/= (Cmplx c)
	{
		Re /= c.Re;
		Im /= c.Im;
		return *this;
	};

	bool operator== (const Cmplx & s)
	{
		return (Re == s.Re && Im == s.Im);
	};

	bool operator!= (const Cmplx & s)
	{
		return !(*this == s);
	};

	double Modul()
	{
		return sqrt(pow(Re,2) + pow(Im,2));
	}

	double Argument()
	{
		return tan(Im/Re);    // W RADIANACH
	}

	friend Cmplx operator- (Cmplx, Cmplx);
	friend ostream & operator << (ostream & s, const Cmplx & c)
	{
		s << "(" << c.Re << "," << c.Im << ")";
		return s;
	};
};

inline Cmplx
operator - (Cmplx s1, Cmplx s2)
{
	Cmplx n (s1);
	return n -= s2;
};

int main()
{
	Cmplx a(0.0,15),b(0,13),c;
	c = 10;
  	cout << c <<endl;
  	c = -a;
  	cout << c <<endl;  
  	c = a + b;
  	c = c - Cmplx(10);
  	cout << c <<endl;  
  	c = 10 - a;
  	(c +=b) +=10;
  	cout << c <<endl;
	cout << "-----------------------" << endl;
	if(a != b) cout << "rozne" << endl;
	Cmplx d(1,2), e(1,2);
	if(d == e) cout << "rowne" << endl;
	cout << "-----------------------" << endl;
	cout << d.Modul() << endl;
	cout << d.Argument() << endl;

	return 0;
}
