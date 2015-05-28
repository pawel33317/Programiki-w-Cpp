#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int ile,**tab;int k,num;
	scanf("%d",&ile);
	tab=(int **)malloc(ile*sizeof(int*));
	if(!tab)exit(1);

	for(k=0;k<ile;k++)
	{
	scanf("%d",&num);
	if(!num)tab[k]=NULL;
	else {tab[k]=(int*)calloc(num,sizeof(int));}
	if(!tab[k])exit(1);
	
	}

	system("PAUSE");	
	return 0;
}
