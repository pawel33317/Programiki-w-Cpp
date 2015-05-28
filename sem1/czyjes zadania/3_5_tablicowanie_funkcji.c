#include <stdio.h>
#include <math.h>

int main()
{
    FILE *f;
    char sciezka[50];
    int a,b,x;
    double y;
    printf("Program do tablicowania funkcji:\n");    
    printf("f(x)=\n");
    printf("\t2*sin(x)                    dla -1<x<=0\n");
    printf("\t[(x^2)+3*x]/[(x+1)(x+2)]    dla 0<x<10\n");
    printf("\t[(x^2)+5]^(1/2)             dla x<=-1 lub x>=10\n");
    printf("Podaj przedzial <a,b>, w ktorym beda obliczane wartosci:\n");
    scanf("%d%d",&a,&b);
    printf("Podaj sciezke dostepu do pliku, w ktorym zostana zapisane wyniki:\n");
    fflush(stdin);
    gets(sciezka);    
    f=fopen(sciezka,"w");
    for(x=a;x<=b;x++)
    {
        if(x>-1 && x<=0)
            y=2*sin(x);
        else if(x>0 && x<10)
            y=(double)(x*x+3*x)/((x+1)*(x+2));
        else 
            y=sqrt(x*x+5);
        fprintf(f,"%d\t%lf\n",x,y);
    }
    fclose(f);    
    system("pause");
    return 0;
}
