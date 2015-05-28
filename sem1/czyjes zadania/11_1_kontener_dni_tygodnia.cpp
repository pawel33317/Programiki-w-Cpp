#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

int main()
{
    map <char*,int> tydzien;
    map <char*,int> :: iterator i;
    tydzien["poniedzialek"]=1;
    tydzien["wtorek"]=2;
    tydzien["sroda"]=3;
    tydzien["czwartek"]=4;
    tydzien["piatek"]=5;
    tydzien["sobota"]=6;
    tydzien["niedziela"]=7;
    for(i=tydzien.begin();i!=tydzien.end();i++)
        printf("%-20s %d\n",i->first,i->second);
    system("PAUSE");
    return 0;
}
