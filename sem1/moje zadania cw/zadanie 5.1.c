#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 20
int ws = 0;
int push(float *tab, float l)
{
	if(ws<N)
		{
			*(tab+ws)=l;
			ws++;
			return 1;
		}
	else return 0;
}
void pop()
{
	if(ws>0)ws--;
}
int fsize(){return ws;}
int clear(){ws=0; return 1;}
int isEmpty(){ if(ws==0) return 1; else return 0;}
void print(float *tab){int i;for(i=0;i<ws;i++)printf("element nr %d to %f\n",i,*(tab+i));}
void getElement(float *tab, int n){printf("element nr %d to %f",n,*(tab+n));}
int main()
{	
	float tab[N];int li;

	if (push(tab,5))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(tab,3))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(tab,2))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(tab,5))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(tab,3))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(tab,2))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	print(tab);
	pop(tab);printf("Usunieto ostatni element stosu\n");
	if (push(tab,5))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	print(tab);
	printf("Ktory elemant stosu wczytac od 1 do do %d",ws);
	scanf("%d",&li);
	getElement(tab,li);
	if(clear())printf("Stos wyczyszczony\n");
	if(isEmpty())printf("Stos pusty\n");





	system("PAUSE");	
	system("cls");
	printf("Created by Pawel Czubak");
	Sleep ( 2000 ) ;
	return 0;
}
