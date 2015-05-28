#include<iostream>
#include<stdio.h>

using namespace std;

class clstring
{
      
              char *dstring;
              
      public:
             clstring ():dstring (0)
             {
             };
              
             ~clstring ()
             {
               delete[]dstring;
             };
             
             clstring (const char *ndane)
             {
              if (ndane)
             {
	          dstring = new char[strlen (ndane) + 1];
              strcpy (dstring, ndane);
             }
              else
              dstring = 0;
             }; 
              
             int lenghtstring()  //sprawdza dlugosc tekstu
             {
              int lenght,i;
              i=0;
              lenght=0;
              if(dstring)
              {
                       while(dstring[i++])
                       {lenght++;}
              }
              
              return lenght;
              }   
              
              find           
             
             friend ostream & operator<< (ostream & o, const clstring & s)
             {
             if (s.dstring)
             o << s.dstring;
             return o;
             }
             
};

int main()
{
    
    clstring z("adrian");
    cout<<z<<endl;
    cout<<z.lenghtstring()<<endl;
    system ("PAUSE");


}
