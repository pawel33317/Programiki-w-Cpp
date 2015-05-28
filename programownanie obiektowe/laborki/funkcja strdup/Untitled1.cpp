#include<stdio.h>
#include<stdlib.h>

char copytxt(char* tekst)
{
         int pomoc;
         char* temp=(char*)malloc(100);
         if(tekst==0)
         {printf("brak tekstu do skopiowania");}
         else
         {
             while(*(tekst+pomoc)!=0)
             {
              *(temp+pomoc)=*(tekst+pomoc);
              pomoc++;
             }
      
         }
return *temp;
} 

int main()
{
   int i;
   char* tekst=(char*)malloc(100);
   char* temp=(char*)malloc(100);

   printf("podaj tekst\n");
   scanf("%s",tekst);
   
 
*temp=copytxt(tekst);

printf("%s",temp);

free(tekst);
free(temp);

getchar();


}

char * strDup (char const *str)
{
if (str == NULL) return NULL;
size_t len = strlen(str) + 1;
char* copy = new char[len];
if (copy != NULL)
{
memcpy(copy, str, len); }
return copy;
}


size_t strlen(const char* string)
{
size_t len = 0;
while (*string++) len++;
return len;
}
