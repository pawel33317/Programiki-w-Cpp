#include <cstdio>
#include <cstring>

class IPrototype
{
public:
    virtual IPrototype * Klonuj() const = 0;
    virtual void Wypisz() const = 0;
    virtual ~IPrototype() { }
};

class CMyPrototype1
    : public IPrototype
{
private:
    int m_iLiczba;
    char * m_pNapis;
public:
    CMyPrototype1( int iLiczba, const char * sNapis )
        : m_iLiczba( iLiczba )
        , m_pNapis( new char[ strlen( sNapis ) + 1 ] )
    {
        strcpy( m_pNapis, sNapis );
    }

    CMyPrototype1( const CMyPrototype1 & kopia )
        : m_iLiczba( kopia.m_iLiczba )
        , m_pNapis( new char[ strlen( kopia.m_pNapis ) + 1 ] )
    {
        strcpy( m_pNapis, kopia.m_pNapis );
    }

    virtual ~CMyPrototype1()
    {
        delete[] m_pNapis;
    }

    virtual IPrototype * Klonuj() const
    {
        //INFO: Przyk³adowa implementacja klonowania
        return new CMyPrototype1( * this );
    }

    virtual void Wypisz() const
    {
        printf( "Liczba = %d\n", m_iLiczba );
        printf( "Komunikat = \"%s\"\n", m_pNapis );
    }
};

int main()
{
    IPrototype * pObiekt1 = new CMyPrototype1( 123, "raz dwa trzy" );
    IPrototype * pObiekt2 = pObiekt1->Klonuj();
    delete pObiekt1;
    pObiekt2->Wypisz();
    delete pObiekt2;
    return 0;
}
