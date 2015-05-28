#include <stdio.h>
#include <stdlib.h>

int lenghttxt(const char* txt)
{
int lenght = 0;
while (*txt++) lenght++;
return lenght;
}

char *copy(char *temp, const char *txt)
{
char* p=temp;
while (*temp++ = *txt++);
return p;
}


char * copytxt(char *txt)
{
     int lenght;
     lenght=lenghttxt(txt);
     char *temp = (char*)malloc(lenght + 1);
 
     if (temp == (char*)0)
     return (char*)0;
 
     copy(temp, txt);
     return temp;
}


int main()
{
   int i;
   char* txt=(char*)malloc(100);
   char* temp=(char*)malloc(100);
   printf("podaj tekst\ntekst oryginalny:");
   scanf("%s",txt);
   temp=copytxt(txt);
   
   printf("kopia :%s\n",temp);
   free(txt);
   free(temp);
   printf("tekst zostal skopiowany\n");
   
   
   getchar();
   getchar();
   
   return 0;
}

