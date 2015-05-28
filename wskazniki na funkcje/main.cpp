#include <iostream>

using namespace std;

void Funkcja()
{
    cout << "Zostalam wywolana! fun1" << endl;
}
float Funkcja2(int)
{
    cout << "Zostalam wywolana! fun2" << endl;
    return 1.1;
}


int main()
{
 void (*pfnWskaznik)();
 pfnWskaznik = &Funkcja;
 (*pfnWskaznik)();
 pfnWskaznik();

 float (*pfnWskaznik2)(int);
 pfnWskaznik2 = &Funkcja2;
 (*pfnWskaznik2)(3);
 pfnWskaznik2(3);
}

