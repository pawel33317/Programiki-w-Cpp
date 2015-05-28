#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
/*
6. Obs³uga strumienia wyjœciowego (lekcja)
9. Obs³uga strumienia wejœciowego (lekcja)
16. Pseudolosowe liczby ca³kowite #include <cstdlib>#include <ctime>
19. Przekazywanie tablic jednowymiarowych do funkcji
*/
void wypelnijTablice( int *t, int iRozmiar )
{
    std::cout << "Podaj " << iRozmiar << " liczb:" << std::endl;
    int i = 0;do{
        t[i] = i;
        i++;
    } while( i < iRozmiar );
}

int main()
{
//6
    printf( "Czy %d jest wieksze od %s?", 3 + 4, "siedem" );
    std::cout << "\t tekst \"C:\\Hej\\ho.txt.\"" << std::endl;
    cout << "Hello world!" << endl;
//7
    int a;
    std::cout << "Podaj liczbe calkowita: ";
    std::cin >> a;
    std::cout << "Czy udalo sie wczytac? " << std::cin.good() << std::endl;
    std::cout << "Czy cos nawalilo? " << std::cin.fail() << std::endl;
    std::cout << "Liczba a = " << a << std::endl;
        //std::getline( std::cin, tekst );
        //reszta z dzielenia
        int r1 = 5.44;
        int r2 = 654.34;
        std::cout << "a % b = " << r1 % r2 << std::endl;
//16
    srand( time( NULL ) );
    std::cout << "Wylosowanie pierwsze: " << std::rand() << std::endl;
    int liczba = std::rand();
    std::cout << "Wylosowanie drugie: " << liczba << std::endl;
    liczba = std::rand();
    std::cout << "Wylosowanie trzecie: " << liczba << std::endl;
        //int wylosowana_liczba =( std::rand() % ile_liczb_w_przedziale ) + startowa_liczba;
//19
    int moja_tablica[5];
    wypelnijTablice( moja_tablica, 5 );
    int i = 0;
    do{
        std::cout << moja_tablica[ i ] << ", ";i++;
    } while( i < 5 );

    return 0;
}
