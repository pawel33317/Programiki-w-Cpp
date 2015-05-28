#include <iostream>

using namespace std;
#define DELETE(p) { delete (p); (p) = NULL; }

class a{
    int z;
    public:
    a(){
        cout << "zostalam utworzona" << endl;
    }
        ~a(){
        cout << "zostalam skasowana" << endl;
    }
};
int main()
{
    a* ca = new a;
    cout << "wskazywany adres: " << ca << endl;
    delete(ca);
    cout << "wskazywany adres: " << ca << endl;


    #pragma message("komunikat")


    a* ca2 = new a;
    cout << "wskazywany adres: " << ca2 << endl;
    DELETE(ca2);
    cout << "wskazywany adres: " << ca2 << endl;
    return 0;
}
