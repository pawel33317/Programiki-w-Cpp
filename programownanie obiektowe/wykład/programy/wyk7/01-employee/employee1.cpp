#include <iostream>
#include <string>
#include <set>
using namespace std;

class Employee
{
  string name;
  char middle_initial;
  short department;
public:
    Employee (const string & n, int dept):name (n), department (dept)
  {
  };
  void print () const
  {
    cout << name << '\t' << department << endl;
  }
};

class Manager:public Employee
{
  short level;
public:
    Manager (const string & name, int dept, int l):Employee (name, dept),
    level (l)
  {
  };
  void print () const
  {
    Employee::print ();
    cout << "\tlevel" << level << endl;
  }
};


void
print_list (set < Employee * >&s)
{
  for (set < Employee * >::const_iterator p = s.begin (); p != s.end (); ++p)
    (*p)->print ();
}

void
print_list_2 (set < Employee * >&s)
{
  for_each (s.begin (), s.end (), mem_fun (&Employee::print));
}


int
main ()
{
  Employee e ("Brown", 1234);
  Manager m ("Smith", 1234, 2);
  set < Employee * >empl;
  empl.insert (&e);
  empl.insert (&m);
  print_list_2 (empl);
}
