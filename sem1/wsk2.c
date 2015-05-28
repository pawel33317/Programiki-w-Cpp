#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
 double *p;
 double q, tymcz;
 tymcz = 1234.34;
 p=&tymcz;
 q=*p;
 printf("%f",q);
 //return 0;
 system("pause");
}
