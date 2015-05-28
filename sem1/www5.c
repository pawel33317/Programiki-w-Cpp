#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>


int main()
{
char tab[]="al0a ma kota";
char *wsk = &tab;
int i=0;
while(*(wsk + i)!=0)
{
       i++;
       }  
       printf("dlugosc = %d\n",i);
        
        
        
system("pause");
return 0;
}
