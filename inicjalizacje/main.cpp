#include <iostream>

using namespace std;


class CFoo
{
 private:
 const float m_fPole;
 // nie mo�e by�: const float m_fPole = 42; !!

 public:
 // konstruktor - inicjalizacja pola
 CFoo() : m_fPole(42)
 {
 /* m_fPole = 42; // te� nie mo�e by� - za p�no!
 // m_fPole musi mie� warto�� ju�
 // na samym pocz�tku wykonywania
 // konstruktora */
 }
  CFoo(double pole) : m_fPole(pole)
 {
 /* m_fPole = 42; // te� nie mo�e by� - za p�no!
 // m_fPole musi mie� warto�� ju�
 // na samym pocz�tku wykonywania
 // konstruktora */
 }
};

int main()
{
    CFoo* a = new CFoo();
    CFoo* b = new CFoo(3.33);
    CFoo* c = new CFoo(33.33);
    return 0;
}
