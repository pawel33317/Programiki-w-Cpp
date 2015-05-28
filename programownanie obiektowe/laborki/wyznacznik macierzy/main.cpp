int main()
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
int i,od;
int tab[20];
for(i=0;i<20;i++)
tab[i]=0;
i=0;
FILE *f;
f=fopen("dane.txt","r");
if(f!=NULL)printf("Otwarlem plik\n\n");
while((f+i)!=EOF){
i++;
}
fclose(f);
printf("%d\n",i);
system("pause");
return 0;   

} 
{
    


