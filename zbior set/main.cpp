#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
   set<string> mapa;
   mapa.insert("Lublin");
   mapa.insert("£ódŸ");
   mapa.insert("Warszawa");
   mapa.insert("Kraków");

   set<string>::iterator result, it;

   // szuka elementu "Warszawa"
   result = mapa.find("Warszawa");
   if( result!=mapa.end() )
      cout << "Znalaz³em! " << *result<< '\n';

   // wyœwietlenie zawartoœci
   for( it=mapa.begin(); it!=mapa.end(); ++it)
      cout << *it<< '\n';

   return 0;
}
