#include <iostream>

using namespace std;
class CFoo
{
     private:
        unsigned m_uPole;
     public:
        unsigned& Pole() { return m_uPole; }
};



int main()
{
    CFoo Foo;
    Foo.Pole() = 10;
    cout << Foo.Pole() << endl;

    CFoo* Foo2 = new CFoo;
    Foo2->Pole() = 10;
    cout << Foo2->Pole() << endl;

    return 0;
}
