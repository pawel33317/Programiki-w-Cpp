#include <iostream>

using namespace std;

class Miesiac
   {
        public:
             int numer;
             int rok;
             Miesiac(const Miesiac &miesiac)
             {
                  numer=miesiac.numer;
                  rok=miesiac.rok;
             }
             Miesiac()
             {
             }
   };

class Rok
   {
        public:
             Miesiac *miesiace;
        public:
             Rok() : miesiace(new Miesiac[12]) {}
             Rok(const Rok &rok)
             {
                  //musimy sami zaalokowaæ pamiêæ na pole ''miesiace''
                  miesiace=new Miesiac[12];
                  //oraz przypisaæ temu polu odpowiednie wartoœci
                  for (int i=0; i<12; ++i)
                       miesiace[i]=Miesiac(rok.miesiace[i]);
             }
             virtual ~Rok() {delete[] miesiace;}
   };

int main()
{
    Miesiac* czerwiec1 = new Miesiac();
    czerwiec1->rok = 1991;
    Miesiac* czerwiec2 = new Miesiac(*czerwiec1);

    cout << czerwiec1->rok << " " << czerwiec2->rok << endl << endl ;
    czerwiec2->rok = 2000;
    cout << czerwiec1->rok << " " << czerwiec2->rok << endl << endl ;

    Rok* rok1888 = new Rok();
    rok1888->miesiace->rok = 1888;

    return 0;
}
