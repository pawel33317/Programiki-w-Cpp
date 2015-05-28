#include <stdio.h>

int main()
{
    int zm;
    int *wsk;
    printf("Podaj wartosc zmiennej calkowitej: ");
    scanf("%d",&zm);
    wsk=&zm;
    printf("\nWartosc zmiennej calkowitej; wyswietlona bezposrednio: %d\n",zm);
    printf("Wartosc zmiennej calkowitej; wyswietlona z uzyciem wskaznika: %d\n",*wsk);
    printf("Adres zmiennej calkowitej: %d\n",wsk);
    printf("\nZmiana wartosci zmiennej z uzyciem wskaznika\n");
    *wsk=12;
    printf("\nWartosc zmiennej calkowitej; wyswietlona bezposrednio: %d\n",zm);
    printf("Wartosc zmiennej calkowitej; wyswietlona z uzyciem wskaznika: %d\n",*wsk);
    printf("Adres zmiennej calkowitej: %d\n\n",wsk);
    system("pause");
    return 0;
}

