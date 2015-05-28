#include <stdio.h>
#include <stdlib.h>
//#define JANEK
#define JOLA
//#define ANDRZEJ
int main()
{	

#if defined(JOLA) 
	printf("JOLA\n");
#endif
#if defined(JANEK) 
	printf("JANEK\n");
#endif
#if dev (ANDRZEJ) 
	printf("ANDRZEJ\n");
#endif


	system("PAUSE");	
	return 0;
}
//#if defined === #if dev
//#else
//#elif
//#ifndev === #if !dev