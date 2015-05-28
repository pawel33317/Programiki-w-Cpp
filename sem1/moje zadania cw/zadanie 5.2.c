#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int size;
int ws = 0;
int create(){float *tmp; if(tmp = malloc(size*sizeof(float))) return tmp;else return 0;}
int push(float*stos,float l){if(ws>=size)return 0;else{*(stos+ws)=l;ws++;return 1;}}
void pop(float*stos){ws--;if(ws<0)ws=0;*(stos+ws)=0;}
int fsize(){return ws;}
int clear(float *stos){free(stos);ws=0; return 1;}
int isEmpty(){if(ws==0)return 1;else return 0;} 
void print(float *stos){int i=0;while(i<ws){printf("element nr %d to: %f\n",i+1,*(stos+i));i++;}}
void getElement(float *stos,int l){printf("element nr %d to: %f\n",l,*(stos+l-1));}
int main()
{	int li;
	float *stos;
	printf("Podaj wielkosc stosu: ");
	scanf("%d",&size);
	stos = create();
	if (stos)printf("Utworzono stos\n");else printf("Blad tworzenia stosu\n");
	if (push(stos,5))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(stos,3))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(stos,2))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(stos,5))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(stos,3))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(stos,2))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	pop(stos);printf("Usunieto ostatni element stosu\n");
	if (push(stos,5))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	print(stos);
	printf("Ktory elemant stosu wczytac od 1 do do %d",ws);
	scanf("%d",&li);
	getElement(stos,li);
	if(clear(stos))printf("Zwolniono pamiec\n");
	if(isEmpty())printf("Stos pusty\n");
  system("PAUSE");	
  system("cls");
  printf("Created by Pawel Czubak");
  Sleep ( 2000 ) ;
  return 0;
}
