#include <iostream>
#include<stdlib.h>
#include "matrix.h"


int main ()
{
CMatrix m1(3,3);
CMatrix m2(3,3);
CMatrix m3(3,3);
m1=m2=m3;

 //FILE *dane;
  //   dane=fopen("dane.txt","r");

//CMatrix zpliku(&dane);

cout <<m3<< endl;

CMatrix ma(2,5,1.0);
cout << ma<< endl;

CMatrix ma2(5,3,0.0,6.3);
cout << ma2<< endl;

CMatrix m4=ma*ma2;
cout<< m4<< endl;
getchar();
/*
fstream f1;
		f1.open("matrix.dat", fstream::in);
		CMatrix B(f1);				//Read the matrix data from file matrix.dat
		f1.close();

cout <<B<< endl;

B(1,1)=333;
cout <<B(1,1)<< endl;	
system ("PAUSE");
*/
}
