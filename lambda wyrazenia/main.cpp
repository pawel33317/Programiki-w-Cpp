#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool porownaj( const int & a, const int & b )
{
    return a > b;
}

int main()
{
    //[]()->int { return 123; }();

//[] informujesz, �e zaczyna si� wyra�enie lambda
//( definiujesz argumenty funkcji*/ )->/*tu okre�lasz zwracany typ
//{
//   cia�o funkcji (zwane tak�e cia�em wyra�ania lambda)
//}( warto�ci argument�w z jakimi wyra�enie lambda ma zosta� wywo�ane )


    int iMojaZmienna =[]()->int { return 123; }();
    cout << "Wynik wyrazenia lambda: " << []()->int { return 123; }() << endl;

    cout << "Wynik wyrazenia lambda: " <<
        []( int a, int b )->int { return a * b; }( 5, 6 ) << endl;


    //WSKAZNIK NA WYRAZENIE
void (*wskaznik)(int x, int y )  =[]( int x, int y )-> void { printf( "Wyrazenie lambda: %d + %d = %d\n", x, y, x + y ); };
    wskaznik( 5, 6 );
    wskaznik( 7, 8 );

    /*srand( time( NULL ) );
    typedef vector < int > VDaneT;
    VDaneT dane( 10 );
    for( size_t i = 0; i < dane.size(); ++i )
         dane[ i ] = rand() % 50 + 1;

    sort( dane.begin(), dane.end(),[]( const int & a, const int & b )->bool { return a > b; } );

    for( size_t i = 0; i < dane.size(); ++i )
         printf( "%d, ", dane[ i ] );
*/


    srand( time( NULL ) );
    typedef vector < int > VDaneT;
    VDaneT dane( 10 );
    for( size_t i = 0; i < dane.size(); ++i )
         dane[ i ] = rand() % 50 + 1;

    sort( dane.begin(), dane.end(), porownaj );

    for( size_t i = 0; i < dane.size(); ++i )
         printf( "%d, ", dane[ i ] );



    return 0;

}
