#include <stdio.h>
#include <stdlib.h>

int main(int arg, char*argv[])
{	
	int a = 5 , b=9;

	printf("a=%d   b=%d   \npo potrojnej alternacji bez tempa zamiana\na=b^a;b=b^a;a=b^a;\n",a,b);

	a=b^a;b=b^a;a=b^a;
	
	printf("a=%d   b=%d   \n",a,b);
	system("PAUSE");	
	return 0;
}
