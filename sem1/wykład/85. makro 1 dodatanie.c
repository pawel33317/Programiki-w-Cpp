#include <stdio.h>
#include <stdlib.h>
#define Kwadrat(x) x*x
#define Kwadratok(x) ((x)*(x))
int main(int arg, char*argv[])
{	
	int a=5;
	printf("%d \n",Kwadrat(a+1)); //�le bo a+1*a+1 // powinno by� 36
	printf("%d \n",Kwadratok(a+1));//ok
	system("PAUSE");	
	return 0;
}