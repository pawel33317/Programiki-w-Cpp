#include<stdlib.h>
#include<stdio.h>

int main()
{
double *p;
double q, tymcz;
tymcz = 1234.34;
p=&tymcz;
q=*p;
printf("%f",q);
system("pause");
return 0;
}
