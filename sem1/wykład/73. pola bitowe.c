#include <stdio.h>
#include <stdlib.h>
struct mystruct{
	int i:2;			//-2 -1 0 1
	unsigned j:5;		//0-31
	int :4;				//nieu¿ywane 4 bity
	unsigned short:1;	//nie u¿ywany bit
	int k:1;			//-1 0 tylko bit znaku
	unsigned m:4;		//0-15
}a,b,c,screen[25][60];
int main()
{	


	system("PAUSE");	
	return 0;
}
