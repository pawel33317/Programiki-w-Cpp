#include <iostream>

using namespace std;
class CFoo
{
public:
    static int i;
    int Metoda() const { cout << "wywolano mnie: " << i << endl; i++;return 1; }
};
int CFoo::i = 0;


int main()
{
    CFoo* pFoo = new CFoo;

    pFoo->Metoda();
    (*pFoo).Metoda();

    CFoo foo;

    foo.Metoda();
    (&foo)->Metoda();

    void* voidFoo = new CFoo;
    CFoo* castf = static_cast<CFoo*>(voidFoo);
    castf->Metoda();

    int tab[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    for(int i=0; i<3;i++){
        for(int j=0; j<3;j++){
            cout << tab[i][j] << " " ;
        }
        cout << endl;
    }
cout << endl;
    for(int i=0; i<3;i++){
        for(int j=0; j<3;j++){
            cout << *(*(tab+i)+j) << " " ;
        }
        cout << endl;
    }

    return 0;
}
