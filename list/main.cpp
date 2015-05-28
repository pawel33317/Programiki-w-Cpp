#include <list>
#include <iostream>
#include <cstddef>

using namespace std;

template <typename  __Typ>
class myList : public list<__Typ>{
    public:
    __Typ& operator[](unsigned uIndeks) {
        unsigned tmp = 0;
        list<__Typ>::iterator iter;
        for(iter=this->begin(); iter != this->end(); iter++)
        {
            if (tmp == uIndeks)
                return *iter;
                tmp++;
        }
         return *iter;
     }
};


int main()
{
   list<int> lista;
   int liczba;

myList<int> a;
   cout << "Podaj kolejne elementy listy, podaj zero aby zakonczyc:\n";
   while(cin >> liczba && liczba != 0){
    lista.push_back(liczba);
    a.push_back(liczba);
   }

cout << "====" << endl << a[2] << " -- " << a[1] << endl << "====" << endl;
   size_t rozmiar = lista.size();

   liczba = 0;
   for( list<int>::iterator iter=lista.begin(); iter != lista.end(); iter++ )
      liczba += *iter;

   cout << "Srednia liczb wystepujacych w liscie wynosi " << static_cast<double>(liczba) / static_cast<double>(lista.size()) << '\n';

   // usuniecie liczb ujemnych
   for( list<int>::iterator iter=lista.begin(); iter != lista.end(); )
      if (*iter < 0)
         iter=lista.erase(iter);
      else
         iter++;


   liczba = 0;
   for( list<int>::iterator iter=lista.begin(); iter != lista.end(); ++iter )
      liczba += *iter;

   cout << "Srednia dodatnich liczb wynosi " << static_cast<double>(liczba) / static_cast<double>(lista.size()) << '\n';

   return 0;
}
