#include <cstdio>
#include <vector>

class IFiltr
{
public:
    virtual bool sprawdz( int iLiczba ) = 0;
}; //class IFiltr

class CParzyste: public IFiltr
{

public:
    CParzyste() { };
    virtual bool sprawdz( int iLiczba )
    {
        return iLiczba % 2 == 0;
    }

    static IFiltr * getSingleton()
    {
        static CParzyste singleton;
        return & singleton;
    }

}; //class CParzyste

class CNieparzyste
    : public IFiltr
{
    CNieparzyste() { };
public:
    virtual bool sprawdz( int iLiczba )
    {
        return iLiczba % 2 != 0;
    }

    static IFiltr * getSingleton()
    {
        static CNieparzyste singleton;
        return & singleton;
    }
}; //class CNieparzyste

class CLiczby
{
    typedef std::vector < int > LiczbyT;
    LiczbyT m_vLiczby;
    IFiltr * m_pFiltr;
public:
    CLiczby()
        : m_pFiltr( NULL )
    {
    }

    void push_back( int iLiczba )
    {
        m_vLiczby.push_back( iLiczba );
    }

    void ustawFiltr( IFiltr * pFiltr )
    {
        m_pFiltr = pFiltr;
    }

    void wypisz()
    {
        for( LiczbyT::const_iterator i = m_vLiczby.begin(); i != m_vLiczby.end(); i++ )
        if( !m_pFiltr || m_pFiltr->sprawdz( * i ) )
             printf( "%d ", * i );

        printf( "\n" );
    }

}; //class CLiczby

int main()
{
    CLiczby liczby;
    for( int i = 0; i < 10; i++ )
         liczby.push_back( i );

    liczby.wypisz();
    //liczby.ustawFiltr( CParzyste::getSingleton() );
    liczby.ustawFiltr( new CParzyste );
    liczby.wypisz();
    liczby.ustawFiltr( CNieparzyste::getSingleton() );
    liczby.wypisz();
    liczby.ustawFiltr( NULL );
    liczby.wypisz();
    return 0;
}
