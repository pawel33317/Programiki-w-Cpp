#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
      double zm[10];
      double *wsk = zm;
      int i;
      
      
      srand(time(NULL));
      for(i=0;i<10;i++)
      {               	
      *(wsk + i)=10*(double)rand()/RAND_MAX;    
      }      
      for(i=0;i<10;i=i+2)
      {         	
      printf("element nr: %d = %f\n",i,*(wsk + i));
      }           
                       
                       
                       
       
       
                       
            system("pause");
      }
