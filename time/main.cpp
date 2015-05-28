#include <time.h>
#include <conio.h>
#include <iostream>

using namespace std;
int main()
{
    //czas unixowy
    time_t sekundy;
    sekundy = time( NULL );
    cout << sekundy / 3600 << " godzin uplynelo od 1 stycznia 1970r.";
    cout << endl << "---------" << endl << endl;


    //!!!!!!!!!!!!!!!!!
    //godzina data sekundy wszystko :-)
    time_t czas;
    struct tm * data;
    char godzina[ 80 ];
    time( & czas );
    data = localtime( & czas );
    strftime( godzina, 80, "Teraz jest %H:%M:%S.", data );
    cout << godzina;
    cout << endl << "---------" << endl << endl;

    //dzien urodzenia
    int rok, miesiac, dzien;
    char * dzien_tygodnia[] = { "Niedziela", "Poniedzialek",
        "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota" };
    cout << "**Dzien urodzin**" << endl;
    cout << "Rok urodzenia: ";
    cin >> rok;
    cout << "Miesiac urodzenia: ";
    cin >> miesiac;
    cout << "Dzien urodzenia: ";
    cin >> dzien;
    time( & czas );
    data = localtime( & czas );
    data->tm_year = rok - 1900;
    data->tm_mon = miesiac - 1;
    data->tm_mday = dzien;
    mktime( data );
    cout << "Dzien Twoich narodzin to: " << dzien_tygodnia[ data->tm_wday ];


    return 0;
}
