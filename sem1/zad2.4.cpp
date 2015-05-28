#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
int wybor=0;
char tab[100];
char *wsk=tab;

printf("Na jakie litery chcesz zamienic?\n");
printf("1-male\n");
printf("2-duze\n");
scanf("%d",&wybor);

printf("podaj wyraz\n");
scanf("%s",tab);

switch(wybor)
{
 case 1:
      for(int i=0;i<strlen(tab);i++)
      {
              *(wsk+i)=tolower(*(wsk+i));
      }
      break;
 case 2:
      for(int i=0;i<strlen(tab);i++)
      {
              *(wsk+i)=toupper(*(wsk+i));
      }
      break;
 default:
         return 0;
} 
printf("%s\n",tab);
        
system("pause");
return 0;
}
