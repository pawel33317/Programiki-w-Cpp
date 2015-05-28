#include<stdlib.h>																//
#include<stdio.h>																//
struct stack      																//deklaracja struktury
{																				//
	float *data;							//wska¿nika data
	unsigned pointer;															//pointer typ int
	unsigned size;																//size typ int
} ;																			//
struct stack *stack_create (unsigned size)  									//tworzy stos \\\\\pobiera wielkoœæ stosu
{				printf("TWORZENIE STOSU...\n");	
				printf("pobrano size=%d\n",size);								//
	struct stack *s;printf("zadeklarowano *s=stack\n");							//deklaracja, ¿e wskaŸnik s to typ stack
	if(!(		s=(struct stack *)		malloc(	sizeof(struct stack)	)))    	//próbuje przydzieliæ do s odpowiedni¹ iloœæ pamiêci
		{return NULL;printf("b³¹d przydzia³u pamiêci dla struktury *s\n");}		//je¿eli siê nie uda³o	
		else{printf("przydzielono pamiêæ dla *s\n");}			
	if(!(		s->data=(float *)		malloc(sizeof(float)*size)		))		//przydziela pamiêæ do danych z struktury
	{			printf("b³¹d przydzia³u pamiêci dla struktury *s->DATA\n");		//
		free(s);		printf("czyszczenie struktury s");						//je¿eli nie posz³o wyczyœæ ca³e s
		return NULL;															//je¿eli nie posz³o
	}	
	else{printf("przydzielono pamiêæ dla struktury *s->DATA\n");}
																				//
		s->pointer=0;	printf("s->pointer=0;\n");											//ustaw wskaŸnik s na 0
		
		printf("TWORZENIE STOSU KONIEC\n");	
		return s;	
																	//zwróæ s		
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
			free(s->data);printf("czyszczenie struktury s->data\n");				//czyœci dane ze zmiennej
			free(s);	printf("czyszczenie struktury s\n");						//czyœci zmienn¹
		}																		//	
	}																			//
int main()																		//MAIN
{																				//
struct stack * s1; 																//deklaracja, ¿e s1 to typ stack  
s1 = stack_create(1);															//tworzy stos
	
//z->dane=111;
//s1->data = 11;
//printf("aaa");  
stack_delete(s1); 																//usuniêcie s1 \\\\\\podaje zmienn¹
system("pause");  																//przytrzymanie programu
return 0;																		//zwrócenie 0
}
 
