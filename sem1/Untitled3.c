#include<stdlib.h>																//
#include<stdio.h>																//
struct stack      																//deklaracja struktury
{																				//
	float *data;							//wska�nika data
	unsigned pointer;															//pointer typ int
	unsigned size;																//size typ int
} ;																			//
struct stack *stack_create (unsigned size)  									//tworzy stos \\\\\pobiera wielko�� stosu
{				printf("TWORZENIE STOSU...\n");	
				printf("pobrano size=%d\n",size);								//
	struct stack *s;printf("zadeklarowano *s=stack\n");							//deklaracja, �e wska�nik s to typ stack
	if(!(		s=(struct stack *)		malloc(	sizeof(struct stack)	)))    	//pr�buje przydzieli� do s odpowiedni� ilo�� pami�ci
		{return NULL;printf("b��d przydzia�u pami�ci dla struktury *s\n");}		//je�eli si� nie uda�o	
		else{printf("przydzielono pami�� dla *s\n");}			
	if(!(		s->data=(float *)		malloc(sizeof(float)*size)		))		//przydziela pami�� do danych z struktury
	{			printf("b��d przydzia�u pami�ci dla struktury *s->DATA\n");		//
		free(s);		printf("czyszczenie struktury s");						//je�eli nie posz�o wyczy�� ca�e s
		return NULL;															//je�eli nie posz�o
	}	
	else{printf("przydzielono pami�� dla struktury *s->DATA\n");}
																				//
		s->pointer=0;	printf("s->pointer=0;\n");											//ustaw wska�nik s na 0
		
		printf("TWORZENIE STOSU KONIEC\n");	
		return s;	
																	//zwr�� s		
}																				//
unsigned stack_push(struct stack *s, float data)
{																				//
	if(s->pointer<s->size)					
	{																			//
		s->data[s->pointer]=data;
		s->pointer++;						
		}																		//
}																				//
void stack_delete(struct stack *s)												//usuwanie zmiennej \\\\\pobiera jej adres
	{																			//	
		if(s)																	//czy istnieje zmienna
		{																		//
			free(s->data);printf("czyszczenie struktury s->data\n");				//czy�ci dane ze zmiennej
			free(s);	printf("czyszczenie struktury s\n");						//czy�ci zmienn�
		}																		//	
	}																			//
int main()																		//MAIN
{																				//
struct stack * s1; 																//deklaracja, �e s1 to typ stack  
s1 = stack_create(1);															//tworzy stos
	
//z->dane=111;
//s1->data = 11;
//printf("aaa");  
stack_delete(s1); 																//usuni�cie s1 \\\\\\podaje zmienn�
system("pause");  																//przytrzymanie programu
return 0;																		//zwr�cenie 0
}
 
