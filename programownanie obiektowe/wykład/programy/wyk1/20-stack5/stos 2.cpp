#include <iostream>
#include <assert.h>

using namespace std;

class Stack
{
public:
Stack();
~Stack();
Stack(const Stack &);
void clear();
void operator<<(int);
Stack & operator>>(int &);
private:
int size;
int *dane;
int top;
};

Stack::Stack()
{
this->top = 0;
this->size = 0;
}

Stack::~Stack()
{
}

Stack::Stack(const Stack & a)
{
this->dane = a.dane;
this->top = a.top;
this->size = a.size;
for(int i = 0; i < (a.size); i++)
   this->dane[i] = a.dane[i];
}

void Stack::clear()
{
delete [](this->dane);
this->top = 0;
}

void Stack::operator<<(int x)
{
if((this->top) >= (this->size))
{
 int newsize = ((this->size) + 1) * 2;
 int *ndane = new int[newsize];
 if((this->top) != 0)
 {
  for(int i = 0; i < (this->size); i++)
   ndane[i] = this->dane[i];
  if (this->dane) 
   delete [] this->dane;
  this->dane = ndane;
 }
 if(ndane)
    this->dane = ndane;
 else
    {
  delete [](this->dane);
  abort();
 }
 fprintf(stderr, "Rozmiar stosu %d -> %d\n", this->size, newsize);
 this->size = newsize;
}
this->dane[this->top++] = x;
}

Stack & Stack::operator>>(int & y)
{
//assert(this->top > 0);
y = this->dane[--this->top];
return *this;
}

int main()
{
Stack a; // tworzy pusty stos
a << 10; // odklada liczbe 10 na stos
a << 12;
int ia, ib, ic, id;
Stack b=a;
a >> ia >> ib;
b >> ic;
b >> id;
cout << ia << " " << ib << " " << ic << " " << id << endl;
  // wypisuje "12 10 12 10"
a.clear(); // czysci zawartosc stosu

system("PAUSE");
}
