#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;


bool GTRM(long val) 
{ 
    return val > (RAND_MAX >> 1);
}

int
main ()
{
  srandom(time(NULL));
  vector < long > v(10);
  generate(v.begin(),v.end(),random);
  cout << count_if(v.begin(),v.end(),GTRM)<<endl;
};
