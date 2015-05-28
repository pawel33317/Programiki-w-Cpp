#include <stdio.h>
#include <stdlib.h>

typedef struct
{
 int n; // Wymiar macierzy
 long **m; // Tablica tablic (wierszy)
 } matrix; // Definicja nowego typu matrix (struktury)
   
 // Funkcja odczytujaca dwie macierze kwadratowe a i b.
 // Wczesniej odczytywana jest informacja o wymiarze macierzy
 // i alokowana jest stosowna pamiec.
 void readmatrix (matrix * a)
 {
 int i, j;
 scanf ("%d", &(a->n));//rozmiar tablicy 
 // Alokacja pamieci na a;
 a->m = (long **) malloc ((a->n) * sizeof (long *));
 for (i = 0; i < a->n; i++)
 {
 a->m[i] = (long *) malloc ((a->n) * sizeof (long *));
 }
 
 for (i = 0; i < a->n; i++)
 for (j = 0; j < a->n; j++)
 scanf ("%d", &(a->m[i][j])); // Odczytywanie wspolrzednych a
}
 
void wyswietl (matrix * m)
{
int i, j;
for (i = 0; i < m->n; i++)
{
for (j = 0; j < m->n; j++)
printf ("%d  ", m->m[i][j]);
printf ("\n");
}
printf ("\n\n");
}

matrix a;

int main (void)
{
readmatrix (&a);
printf ("Macierz A:\n\n");
wyswietl (&a);


system ("PAUSE");
return 0;
} 
