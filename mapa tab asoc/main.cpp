#include<iostream>
#include<map>
using namespace std;

int main()
{
   map<int, string> tydzien;
   tydzien[1] = "niedziela";
   tydzien[2] = "poniedzialek";
   tydzien[3] = "wtorek";
   tydzien[4] = "sroda";
   tydzien[5] = "czwartek";
   tydzien[6] = "piatek";
   tydzien[7] = "sobota";

   cout << "trzeci dzien tygodnia:  " << tydzien[3] << '\n';

   map<int, string>::iterator cur;

   // zwrocenie elementu o kluczu 3
   cur = tydzien.find(3);

   // elementy o kluczach wiêkszych i mniejszych
   map<int, string>::iterator prev = cur;
   map<int, string>::iterator next = cur;
   ++next;
   --prev;

   cout << "Wczesniejszy:  " << prev->second << '\n';
   cout << "Nastepny:  " << next->second << '\n';
}
