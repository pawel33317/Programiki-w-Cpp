#include <iostream>
using namespace std;

class list
{
private:
  struct node
  {
    node *next;
    int val;
  };
  node * head;
  node *current;
public:
  list ();
  list (const list& l);
  list& operator=(const list& l);
  ~list ();
  void insert (int a);
  void goToHead ();
  int getCurrentData ();
  void advance ();
  bool moreData ();
};


list::list ()
{
  head = NULL;
  current = NULL;
}

list::~list ()
{
  while (head)
    {
      node *t = head->next;
      delete head;
      head = t;
    };
}

void
list::insert (int a)
{
  node *nowy = new node;
  nowy->next = head;
  head = nowy;
  head->val = a;
}

void
list::goToHead ()
{
  current = head;
}

int
list::getCurrentData ()
{
  return current->val;
}

void
list::advance ()
{
  current = current->next;
}

bool
list::moreData ()
{
  if (current)
    return true;
  else
    return false;
}

list::list (const list & l)
{
  current=NULL;
  node *src, **dst;
  head = NULL;
  src = l.head;
  dst = &head;
  while (src)
    {
      *dst = new node;
      (*dst)->val = src->val;
      (*dst)->next = NULL;
      if(src==l.current)
        current=*dst;
      src = src->next;
      dst = &((*dst)->next);
    }
}

list & list::operator= (const list & l)
{
  if (&l == this)
    return *this;
  current=NULL;
  while (head)
    {
      node *t =	head->next;
      delete head;
      head = t;
    };
  node *src, **dst;
  head = NULL;
  src = l.head;
  dst = &head;
  while (src)
    {
      *dst = new node;
      (*dst)->val = src->val;
      (*dst)->next = NULL;
      if(src==l.current)
        current=*dst;
      src = src->next;
      dst = &((*dst)->next);
    }
  return *this;
}



void
PrintList (list toPrint, ostream & Out)
{
  int nextValue;
  Out << "Printing list contents: " << endl;
  toPrint.goToHead ();
  if (!toPrint.moreData ())
    {
      Out << "List is empty" << endl;
      return;
    }
  while (toPrint.moreData ())
    {
      nextValue = toPrint.getCurrentData ();
      Out << nextValue << " ";
      toPrint.advance ();
    }
  Out << endl;
}

int
main ()
{
  list l;
  l.insert (1);
  l.insert (2);
  l.insert (3);
  PrintList (l, cout);
  list l2;
  l2=l;
  PrintList (l2,cout);
}
