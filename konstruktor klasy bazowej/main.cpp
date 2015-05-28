#include <iostream>

using namespace std;

class v1
{
 protected:
 int m_nPole1;
 public:
 v1(int nPole1) : m_nPole1(nPole1) { }
 friend int main();
};

class v2 : public v1
{
 public:
 v2(int nPole1) : v1(nPole1) { }
};

class v3 : public v2
{
 protected:
 float m_fPole2;

 public:
 v3(int nPole1, float fPole2) : v2(nPole1), m_fPole2(fPole2) { }
  friend int main();
};


int main()
{
    v3* moje = new v3(4,33.33);
    cout << (*moje).m_nPole1 << "  ---  " << moje->m_fPole2 ;
    return 0;
}
