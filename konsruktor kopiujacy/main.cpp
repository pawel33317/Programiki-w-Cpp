#include <iostream>

using namespace std;

class AA {
public:
    int a;
    int *b;
    AA(int z, int x){
        this->a = z;
        this->b = new int;
        *this->b = x;
    }
    AA(const AA & refAA){
        cout << "zostalem wywolany" << endl;
        this->a = refAA.a;
        this->b = new int;
        *this->b = *refAA.b;
    }
    AA(const AA* & refAA){
        cout << "zostalem wywolany wsk" << endl;
        this->a = refAA->a;
        this->b = new int;
        *this->b = *refAA->b;
    }
    AA& operator=(const AA& prawyObiekt){
        cout << "zostalem wywolany operator przypisania" << endl;
        delete b;

        b = new int;
        b = prawyObiekt.b;
        return *this;
    }
};




int main()
{
    AA* p1 = new AA(1,2);
    AA* p2 = new AA(*p1);
    AA* p3;
    p3 = p1;

    AA x1(11,22);
    AA x2 = x1;
    x1 = x2;
    cout << "AA p1:   a: " << p1->a <<"  b: "<< *p1->b <<endl;
    cout << "AA p2:   a: " << p2->a <<"  b: "<< *p2->b <<endl;
    cout << "AA p3:   a: " << p3->a <<"  b: "<< *p3->b <<endl;
    p2->a = 3;
    *p2->b = 4;
    p3->a = 5;
    *p3->b = 6;
    //bez konstruktora kopiujacego zmienily by sie oba
    cout << "AA p1:   a: " << p1->a <<"  b: "<< *p1->b <<endl;
    cout << "AA p2:   a: " << p2->a <<"  b: "<< *p2->b <<endl;
    cout << "AA p3:   a: " << p3->a <<"  b: "<< *p3->b <<endl;
    return 0;
}
