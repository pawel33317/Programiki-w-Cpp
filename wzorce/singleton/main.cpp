#include <iostream>
using namespace std;

class mySingletonClass {
    static mySingletonClass *mySingletonObject;
    mySingletonClass(){
        cout<<"My Solo Object Created\n";
    }
public:
    static mySingletonClass* getSingletonObject();
};

mySingletonClass* mySingletonClass::mySingletonObject=NULL;

mySingletonClass* mySingletonClass::getSingletonObject(){
    if(!mySingletonObject){
        mySingletonObject=new mySingletonClass;
    }
    return mySingletonObject;
}

int main(int argc, const char * argv[])
{

    mySingletonClass *myObject = myObject->getSingletonObject();
    cout<<myObject<<"\n";

    ///2nd object get the reference of the first object!

    mySingletonClass *myAnotherObject = myAnotherObject->getSingletonObject();
    cout<<myAnotherObject<<"\n";

    delete mySingletonClass::getSingletonObject();
    return 0;
}
