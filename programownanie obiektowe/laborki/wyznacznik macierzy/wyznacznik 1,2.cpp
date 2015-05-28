#include <stdio.h>
#include <stdlib.h>
#include<math.h>
 
void wyswietl (int **m,int rozmiar)
{
int i, j;
for (i = 0; i < rozmiar; i++)
{
for (j = 0; j < rozmiar; j++)
printf ("%d  ", m[i][j]);
printf ("\n");
}
printf ("\n\n");
}

double Determinant(int **a,int n)
{
   int i,j,j1,j2;
   int det = 0;
   int **m;

   if (n < 1) { 

   } else if (n == 1) { 
      det = a[0][0];
   } else if (n == 2) {
      det = a[0][0] * a[1][1] - a[1][0] * a[0][1];
   } else {
      det = 0;
      for (j1=0;j1<n;j1++) {
         m = (int**)malloc((n-1)*sizeof(int *));
         for (i=0;i<n-1;i++)
            m[i] = (int*)malloc((n-1)*sizeof(int));
         for (i=1;i<n;i++) {
            j2 = 0;
            for (j=0;j<n;j++) {
               if (j == j1)
                  continue;
               m[i-1][j2] = a[i][j];
               j2++;
            }
         }
         det += pow(-1,1+j1+1) * a[0][j1] * Determinant(m,n-1);
         for (i=0;i<n-1;i++)
            free(m[i]);
         free(m);
      }
   }
   return(det);
}

int main ()
{
    int n,liczba,rozm,i,j; 
    int **macierz; 
    
     rozm=0;
     FILE *dane;
     dane=fopen("dane.txt","r");
     
 fscanf(dane,"%d",&rozm);
 n=sqrt(rozm);
 printf("wymiar macierzy: %d\n",n);
 macierz = (int **) malloc ((n) * sizeof (int *));
 for (i = 0; i < n; i++)
 {
 macierz[i] = (int *) malloc ((n) * sizeof (int *));
 }
 
 for (i = 0; i < n; i++)
 for (j = 0; j < n; j++)
 {fscanf(dane,"%d",&macierz[i][j]);}
 
  int det;
  printf ("Macierz A:\n\n");
  wyswietl (macierz,n);
det=Determinant(macierz,n);
printf("wyzancznik macierzy wynosi %d\n",det);

 for (i=0;i<n;i++)
 free(macierz[i]);
 free(macierz);


system ("PAUSE");
return 0;
} 
