#include<iostream>
using namespace std;

int main()
{
  int i; //stores some garbage value
  cout<<i<<endl;

  i++;
  cout<<i<<endl; //prints the incremented garbage value

  int *p;
  cout<<p<<endl;//prints the address of the garbage value
 // this points to a random address;
  
  cout<<*p<<endl;

  (*p)++;
  cout<<*p<<endl;

  /*
  we should never declare a pointer which is not pointing to anything
  if we don't have anything to allocate to the pointer just make it equal to 0
  *p = 0; is known as the null pointer
  */
  int *f = 0; //null pointer
  cout<<*f<<endl;
}
