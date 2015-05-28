#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
      char zm[10];
      char *wsk = zm;
      int i;
      
      
      srand(time(NULL));
      for(i=0;i<10;i++)
      {               	
      //*(wsk + i)=92+(char)rand()%20;    
      *(wsk + i)=rand()%('z'-'a'+1)+'a';
      }      
      for(i=0;i<10;i=i+2)
      {         	
      printf("element nr: %d = %c\n",i,*(wsk + i));
      }           
                       
                       
                       
       
       
                       
            system("pause");
      }
