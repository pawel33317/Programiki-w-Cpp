#include<stdio.h>
#include<stdlib.h>
int main(void)
{
int i,od;
int *wsk;
for(i=0;i<20;i++)

i=0;
FILE *f;
f=fopen("dane.txt","r");
if(f!=NULL)printf("Otwarlem plik\n\n");
while(feof(f)==0){
fscanf(f,"%d",wsk);
i++;
}
fclose(f);
printf("%d\n",i);
system("pause");
return 0;   

} 
