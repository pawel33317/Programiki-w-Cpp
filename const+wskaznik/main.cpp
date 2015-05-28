#include <iostream>

using namespace std;

int main()
{
    int a = 101;
    int b = 203;
    int* wska;
    wska = &a;
    *wska = 102;
    cout << *wska << endl;
    wska = &b;
    cout << *wska << endl;

//wskaznik na sta³¹

    const int* wksaConst;
    wksaConst = &a;
    //*wksaConst = 103; ERROR
    cout << *wksaConst << endl;
    wksaConst = &b;
    cout << *wksaConst << endl;

//staly wskaznik na zmienna

    int* const ConstWska = &a;
    *ConstWska = 103;
    cout << *ConstWska << endl;
    //ConstWska = &b; ERROR
    cout << *ConstWska << endl;
    return 0;
}
