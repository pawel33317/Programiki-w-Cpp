#include <iostream>
#include "matrix.h"

void fun();

int main ()
{

fun();

try
	{
		cout << endl;
	  	CMatrix A1(2,5,1.0);			//Create matrix A1 = [	1.0  0.0  0.0  0.0  0.0
							//			0.0  1.0  0.0  0.0  0.0  ]
	
		cout << A1 << endl;
		
		CMatrix A2(5,3,0.0,6.3);		//Create matrix A1 = [	0.0  6.3  6.3 
							//			6.3  0.0  6.3 
							//			6.3  6.3  0.0
							//			6.3  6.3  6.3
							//			6.3  6.3  6.3  ]
		
		cout << A2 << endl;
		
		CMatrix S = A1 * A2;			//Multiply A1 by A2
		cout << S << endl;
	
		fstream f1;
		f1.open("matrix.dat", fstream::in);
		CMatrix B(f1);				//Read the matrix data from file matrix.dat
		f1.close();				//First two values in this file specify the matrix dimensions
		cout << B << endl;
		
		S = B;						//Assign B to S
		S(0,9) = 1.4;					//Modify S
				//Verify B
	}
	catch(IndexOutOfRange&)
	{
		cout << "Index Out of Range" << endl;
	}

	catch(WrongDim&)
	{
		cout << "Wrong Matrix Dimensions" << endl;
	}
	/*catch(bad_alloc &ba)
	{
		cout << "Out of Memory" << endl;
	}*/
}
void fun()
{
CMatrix m11(4,4,1.0);
CMatrix m1,m2,m3,m4;

m1=m2=m3=m4=m11;

cout << m11<<endl;
m2+=m3;
cout << m2<<endl;
m1=m2-m3;
cout<<m1<<endl;
cout << m11<<endl;
m4(1,1)=6.0;
cout<<m4<<endl;
cout << m11<<endl;
cout<<"======================================="<<endl;
}


