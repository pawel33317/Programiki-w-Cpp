#include <stdio.h>
float oblicz(FILE *plik)
{
	float size;unsigned int znak = 0;
    do
		znak++;
    while (getc(plik) != EOF);
    size = (float)znak / 1024.0;
	return size;
}

int main()
{
   int i;
   FILE * fin = fopen("c:/a.txt", "r");
   printf("c:/a.txt -> %2.2f KiB\n", oblicz(fin));
   fclose(fin);
system("pause");
return 0;
}