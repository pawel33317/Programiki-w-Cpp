#include <iostream>
#include <cmath>
using namespace std;

class CRational
{
private:
    int m_nLicznik;
    int m_nMianownik;
public:
    CRational(int nLicznik, int nMianownik)
    : m_nLicznik(nLicznik), m_nMianownik(nMianownik) { }

    CRational(int nLiczba)
    : m_nLicznik(nLiczba), m_nMianownik(1) { }

//explicit s³owo kluczowe przed konstruktorem blokuje konstruktor przed konwertowaniem

    //te 4 linie wy¿ej w skrócie zostawiam dla zrozumienia
    //CRational(int nLicznik = 0, int nMianownik = 1)
    //: m_nLicznik(nLicznik), m_nMianownik(nMianownik) { }

operator float()
{
 return m_nLicznik / static_cast<float>(m_nMianownik);
}


    int Licznik() const { return m_nLicznik; }
    void Licznik(int nLicznik) { m_nLicznik = nLicznik; }
    int Mianownik() const { return m_nMianownik; }
    void Mianownik(int nMianownik)
    { m_nMianownik = (nMianownik != 0 ? nMianownik : 1); }
};

CRational Pomnoz(const CRational& Liczba1, const CRational& Liczba2)
{
    return CRational(Liczba1.Licznik() * Liczba2.Licznik(),
    Liczba1.Mianownik() * Liczba2.Mianownik());
}


int main()
{
    CRational Raz(1, 2), Dwa(2, 3);
    CRational Wynik = Pomnoz(Raz, Dwa);

    CRational Wynik2 = Pomnoz(Raz, 5);

    float fPierwiastek = sqrt(Wynik);


    return 0;
}
