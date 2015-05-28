#include<stdlib.h>
#include<stdio.h>

struct stack                     // Stos
{
       float * data;             // Dane
       unsigned size;            // Wielkoœæ
       unsigned pointer;         // WskaŸnik
};

struct stack * stack_create(unsigned size)
{
       struct stack *s;          // wskaŸnik na strukture
       if(!(s=(struct stack *)malloc(sizeof(struct stack))))
            return NULL;         // Jeœli nie zaalokowa³ struktury, zwróæ NULL
       if(!(s->data=(float *)malloc(sizeof(float)*size)))
       {                         // Jeœli nie zaalokowa³ wskaŸnika
            free(s);             // Wyczyœæ zaalokowan¹ strukturê
            return NULL;         // Zwróæ NULL
       }
            s->pointer=0;        // Ustaw wskaŸnik na 0
return s;                        // Zwróæ wskaŸnik do struktury
};

void stack_delete(struct stack *s)
{
     if(s)                       // Jeœli wskaŸnik na strukturê nie istnieje 
     {
          free(s->data);         // Zwolnij pamiêæ ze wskaŸnika
          free(s);               // Zwolnij pamiêæ ze struktury
     }
}

unsigned stack_push(struct stack *s, float data) 
{                                // Umieœæ wartoœæ pod adresem
   if(s->pointer < s->size)   
   {
         s->data[s->pointer]=data;
         s->pointer++;
   }
return s->pointer;
}

float stack_pop(struct stack *s) // Zdejmij i zwróæ wartoœæ ze stosu
{
      float value=s->data[s->pointer];
      s->pointer--;
      return value;
}

unsigned stack_size(struct stack *s)
{return s->size;}                // Zwróc wielkoœæ stosu

bool stack_isEmpty(struct stack *s)
{                                // SprawdŸ czy stos jest pe³ny
     if(s->pointer)
        return true;
     else
         return false;
}

void stack_print(struct stack *s) // Wypisz wszyskie elementy stosu
{
int i;
     for(i=0;i<s->pointer;i++)
     {
         printf("%f   ",s->data[i]);
     }
}

float stack_getElement(struct stack *s,int index)
{                                 // Zwróæ wartoœæ elementu spod indeksu
      return s->data[index];
}


int main()
{
struct stack * s1;
s1=stack_create(100);


stack_delete(s1);
  
system("pause");
return 0;
}

