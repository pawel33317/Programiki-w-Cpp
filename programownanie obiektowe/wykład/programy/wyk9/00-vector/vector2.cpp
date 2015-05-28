#include <iostream>
#include <vector>		// for vector template definition
#include <stdexcept>
using namespace std;

int
main ()
{
  int MaxCount = 100;
  vector < int >iVector (MaxCount);
  try
  {
    for (int Count = 0; Count < 2 * MaxCount; Count++)
      {
	cout << iVector.at (Count);
      }
  }
  catch (out_of_range &)
  {
    cerr << "Blad zakresu" << endl;
  }

}
