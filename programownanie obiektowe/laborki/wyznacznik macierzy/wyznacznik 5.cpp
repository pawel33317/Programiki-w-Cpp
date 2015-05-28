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

double Determinant(double **a,int n)
{
   int i,j,j1,j2;
   double det = 0;
   double **m;

   if (n < 1) { /* Error */

   } else if (n == 1) { /* Shouldn't get used */
      det = a[0][0];
   } else if (n == 2) {
      det = a[0][0] * a[1][1] - a[1][0] * a[0][1];
   } else {
      det = 0;
      for (j1=0;j1<n;j1++) {
         m = (double**)malloc((n-1)*sizeof(double *));
         for (i=0;i<n-1;i++)
            m[i] = (double*)malloc((n-1)*sizeof(double));
         for (i=1;i<n;i++) {
            j2 = 0;
            for (j=0;j<n;j++) {
               if (j == j1)
                  continue;
               m[i-1][j2] = a[i][j];
               j2++;
            }
         }
         det += pow(-1.0,1.0+j1+1.0) * a[0][j1] * Determinant(m,n-1);
         for (i=0;i<n-1;i++)
            free(m[i]);
         free(m);
      }
   }
   return(det);
}

int main ()
{
    int n,liczba,rozm; 
    int **m; 
    
    
     FILE *dane;
     dane=fopen("dane.txt","r");
     while (feof(dane)==0)
      {
            
               fscanf(dane, "%d", &liczba);
               rozm++;
      }
      printf("%d",rozm);
      
 (a->n)=sqrt(rozm);
 a->m = (long **) malloc ((a->n) * sizeof (long *));
 
 for (i = 0; i < a->n; i++)
 {
 a->m[i] = (long *) malloc ((a->n) * sizeof (long *));
 }
 
 for (i = 0; i < a->n; i++)
 for (j = 0; j < a->n; j++)
 fscanf(dane, "%d", &liczba);
 a->m[i][j]=liczba;
}
    
/*    
    double det;
readmatrix (&macierz);
printf ("Macierz A:\n\n");
wyswietl (&macierz);
double Determinant(double **m,int n);
*/
system ("PAUSE");
return 0;
} 
