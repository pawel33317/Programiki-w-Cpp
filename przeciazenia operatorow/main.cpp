#include <iostream>
#include <cmath>
using namespace std;

class CRational
{
private:
    int m_nLicznik;
    int m_nMianownik;
public:
    CRational(int nLicznik = 0, int nMianownik = 1)
    : m_nLicznik(nLicznik), m_nMianownik(nMianownik) { }
    operator float(){
     return m_nLicznik / static_cast<float>(m_nMianownik);
    }
    int Licznik() const { return m_nLicznik; }
    void Licznik(int nLicznik) { m_nLicznik = nLicznik; }
    int Mianownik() const { return m_nMianownik; }
    void Mianownik(int nMianownik)
    { m_nMianownik = (nMianownik != 0 ? nMianownik : 1); }
    void wypisz() const {cout << m_nLicznik << "/" << m_nMianownik << endl; }
    //CRational operator*(const CRational& Liczba) const;
};

/*CRational CRational::operator*(const CRational& Liczba) const
{
 return CRational(m_nLicznik * Liczba.m_nLicznik,
 m_nMianownik * Liczba.m_nMianownik);
}*/
CRational operator*(const CRational& Liczba1, const CRational& Liczba2)
{
 return CRational(Liczba1.Licznik() * Liczba2.Licznik(),
 Liczba1.Mianownik() * Liczba2.Mianownik());
}

int main()
{
CRational JednaPiata(8, 2), TrzyCzwarte(4, 2);
CRational Wynik = JednaPiata * TrzyCzwarte;
Wynik.wypisz();
CRational Polowa(1, 2);
CRational Calosc = Polowa * static_cast<CRational>(2);
Calosc = static_cast<CRational>(2) * Polowa;
Calosc.wypisz();
    return 0;
}
