#include <stdio.h>
#include <math.h>

int liczba_pierwsza(int);
void liczba_mersenne(int);

int main()
{
    float a,b;
    int p;
    printf("Program znajdujacy liczby Mersenne'a w przedziale <a,b>\n");
    printf("Podaj kolejno liczby: a>=3 oraz b>=3:\n");
    scanf("%f%f",&a,&b);
    while(a>b || a<3 || b<3)
    {
        printf("Niepoprawny przedzial, podaj ponowie a oraz b:\n");
        scanf("%f%f",&a,&b);
    }  
    p=ceil(log2(a+1));
    printf("\nZnalezione liczby:\n");
    while(pow(2,p)-1<=b)
    {        
        liczba_mersenne(p);
        p++;        
    }   
    system("pause");
    return 0; 
}

int liczba_pierwsza(int n)
{  
    int i;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return 0;
    }    
    return 1;
}

void liczba_mersenne(int n)
{
    if(liczba_pierwsza(n)==1 && liczba_pierwsza(pow(2,n)-1)==1)
        printf("%.lf\n",pow(2,n)-1);
}

