#include <iostream>
#include "CVector2D.cpp"

using namespace std;

int main()
{
    CVector2D* vec1 = new CVector2D(1.1,2.2);
    vec1->wypisz();

    *vec1 = -*vec1;
    vec1->wypisz();

    *vec1 = +*vec1;
    vec1->wypisz();

    ++(*vec1);
    vec1->wypisz();

    (*vec1)++;
    vec1->wypisz();

    CVector2D* vec2;

    *vec2 = (*vec1) + (*vec1);
    vec2->wypisz();

    *vec2 = (*vec2)*10;
    vec2->wypisz();

    *vec2 = 10 * (*vec2);
    vec2->wypisz();
    return 0;
}
