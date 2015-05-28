#include <stdio.h>
#include <stdlib.h>

int strlen(const char *s)
{
	int n;
	for(n=0;*s;s++)n++;
		return n;
}

int main()
{	
	printf("Rozmiar \"ABCDEFGHIJK\" to: %d\n",strlen("ABCDEFGHIJK"));
	system("PAUSE");	
	return 0;
}
