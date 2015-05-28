#include <stdlib.h>
#include <stdio.h>
#include <time.h>
main()
{
      int m=9, n=9; 
      int a[m+1][n+1]; 
      int i=0,j=0; 
      int iloczyn; 
      int l1,l2,l1a,l2a;
 
	srand(time( NULL ) );
	while (i<=m)
	{
          while (j<=n)
          {
                a[i][j]=rand() % 10+1; j++;
          }
                j=0;i++;
    }
	
    i=0;
    while (i<=m)
    {
          while (j<=n)
          {
               printf("%6d",a[i][j]);
                j++;
          }
          j=0;i++;
          printf("\n");
    }
      
    i=0;
    scanf("%d %d",&l1,&l2);
    l1a=l1;l2a=l2;
    iloczyn=a[l1][l2];
    while((l1a-1>=0) && (l2a-1>=0)){--l1a;--l2a; iloczyn=iloczyn*a[l1a][l2a];}
    l1a=l1;l2a=l2;
    while((l1a-1>=0) && (l2a+1<=n)){--l1a;++l2a; iloczyn=iloczyn*a[l1a][l2a];}            
    l1a=l1;l2a=l2;
    while((l1a+1<=m) && (l2a+1<=n)){++l1a;++l2a; iloczyn=iloczyn*a[l1a][l2a];}      
    l1a=l1;l2a=l2; 
    while((l1a+1<=m) && (l2a-1>=0)){++l1a;--l2a; iloczyn=iloczyn*a[l1a][l2a];}  
      
    printf("iloczyn = %d\n",iloczyn);
      
      system("pause");

      }
