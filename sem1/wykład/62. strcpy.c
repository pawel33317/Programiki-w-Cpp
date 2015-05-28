#include <stdio.h>
#include <stdlib.h>

void strcpy(char*cel, const char *src)
{
	while(*cel++=*src++);
}


int main()
{	
	char tab[]="abcdefg";
	char tabb[11];
	strcpy(tabb, tab);
	printf("%s\n",tab);
	printf("%s\n",tabb);
	system("PAUSE");	
	return 0;
}
