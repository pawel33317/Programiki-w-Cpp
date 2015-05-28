#include <iostream>
#include <fstream>

using namespace std;

int main()
{


    //wczytywanie metoda 1
    ifstream plik;
    plik.open( "a.txt" );
    if( plik.good() ){
       cout << "##otworzono plik" << endl;
    }
    else{
        cout << "##nie mozna otworzyc" << endl;
        getchar();
        return 1;
    }
    //GETLINE wczyta tylko pierwsza linie
    string tekstzPliku;
    getline(plik,tekstzPliku);
    cout << tekstzPliku << endl;
    //Pętla wczyta wszystkie
    string wiersz;
    while( getline( plik, wiersz ) )
         cout << wiersz << endl;
    plik.close();



    //wczytywanie metoda 2
    cout << "------------" << endl << endl;
    plik.open( "a.txt" );
    string www;
    while( !plik.eof() &&  !plik.bad())
    {
        plik >> www;
        cout << www << endl;
    }
    plik.close();
    cout << "------------" << endl << endl;



    //ZAPISYWANIE
    fstream plik1;
    plik1.open( "a.txt", ios::in | ios::out ); //zapis/odczyt
    if( plik1.good() == true ){
        cout << "Uzyskano dostep do pliku!" << endl;
    }
    else cout << "Dostep do pliku zostal zabroniony!" << endl;

    //przeesuniecie na koniec
    plik1.seekg( 0, ios_base::end );
    //metoda dopisywania1
    plik1 << "tekstDOPISANY"; //jak wiecej racu << to plik.flush()
    //metoda dopisywania 2
    string tddp = "nowytekst";
    plik1.write(&tddp[0],tddp.length());
    plik1.close();
    cout << "------------" << endl << endl;



    //odczyt z pliku
    plik.open( "a.txt" );
    plik.seekg( 11 );
    while( getline( plik, wiersz ) ){
        streampos iOdczytanaPozycja = plik.tellg();
        cout << wiersz << endl;
        cout << "Aktualna pozycja: " << iOdczytanaPozycja << endl;
    }
    plik.close();
    cout << "------------" << endl << endl;


    //odczyt z pliku blokami
    fstream plik2( "a.txt", std::ios::in );
    char bufor[ 1024 ];
    plik2.read( bufor, 1024 );
    cout << "Wczytano " << plik2.gcount() << " bajtow do bufora" << endl;
    int i = 0;
    while(i<plik2.gcount()){
        cout << bufor[i++];
    }
    plik2.close();


    return 0;
}
