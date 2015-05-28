#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <stdlib.h>

template<class C> class vector
{
  C *dane;
  unsigned int size;
public:
  class index_out_of_range{};
  explicit vector (int s)
  {
    dane=(C*)malloc(sizeof(C)*s);
    if (!dane) throw bad_alloc();
    size = s;
    unsigned i;
   try
   {
    for (i = 0; i < size; i++)
        new(dane+i)C();
   }
   catch (...)
   {
    for (unsigned j=0; j < i; j++)
     (dane+j)->~C();
     free(dane);
     throw;
   }
  }
   ~vector ()
  {
    for (unsigned j=0; j < size; j++)
     (dane+j)->~C();
     free(dane);
    
  }
  C& operator[] (unsigned int pos)
  {
    if (pos >= size)
      throw index_out_of_range();
    return dane[pos];
  }
  C operator[] (unsigned int pos) const
  {
    if (pos >= size)
      throw index_out_of_range();
    return dane[pos];
  }

  vector (const vector<C> & s)
  {
    dane=(C*)malloc(sizeof(C)*s.size);
    if (!dane) throw bad_alloc();
    size = s.size;
    unsigned i;
   try
   {
    for (i = 0; i < size; i++)
        new(dane+i)C(s[i]);
   }
   catch (...)
   {
    for (unsigned j=0; j < i; j++)
     (dane+j)->~C();
     free(dane);
     throw;
   }



  }
  
  void swap(vector<C>& s)
  {
    C* t1=s.dane;
    unsigned int t2=s.size;
    s.dane=dane;
    s.size=size;
    dane=t1;
    size=t2;
  }
  
  vector<C> & operator= (const vector<C> & s)
  {
    if (this == &s)
      return *this;
    vector<C> n(s);
    swap(n);
    return *this;
  }
  friend ostream & operator<< (ostream & o, const vector<C> & v)
  {
    o << '[';
    for (unsigned i = 0; i < v.size;i++)
      {
	o << v[i];
	if (i != v.size - 1)
	  o << ',';
      };
    o << ']';
    return o;
  }
};
#endif /* __VECTOR_H__ */
