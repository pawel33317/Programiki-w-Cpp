#include  <new>
#include <string>
#include <iostream>
using namespace std;

int
main ()
{
  char buf[sizeof (string)];
  string *s = new (buf) string;	// construct an string at .buf;. invokes: operator new(sizeof(string),buf);
  *s = "hello";
  cout << *s << endl;
  s->~string();
}
