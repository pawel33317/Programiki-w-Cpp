// DLA ZMIENNO PRZECINKOWYCH
#include<stdlib.h>
#include<stdio.h>

int main()
{
char tab[10];
int  i=0;

char *wsk=tab;

for(i=0;i<10;i++)
{
                 *(wsk+i)=char(10*rand()/RAND_MAX+50);
}
for(i=0;i<10;i+=2)
{
                 printf("%c\n",*(wsk+i));
}


    
system("pause");
return 0;
}

/*




// DLA ZMIENNO PRZECINKOWYCH
#include<stdlib.h>
#include<stdio.h>

int main()
{
double tab[10];
int    i=0;

double *wsk=tab;

for(i=0;i<10;i++)
{
                 *(wsk+i)=10*(double)rand()/RAND_MAX;
}
for(i=0;i<10;i+=2)
{
                 printf("%f\n",*(wsk+i));
}


    
system("pause");
return 0;
}

*/

/*     DLA CA£KOWITYCH
#include<stdlib.h>
#include<stdio.h>

int main()
{
int tab[10],
    i=0;

int *wsk=tab;

for(i=0;i<10;i++)
{
                 *(wsk+i)=rand()%10+0;
}
for(i=0;i<10;i+=2)
{
                 printf("%d\n",wsk[i]);
}


    
system("pause");
return 0;
}
*/
