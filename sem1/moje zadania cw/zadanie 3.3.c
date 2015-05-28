#include<stdio.h>
#include<stdlib.h>
void ypoc(char zrodlo[20],char cel[20])
{
	char zn;FILE *zr; FILE *ce;
	//printf("%s",cel);
	
	zr = fopen(zrodlo, "r");
	ce = fopen(cel, "w");
    while(!feof(zr)){zn=getc(zr);fprintf (ce, "%c", zn);printf("%c", zn);}
	fclose(zr);
	fclose(ce);
}

int main()
{
	char z[20];char c[20];
	printf("Podaj sciezke do pliku zrodlowego: ");
	scanf("%s",z);
	printf("Podaj sciezke do pliku docelowego: ");
	scanf("%s",c);
	ypoc(z,c);
system("pause");
return 0;
}