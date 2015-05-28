#include <stdio.h>
#include <stdlib.h>

int main()
{	
	char *tab="aaa";char t1[81]="ABCD";
	char *ttab[10]={"jola","ala","kutas"};
	printf("%c\n",*tab);//wyœwietli pierwszy znak a

	printf("%s\n",*ttab);//jola
	printf("%s\n",t1);//abcd
	system("PAUSE");	
	return 0;
}
