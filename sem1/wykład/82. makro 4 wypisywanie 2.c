#include <stdio.h>
#include <stdlib.h>
#define TRACE(name,flag) \
printf("%s = %d \n",name,flag);
int main()
{	
	int a=5;
	TRACE("aaa",a);
	system("PAUSE");	
	return 0;
}
//        \ -znak kontynuacji