#include <iostream>
#include <list>
#include <string>
using namespace std;

class IZadanie{public:string rodzaj; int a=5; int b=6;}; //powinien byc abstrakcyjne ... virtual =0 cos
class dodawanie :public IZadanie{public:dodawanie(){rodzaj = "dodawanie";}};
class odejmowanie :public IZadanie{public:odejmowanie(){rodzaj = "odejmowanie";}};
class mnozenie :public IZadanie{public:mnozenie(){rodzaj = "mnozenie";}};
class dzielenie :public IZadanie{public:dzielenie(){rodzaj = "dzielenie";}};

class IObiektObslugujacy
{public:virtual bool obslugaZadania( IZadanie * pZadanie ) = 0;};

class ObsDodawanie :public IObiektObslugujacy{
    public:
        ObsDodawanie(){};
        bool obslugaZadania( IZadanie * pZadanie ){
        if (pZadanie->rodzaj == "dodawanie"){
            cout << "Suma = " << pZadanie->a+pZadanie->b << endl;
            return true;
        }
        return false;
    };};
class ObsOdejmowanie :public IObiektObslugujacy{
    public:bool obslugaZadania( IZadanie * pZadanie ){
        if (pZadanie->rodzaj == "odejmowanie"){
            cout << "Roznica = " << pZadanie->a-pZadanie->b << endl;
            return true;
        }
        return false;
    };};
class ObsMnozenie :public IObiektObslugujacy{
    public:bool obslugaZadania( IZadanie * pZadanie ){
        if (pZadanie->rodzaj == "mnozenie"){
            cout << "Iloczyn = " << pZadanie->a*pZadanie->b << endl;
            return true;
        }
        return false;
    };};
class ObsDzielenie :public IObiektObslugujacy{
    public:bool obslugaZadania( IZadanie * pZadanie ){
        if (pZadanie->rodzaj == "dzielenie"){
            cout << "Iloraz = " << static_cast<float>(pZadanie->a)/static_cast<float>(pZadanie->b) << endl;
            return true;
        }
        return false;
    };};

class CLancuchZobowiazan
{
protected:
    std::list < IObiektObslugujacy *> m_vObsluga;
public:
    bool obsluzZadanie( IZadanie * pZadanie )
    {
        for( std::list < IObiektObslugujacy *>::iterator i = m_vObsluga.begin(); i != m_vObsluga.end(); i++ )
        {
            if(( * i )->obslugaZadania( pZadanie ) )
                 return true;
        }
        return false;
    }
    void dodajIObiektObslugujacy(IObiektObslugujacy * ob){
        m_vObsluga.push_back(ob);
    }
};


int main ()
{
    //tworzymy obiekty obslugujace zdarzenia
    CLancuchZobowiazan CLancuchZobowiazan1;
    IObiektObslugujacy* dod = new ObsDodawanie;
    IObiektObslugujacy* ode = new ObsOdejmowanie;
    IObiektObslugujacy* mno = new ObsMnozenie;
    IObiektObslugujacy* dzi = new ObsDzielenie;

    //dodajemy te obiekty do lancucha
    CLancuchZobowiazan1.dodajIObiektObslugujacy(dod);
    CLancuchZobowiazan1.dodajIObiektObslugujacy(ode);
    CLancuchZobowiazan1.dodajIObiektObslugujacy(mno);
    CLancuchZobowiazan1.dodajIObiektObslugujacy(dzi);

    IZadanie* zad1 = new dodawanie();
    IZadanie* zad2 = new dzielenie();

    CLancuchZobowiazan1.obsluzZadanie(zad1);
    CLancuchZobowiazan1.obsluzZadanie(zad2);
	return 0;
}
