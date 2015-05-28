#include <iostream>
using namespace std;

class X
{
public:
  virtual void f (double a)
  {
    cout << "X::f with parameter "<<a<<endl;
  }
  virtual ~X(){};
};


class Y: public X
{
public:
  void f (double a)
  {
    cout << "Y::f with parameter "<<a<<endl;
  }
};

typedef void (X::*pf) (double);	// pointer to member

void
test (X * p, X * q)
{
  pf m = &X::f;
  (p->*m)(6.0);
  (q->*m)(7.0);
}

int
main ()
{
  X i;
  Y j;
  test (&i, &j);
}
