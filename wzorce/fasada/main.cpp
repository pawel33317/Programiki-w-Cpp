#include<iostream>
#include<string>

using namespace std;

// Customer class
class Klient
{
public:
  Klient (const string& name) : name_(name){}
  const string& Name(void)
  {
    return name_;
  }
private:
  Klient(); //not allowed
  string name_;
};

// The 'Subsystem ClassA' class
class Bank
{
public:
  bool maDobryKredyt(Klient c, int ilosc)
  {
    cout << "Check bank for " <<c.Name()<<endl;
    return true;
  }
};

// The 'Subsystem ClassB' class
class Credit
{
public:
  bool maDobryKredyt(Klient c, int ilosc)
  {
    cout << "Check credit for " <<c.Name()<<endl;
    return true;
  }
};

// The 'Subsystem ClassC' class
class Pozyczka
{
public:
  bool maDobryKredyt(Klient c, int ilosc)
  {
    cout << "Check loans for " <<c.Name()<<endl;
    return true;
  }
};

// The 'Facade' class
class zadluzenie
{
public:
  bool czyNadajeSie(Klient cust, int ilosc)
  {
    cout << cust.Name() << " chce pozyczke w wysokosci $" << ilosc <<endl;
    bool nadajeSie = true;

    nadajeSie = bank_.maDobryKredyt(cust, ilosc);

    if(nadajeSie)
      nadajeSie = loan_.maDobryKredyt(cust, ilosc);

    if(nadajeSie)
      nadajeSie = credit_.maDobryKredyt(cust, ilosc);

    return nadajeSie;
  }

private:
  Bank bank_;
  Pozyczka loan_;
  Credit credit_;
};

//The Main method
int main()
{
  Hipoteka zadluzenie;
  Klient klient1("Brad Pitt");

  bool nadajeSie = zadluzenie.czyNadajeSie(klient1, 1500000);

  cout << "\n" << klient1.Name() << " dostal " << (nadajeSie ? "zezwolone" : "odrzucone") << endl;

  return 0;
}
