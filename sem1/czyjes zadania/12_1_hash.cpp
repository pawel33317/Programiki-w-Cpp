#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

struct student
{
   char imie[20];
   char nazwisko[20];
   int indeks;
};

int h(char *key)
{
    int i=0;
    int p=5;
    double suma=0;
    while(*(key+i))
    {
        suma=*(key+i)*pow((float)p,i);
        i++;
    }printf("\n%d\n",(int)suma%10);
    return (int)suma%10;
};


void push(vector <struct student> *s)
{
    struct student *cell;
    if(cell=(struct student*)malloc(sizeof(struct student))) 
    {
        printf("Podaj imie: ");
        scanf("%s",cell->imie);
        printf("Podaj nazwisko: ");
        scanf("%s",cell->nazwisko); 
        printf("Podaj indeks: ");
        scanf("%d",&cell->indeks);             
        (s+h(cell->nazwisko))->push_back (*cell);     
    }       
}

void printall(vector <struct student> *s)
{
    vector <struct student> :: iterator j;
    for(int i=0;i<10;i++)
        for(j=(s+i)->begin();j!=(s+i)->end();j++)
            printf("%-20s%-20s%-20d\n",j->imie,j->nazwisko,j->indeks);
}

int main()
{
    int i;    
    vector <struct student> hashTable[10];
    //printf("%d",h("c"));
    for(i=0;i<3;i++)
        push(hashTable);
    printall(hashTable);
    system("PAUSE");
    return 0;
}
//stos,lista, struktury, sort przez scalanie - kolokwium!
