#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int ws = 0;
//int * create(){int *tmp; if(tmp =(int*) malloc(sizeof(float))) return tmp;else return 0;}
int push(float*stos,float l){
	float*tmp=(float*)realloc(stos,(ws+1)*sizeof(float));
	if(tmp==NULL) {return 0;}
	else{stos=tmp;*(stos+ws)=l;ws++;return 1;}}
void pop(float*stos){
	if(ws<=0){}//stos pusty
	else{ws--;stos=(float*)realloc(stos,ws*sizeof(float));}}   
int fsize(){return ws;}
int clear(float *stos){free(stos);ws=0; return 1;}
int isEmpty(){if(ws==0)return 1;else return 0;} 
void print(float *stos){int i=0;while(i<ws){printf("element nr %d to: %f\n",i+1,*(stos+i));i++;}}
void getElement(float *stos,int l){printf("element nr %d to: %f\n",l,*(stos+l-1));}
int main()
{	int li;
	float *stos;
	stos =(float*) malloc(sizeof(float));
	if (stos)printf("Utworzono stos\n");else printf("Blad tworzenia stosu\n");
	if (push(stos,1))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(stos,2))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(stos,3))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(stos,4))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(stos,5))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(stos,5.5))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(stos,5.555))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(stos,6))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	if (push(stos,7))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	print(stos);
	pop(stos);printf("Usunieto ostatni element stosu\n");
	print(stos);
	printf("Rozmiar stosu to %d elementow\n",fsize());
	if (push(stos,997))printf("Dodano element do stosu\n");else printf("Stos przepelniony\n");
	print(stos);
	printf("Ktory elemant stosu wczytac od 1 do do %d: ",ws);
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
