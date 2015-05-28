#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define M 10
#define N 10
main()
{	
	int macierz[M][N],i=0,j=0,x,y;int iloczyn,tx,ty;int nowyiloczyn=1;
	printf("Macierz %dx%d\n",M,N);
//GENEROWANIE LICZB DO MACIERZY
	srand(time(0));
	while (i<M)
	{		while (j<N)
			{
                macierz[i][j]=rand()%4+1;
				printf("%5d",macierz[i][j]);
				j++;
			}
            j=0;i++;printf("\n");
    }
//WCZYTYWANIE POZYCJI MACIERZY
	do{
		printf("Podaj po spacji 2 liczby (nr elementu macierzy) <=%d, <=%d\n",M,N);
		scanf("%d %d",&x,&y);
	}while(x>M && y>N);
	x--;y--;
	printf("Wybrano pozycje x=%d y=%d wartosc:%d\n",x+1,y+1,macierz[x][y]);

//INNE OBLICZANIE ILOCZYNU
	i=0;j=0;
	while (i<M)
	{		while (j<N)
			{
				if((i+j==x+y)||(i-j==x-y)){nowyiloczyn=nowyiloczyn*macierz[i][j];printf("  Ma[%d][%d]",i+1,j+1);}
				//if(){nowyiloczyn=nowyiloczyn*macierz[i][j];printf("  Mb[%d][%d]",i,j);}
				j++;
			}
            j=0;i++;printf("\n");
    }
	printf("INNE WYLICZENIE iloczyn wynosi: %d\n",nowyiloczyn);
//OBLICZANIE ILOCZYNU PRZEK¥TNYCH
	iloczyn=macierz[x][y];
	tx=x-1;ty=y-1;
    while((tx>=0) && (ty>=0)){printf("a%d  ",macierz[tx][ty]); iloczyn=iloczyn*macierz[tx][ty];tx--;ty--;} //lewo góra
    tx=x-1;ty=y+1;
	while((tx>=0) && (ty<=N-1)){printf("b%d  ",macierz[tx][ty]); iloczyn=iloczyn*macierz[tx][ty];tx--;ty++;} //lewo dó³
	tx=x+1;ty=y+1;
	while((tx<=M-1) && (ty<=N-1)){printf("c%d  ",macierz[tx][ty]); iloczyn=iloczyn*macierz[tx][ty];tx++;ty++;} //prawo dó³
	tx=x+1;ty=y-1;
	while((tx<=M-1) && (ty>=0)){printf("d%d  ",macierz[tx][ty]); iloczyn=iloczyn*macierz[tx][ty];tx++;ty--;} //prawo góra

	printf("Iloczyn wynosi: %d\n",iloczyn);

	system("pause");
	return 0;
}