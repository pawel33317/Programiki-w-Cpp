#include <iostream>
#include <memory.h>
using namespace std;

class CIntArray
{
static const unsigned DOMYSLNY_ROZMIAR = 5;
private:
    unsigned m_uRozmiar;
    int* m_pnTablica;
public:
    CIntArray()
        : m_uRozmiar(DOMYSLNY_ROZMIAR),m_pnTablica(new int [m_uRozmiar]) {
        cout << "konst bezparam" << endl;
        }
     explicit CIntArray(unsigned uRozmiar)
        : m_uRozmiar(uRozmiar), m_pnTablica(new int [m_uRozmiar]) {
        cout << "konst 1 param" << endl;
        }

    CIntArray(const CIntArray& aTablica){
        cout << "konst kopiujacy" << endl;
        m_uRozmiar = aTablica.m_uRozmiar;
        m_pnTablica = new int [m_uRozmiar];
        memcpy (m_pnTablica, aTablica.m_pnTablica, m_uRozmiar * sizeof(int));
    }

    ~CIntArray() { delete[] m_pnTablica; }

    CIntArray& operator=(const CIntArray& aTablica) {
        cout << "przeciazenie =" << endl;
        if (&aTablica == this) return *this;
        delete[] m_pnTablica;
        m_uRozmiar = aTablica.m_uRozmiar;
        m_pnTablica = new int [m_uRozmiar];
        memcpy (m_pnTablica, aTablica.m_pnTablica, m_uRozmiar * sizeof(int));
        return *this;
    }

    int& operator[](unsigned uIndeks) {
        cout << "przeciazenie []" << endl;
        return m_pnTablica[uIndeks < m_uRozmiar ? uIndeks : m_uRozmiar-1]; }

    int Pobierz(unsigned uIndeks) const
        { if (uIndeks < m_uRozmiar) return m_pnTablica[uIndeks];
        else return 0; }
    bool Ustaw(unsigned uIndeks, int uWartosc)
        { if (uIndeks >= m_uRozmiar) return false;m_pnTablica[uIndeks] = uWartosc; return true; }

    unsigned Rozmiar() const { return m_uRozmiar; }
};

int main()
{
    //deklaracja
    CIntArray aTablica1(6);
    // inicjalizacja
    CIntArray aTablica2 = aTablica1;

    //przypisanie
    CIntArray aTablica5(7), aTablica6(8);
    aTablica5 = aTablica6;

    aTablica5[0] = 12;
    aTablica5[1] = 42;

    cout << aTablica5[0] << endl;
    cout << aTablica5[1] << endl;
    cout << aTablica5[132] << endl;
    //przez explict bo by wywoa³a³o konstruktor 1 parm
    //CIntArray aTablica4;
    //aTablica4 = 10;
    return 0;
}



