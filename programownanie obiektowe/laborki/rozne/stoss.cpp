#include<stdio.h>
#include<iostream>

using namespace std;

class Stack{
      private:
              int rozmiar;
              int stos[];
      public:
             Stack();
             
             ~Stack();
             void wypisz();           
             Stack operator << (int liczba);
             Stack & operator >> (int liczba);
             Stack operator =(const Stack & a);
};
Stack::Stack()
{
              rozmiar=0;
}

Stack::~Stack()
{}
void Stack :: wypisz()
{
     int  i=0;
            for (i=(this->rozmiar)-1;i>-1;i--)
            {
                cout<<this->stos[i]<<endl;
            }
}

Stack Stack:: operator << (int liczba)
{
                stos[rozmiar]=liczba;
                rozmiar=rozmiar+1;
}

Stack & Stack:: operator >> (int liczba)
{
      liczba=stos[rozmiar];
      rozmiar--;
//      return liczba;
}

Stack Stack::operator =(const Stack & a)
{
      this->rozmiar=a.rozmiar;
      int stos[rozmiar];
      for (int i=0;i<rozmiar;i++)
      {
          this->stos[i]=a.stos[i];
      }
} 
 
int main()
{
    int liczba;
    
   Stack a;
   a<<5;
   a<<10;
   a<<15;
   a<<20;
   Stack b;
   //b=a;
   //b.wypisz();
    a.wypisz();
  //  a>>liczba;
   // cout<<(a>>liczba)<<endl;
   // cout<<liczba<<endl;
    system("PAUSE");
}

