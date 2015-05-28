#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int ile,*tab;
	scanf("%d",&ile);
	tab=(int *)malloc(ile*sizeof(int));// ===tab=(int *)calloc(ile, sizeof(int));
	if(!tab)exit(1);
	system("PAUSE");	
	return 0;
}
//malloc zwraca adres je¿eli jest w ramie wolny blok o danym rozmiarze NULL jak nie ma
//calloc zeruje przydzielon¹ pmiêæ
//realloc zmienia obszar przydzielony
//free zwalnia dany obszar
