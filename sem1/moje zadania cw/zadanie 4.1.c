#include<stdio.h>
#include<stdlib.h>
#define M 9
#define N 9
int pierwsza(int n)
{
	int p=1,i=1;
	for (i; i<n; i++)
	{
		if (n%i == 0)
		{
			p++;
			if (p>2)
			return 0;
		}    
	} 
	return 1;  
}
int main()
{
	int i=0,j=0,tab[M][N],l=2,(*wsk)[M]=tab;
	while(i<M)
	{j=0;
			while(j<N)
			{
				while(!pierwsza(l))l++;
				tab[i][j]=l;
				l++;
				j++;
			}i++;
	}


	i=0;
	while(i<M)
	{j=0;
			while(j<N)
			{
				//printf("%6d  ",*(*(tab+i)+j));
				printf("%6d  ",*(*(wsk+i)+j));
				j++;
			}i++;printf("\n");
	}
	printf("\n");printf("\n");printf("\n");

	i=0;
	while(i<M)
	{j=0;
			while(j<N)
			{
				if(((i+1)%3==0)&&((j+1)%3==0))printf("%6d  ",tab[i][j]);
				j++;
			}i++;printf("\n");
	}

system("pause");
return 0;
}