#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

//deklaracja
namespace przestrzen{
    const double stalaG = 6.33;
    double getG();
}

template <typename T>
T funkcjaZtemplate (T arg1)
{
    return arg1*2;
};


int main()
{
    //przestrzenie nazw
    cout << przestrzen::getG() << endl;


    string wczytaniezKlawiatury;
    cin >> wczytaniezKlawiatury;
    cout << wczytaniezKlawiatury << endl;


    int* przydzialPamieci = (int*) malloc (sizeof(int));
    *przydzialPamieci = 112;
    int* przydzialPamieci2 = new int;
    *przydzialPamieci2 = 113;
    delete przydzialPamieci;
    delete przydzialPamieci2;


    int liczba = 5, liczba2 = 2;
    double liczba3;
    liczba3 = static_cast<float>(liczba)/static_cast<float>(liczba2);
    cout << endl << liczba3 << endl;


    const double stala = 4.44;
    const double * wskaznikNaStala = &stala;
    double * wskaznikNaZmienna;
    wskaznikNaZmienna = const_cast<double *>(wskaznikNaStala);
    cout << endl << stala << endl;
    cout << *wskaznikNaStala << endl;
    cout << *wskaznikNaZmienna << endl;

    cout << "adres zmiennej " << reinterpret_cast<int>(wskaznikNaStala) << endl;


    int z = funkcjaZtemplate(2);
    double x = funkcjaZtemplate(2.2);

    cout << "int " << z << " double " << x << endl;

    int **tab2D = new int* [5];
    for(int i=0; i<5; i++){
        tab2D[i] = new int[5];
        for(int j=0; j<5; j++){
            tab2D[i][j] = i*j;
        }
    }
    for(int i=0; i<5; i++){
        delete[] tab2D[i];
    }
    delete[] tab2D;




    string a;
    cout << "Nacisnij Enter aby zakonczyc zapis.\n";
    //tworzy plik
    ofstream f ("acc.txt");
    cin >> a;
    if (f.good())
    {
        //zapisuje do pliku
        f << a;
        f.close();
    }
    cout << "zmienna a: " << endl << a << endl;
    //pobiera cala linie z konsoli czasami trzeba wyczyscic cin -> cin.ignore();
    //getline(cin, tekst);



    long xx;   // Zmienna do przechowania liczby
    string napis;   // Zmienna do przechowania napisu
    stringstream ss;  // Strumieñ do napisów
    cout << "Podaj dowolna liczbe calkowita: ";
    cin >> xx;
    ss << xx;   // Do strumienia 'wysy³amy' podan¹ liczbê
    napis = ss.str();   // Zamieniamy zawartoœæ strumienia na napis
    cout << "Dlugosc napisu wynosi " << napis.size() << " znakow." << std::endl;


    return 0;
}

//definicja
namespace przestrzen{
    double getG(){
        return stalaG;
    }
}
