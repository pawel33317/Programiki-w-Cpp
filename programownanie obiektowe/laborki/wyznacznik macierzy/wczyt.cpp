#include <stdio.h>
#define N 50
int main() 
{
      int j, i=0;
      int liczby[N];
      FILE *plik;
      if  ((plik=fopen("dane.txt", "r"))==NULL)
	printf("Nie moge otorzyc pliku!\n");     
      while (feof(plik)==0)
      {
            
               fscanf(plik, "%d", &liczby[1]);
               i++;
      }
      if  (fclose(plik))
	 printf("Nie moge zamknac pliku!\n");
      printf("%d",i);
      //for(j=0;j<i;j++)
	 //printf("%d\n", liczby[j]);
getchar();
      return 0;
      
}
