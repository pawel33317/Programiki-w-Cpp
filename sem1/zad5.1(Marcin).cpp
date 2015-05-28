#include<stdlib.h>
#include<stdio.h>

struct stack                     // Stos
{
       float * data;             // Dane
       unsigned size;            // Wielko��
       unsigned pointer;         // Wska�nik
};

struct stack * stack_create(unsigned size)
{
       struct stack *s;          // wska�nik na strukture
       if(!(s=(struct stack *)malloc(sizeof(struct stack))))
            return NULL;         // Je�li nie zaalokowa� struktury, zwr�� NULL
       if(!(s->data=(float *)malloc(sizeof(float)*size)))
       {                         // Je�li nie zaalokowa� wska�nika
            free(s);             // Wyczy�� zaalokowan� struktur�
            return NULL;         // Zwr�� NULL
       }
            s->pointer=0;        // Ustaw wska�nik na 0
return s;                        // Zwr�� wska�nik do struktury
};

void stack_delete(struct stack *s)
{
     if(s)                       // Je�li wska�nik na struktur� nie istnieje 
     {
          free(s->data);         // Zwolnij pami�� ze wska�nika
          free(s);               // Zwolnij pami�� ze struktury
     }
}

unsigned stack_push(struct stack *s, float data) 
{                                // Umie�� warto�� pod adresem
   if(s->pointer < s->size)   
   {
         s->data[s->pointer]=data;
         s->pointer++;
   }
return s->pointer;
}

float stack_pop(struct stack *s) // Zdejmij i zwr�� warto�� ze stosu
{
      float value=s->data[s->pointer];
      s->pointer--;
      return value;
}

unsigned stack_size(struct stack *s)
{return s->size;}                // Zwr�c wielko�� stosu

bool stack_isEmpty(struct stack *s)
{                                // Sprawd� czy stos jest pe�ny
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
{                                 // Zwr�� warto�� elementu spod indeksu
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

