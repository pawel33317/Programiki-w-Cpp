#include<iostream>
#include"exampleClas.hpp"
#include"class2.hpp"
using namespace std;
int main(){
	cout << "START---------------" << endl << endl << endl;
	exampleClas klasa1;
	exampleClas* klasa2 = new exampleClas();
	class2 klasa3;


	klasa1.setVal(3.14);
	klasa2->setVal(2.37);
	klasa3.setVal(11);


	cout << klasa1.getVal() << endl;
	cout << klasa2->getVal() << endl;
	cout << klasa3.getVal() << endl;

	cout << endl << endl << "FINISH--------------" << endl << endl;
	return 0;
}
