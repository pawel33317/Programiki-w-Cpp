#include <stdio.h>
#include <stdlib.h>
#define TRACE(flag) \
	printf(#flag " = %d \n",flag);
int main()
{	
	int zmienna=5;
	TRACE(zmienna);
	system("PAUSE");	
	return 0;
}
//        \ -znak kontynuacji