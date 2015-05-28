#include <iostream>
using namespace std;

class X
{
  double g (double a)
  {
    return a * a + 5.0;
  }
  double h (double a)
  {
    return a - 13;
  }
public:
  void test (X *, X);
};

typedef double (X::*pf) (double);	// pointer to member

void
X::test (X * p, X q)
{
  double g5 = p->g (5.0);	// call directly
  double h5 = p->h (5.0);	// call directly
  double g10 = q.g (10);	// call directly
  double h10 = q.h (10);	// call directly

  cout << "g5 = " << g5 << "\n ";
  cout << "h5 = " << h5 << "\n ";
  cout << "g10 = " << g10 << "\n ";
  cout << "h10 = " << h10 << "\n ";

  pf m1 = &X::g;
  pf m2 = &X::h;
  double g6 = (p->*m1) (6.0);	// call through pointer to member
  double h6 = (p->*m2) (6.0);	// call through pointer to member
  double g12 = (q.*m1) (12);	// call through pointer to member
  double h12 = (q.*m2) (12);	// call through pointer to member

  cout << "g6 = " << g6 << "\n ";
  cout << "h6 = " << h6 << "\n ";
  cout << "g12 = " << g12 << "\n ";
  cout << "h12 = " << h12 << "\n";
}

int
main ()
{
  X i;
  i.test (&i, i);
}
