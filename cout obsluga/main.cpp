#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    //justowanie
    int l =- 3;
    cout << l << endl;
    cout.width( 10 );
    cout << left << l << endl;
    cout.width( 10 );
    cout << right << l << endl;
    cout.width( 10 );
    cout << internal << l << endl;

    //typ zmiennej wyswietlania
    l = 59;
    cout.setf( ios::hex, ios::basefield );
    cout << l << endl; //3b
    cout.setf( ios::oct, ios::basefield );
    cout << l << endl; //73
    cout.setf( ios::dec, ios::basefield );
    cout << l << endl; //5

    //pokazuje znak liczby
    int a = 59;
    cout.setf( ios::showpos );
    cout << a << endl; //+59


    //powiekszenie liter w zapisie szesnastkowym
    l = 59;
    cout.setf( ios::hex, ios::basefield );
    cout.setf( ios::uppercase );
    cout << l << endl; //3B


    //wypisuje nawet nieznacz¹ce zera i kropkê dziesiêtn¹
    float x = 1175;
    cout << x << endl; //1175
    cout.setf( ios::showpoint );
    cout << x << endl; //1175.00


    //nitacja wykladnicza
    x = 1175;
    cout << x << endl; //1175
    cout.setf( ios::scientific );
    cout << x << endl; //1.175000e+003
    cout.setf( ios::fixed );


    cout << endl << endl << endl;
    //na ilu polach ma wypisac liczbe
    long kwota[] = { 120, 1650000, 5200, 190000123 };
    for( int i = 0; i < 4; i++ )
    {
        cout << "Rachunek nr ";
        cout.width( 2 );
        cout << i << " opiewa na sume :";
        cout.width( 10 );
        cout << kwota[ i ] << " DM\n";
    }


    cout << endl << endl << endl;
    //wype³nianie
    long kwota1[] = { 120, 1650000, 5200, 190000123 };
    for( int i = 0; i < 4; i++ )
    {
        cout << "Rachunek nr ";
        cout.width( 2 );
        cout.fill( '*' );
        cout << i << " opiewa na sume :";
        cout.width( 10 );
        cout.fill( '_' );
        cout << kwota1[ i ] << " DM\n";
    }


    cout << endl << endl << endl;
    //dok³adnoœæ
    double kwota2[] = { 1.123456789123, 2.12345, 3.1 };
    cout << kwota2[ 0 ] << " DM\n"; //bez formatowania polazuje tylko 6 miejsc
    cout.precision( 15 );
    for( int i = 0; i < 3; i++ )
    {
        cout << "Rachunek nr ";
        cout << i << " opiewa na sume :";
        cout << kwota2[ i ] << " DM\n";
    }


    //kolor czcionki
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),
                            FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << "Zielony napis" ;





    HANDLE hOut;

    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    cout << "Standart" << endl << endl;

    SetConsoleTextAttribute( hOut, BACKGROUND_RED );
    cout << "This text is red." << flush << endl << endl;

    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
    cout << "This text is green." << endl << endl;

    SetConsoleTextAttribute( hOut, FOREGROUND_BLUE );
    cout << "This text is blue." << endl << endl;






    return 0;
}










