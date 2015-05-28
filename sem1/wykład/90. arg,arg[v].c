#include <stdio.h>
#include <stdlib.h>
int main(int arg, char*argv[])
{	
	int i=0;
	for(i=0;i<=arg;i++)printf("Argv[%d] = %s\n",i,argv[i]);
	system("PAUSE");	
	return 0;
}
