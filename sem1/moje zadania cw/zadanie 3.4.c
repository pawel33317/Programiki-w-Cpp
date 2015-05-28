#include<stdio.h>
#include<stdlib.h>
void ypoc(char zrodlo[20],char cel[20])
{
	char zn;FILE *zr; FILE *ce;int znak=0;
	zr = fopen(zrodlo, "r");

	ce = fopen(cel, "w");
	do
		znak++;
    while (getc(zr) != EOF);

	while(znak>=0){
		fseek(zr, znak, 0);
		zn=getc(zr);
		if(zn=='\n')znak--;
		fprintf (ce, "%c", zn);
		printf("%c", zn);
		znak--;
	}
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
	printf("\n");
system("pause");
return 0;
}