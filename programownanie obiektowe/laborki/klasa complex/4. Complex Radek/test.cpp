#include "complex.h"

using namespace std;


int main()
{
	Complex com(3,2.5);
	Complex com0(5,5);
	Complex com1; //test konstruktora
	Complex com2;
	
	com1 = com + com0; //test dodawania
	
	cout << "com1 = " << com1 << endl;
	
	com2 = com - com0; //test odejmowanie
	
	cout << "com2 = " << com2 << endl;
	
	cout << "modul z com1 = " << com1.modul(com1) << endl;
	
	cout << "faza z com2 = " << com2.faza(com2) << endl;
	
	return 0;
}
