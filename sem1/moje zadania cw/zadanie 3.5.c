#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float f1(float l){return(2*sin(l));}
float f2(float l){return(		(	(l*l)	+	(3*l)	)	/	(	(l+1)	*	(l+2)	)		);}
float f3(float l){return(sqrt((l*l)+5));}
int main()
{
	float a,b,c; FILE *pl;
	printf("Podaj przedzial po spacji:");
	scanf("%f %f",&a,&b);
	pl=fopen("C:/a.txt","w");
	c=0.5*(b-a);
	while(a+c<=b)
	{	
		if((a>-1)&&(a<=0)){fprintf(pl,"1f(%2.2f) = %13.4f",a,f1(a));printf("1f(%2.2f) = %13.4f",a,f1(a));}
		if((a>0)&&(a<=10)){fprintf(pl,"2f(%2.2f) = %13.4f",a,f2(a));printf("2f(%2.2f) = %13.4f",a,f2(a));}
		if((a>=10)||(a<=-1)){fprintf(pl,"3f(%2.2f) = %13.4f",a,f3(a));printf("3f(%2.2f) = %13.4f",a,f3(a));}if(a>=0)printf(" ");
		if((a+c>-1)&&(a+c<=0)){fprintf(pl,"        1f(%2.2f) = %8.4f\n",a+c,f1(a+c));printf("        1f(%2.2f) = %8.4f\n",a+c,f1(a+c));}
		if((a+c>0)&&(a+c<=10)){fprintf(pl,"        1f(%2.2f) = %8.4f\n",a+c,f2(a+c));printf("        2f(%2.2f) = %8.4f\n",a+c,f2(a+c));}
		if((a+c>=10)||(a+c<=-1)){fprintf(pl,"        1f(%2.2f) = %8.4f\n",a+c,f3(a+c));printf("        3f(%2.2f) = %8.4f\n",a+c,f3(a+c));}
		a=a+0.1;
	}
	fclose(pl);
	printf("\n");
system("pause");
return 0;
}