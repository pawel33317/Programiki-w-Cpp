#include <stdio.h>
#include <stdlib.h>
#define TRACE(flag) \
printf(" flag = %d \n",flag);
int main()
{	
	int a=5;
	TRACE(a);
	system("PAUSE");	
	return 0;
}
//        \ -znak kontynuacji