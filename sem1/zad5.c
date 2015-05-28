#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct stack      //deklaracja struktury
{
	float *data; 
	unsigned pointer;
	unsigned size;
};

struct stack *stack_create (unsigned size)  //tworzy coœ
{
	struct stack *s;
	
	if(!(s=(struct stack *) malloc (sizeof(struct stack))))
		return NULL;
	
	if(!(s->data=(float *) malloc(sizeof(float)*size)))
	{
		free(s);
		return NULL;
	}
		s->pointer=0;
		return s;
}
unsigned stack_push(struct stack *s, float data)
{
	if(s->pointer<s->size)
	{
		s->data[s->pointer]=data;
		s->pointer++;
		}
}
void stack_delete(struct stack *s)
	{
		if(s)
		{
			free(s->data);
			free(s);
		}
	}



int main()
{
struct stack * s1;
s1 = stack_create(100);

stack_delete(s1);
system("pause");
return 0;
}
