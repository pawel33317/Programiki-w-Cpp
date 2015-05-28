#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

int main()
{
   double liczba;
    cout << "Podaj liczbe: ";
    cin >> liczba;
    cout << "round(" << liczba << ")=" << round( liczba ) << endl;
    cout << "ceil(" << liczba << ")=" << ceil( liczba ) << endl;
    cout << "floor(" << liczba << ")=" << floor( liczba ) << endl;
    cout << endl << "------------" << endl << endl;

   double stopnie;
    cout << "Podaj kat w stponiach: ";
    cin >> stopnie;
    double radiany =( stopnie * M_PI ) / 180.0f;
    cout << "radiany: " << radiany << endl;
    cout << endl << "------------" << endl << endl;


double liczba2, potega;
    cout << "Podaj liczbe: ";
    cin >> liczba2;
    cout << "Do ktorej potegi podniesc liczbe " << liczba2 << "? Wpisz wartosc: ";
    cin >> potega;
    cout << "pow(" << liczba2 << "," << potega << ")=" << pow( liczba2, potega ) << endl;
    cout << endl << "------------" << endl << endl;

    cout << "Podaj liczbe: ";
    cin >> liczba;
    double wynik = pow( liczba,( 1 / 5.0 ) ); //lub poprostu: pow(liczba,0.2);
    cout << "Pierwiastek stopnia piatego z liczby " << liczba << " to: " << wynik << endl;

    return( 0 );
}
