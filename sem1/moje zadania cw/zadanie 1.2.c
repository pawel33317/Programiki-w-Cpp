#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define M 10
int sprawdz(char iitab[10])
{
	int z=0,j=0;
	while(iitab[j]!=NULL)
	{
		if (islower(iitab[j]))z++;
		j++;
	}
	return z;
}
sortuj(char tab[M][10])
{ int d=0,f=0; char tmp[10];
	while(d<M)
	{
		while(f<M-1)
		{	
			if(sprawdz(tab[f])>sprawdz(tab[f+1]))
			{
				strcpy(tmp,tab[f]);
				strcpy(tab[f],tab[f+1]);
				strcpy(tab[f+1],tmp);
			}
			f++;
		}
		f=0;
		d++;
	}
}
wypisz(char tab[M][10])
{
	int i=0;
	while (i<M)
	{
		printf("\n %s ",tab[i]);		
		i++;
	}
}

main()
{	
	char tab[M][10];int i=0;
	while (i<M)
	{
		printf("\nPodaj wyraz:");
		scanf("%s",&tab[i]);
		i++;
	}
	sortuj(tab);
	wypisz(tab);
	system("pause");
	return 0;
}