#include<stdio.h>
#include<stdlib.h>
int main()
{   
    char s[20];FILE *f;
	printf("Podaj sciezke do pliku: ");				//puts("Podaj sciezke dostepu:");
	scanf("%s",s);									//gets(tab);
	f=fopen(s,"r");
    if(		(f=fopen(s,"r"))	==NULL)printf("nie ma takiego pliku");
    else{
    char zn;
    while(!feof(f)){zn=getc(f);printf("%c", zn);}
													 /* 
													  char tr[20];
													  fgets(tr,20,f);
													  printf("%s\n",tr);
 
														char zn;   
														do
														{	zn=getc(f);
															printf("%c", zn);
														}while(zn!=EOF);
													*/
	fclose (f);
    }
    system("pause");
    return 0;
}
 
 
 
 
 
 