#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
void sum(char*msg,...)
{
	int total=0;
	va_list ap;
	int arg;
	va_start(ap,msg);
	while((arg=va_arg(ap,int))!=0)total+=arg;
	va_end(ap);
	printf(msg,total);
}
int main(int arg, char*argv[])
{	
	sum("the total = %d \n",1,2,3,4,6,0);
	system("PAUSE");	
	return 0;
}
