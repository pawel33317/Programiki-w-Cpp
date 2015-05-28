#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
   set<string> mapa;
   mapa.insert("Lublin");
   mapa.insert("��d�");
   mapa.insert("Warszawa");
   mapa.insert("Krak�w");

   set<string>::iterator result, it;

   // szuka elementu "Warszawa"
   result = mapa.find("Warszawa");
   if( result!=mapa.end() )
      cout << "Znalaz�em! " << *result<< '\n';

   // wy�wietlenie zawarto�ci
   for( it=mapa.begin(); it!=mapa.end(); ++it)
      cout << *it<< '\n';

   return 0;
}
