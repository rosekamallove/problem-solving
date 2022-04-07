#include<iostream>
using namespace std;

int main()
{
  int a[] = {1,2,3};
  char c[] = "abc";

  cout<<c<<endl;//prints the string itself
  cout<<a<<endl;//prints the address of array

  char* w =&c[0];
  cout<<w<<endl;

  char c1 = 'a';
  char * pc1 = &c1;

  cout<<c1<<endl;
  cout<<pc1<<endl;//will print whats in c1 and then will continue to print garbage until it finds a null char


  char str[] = "abcded";//systerm creates a temporary memory first
 // and then creates an array of size 6 stored permanently for our use.
 
  char * pstr = "abcdef";//this is a pointer which is pointing to a temporary memory which is dangerous
  cout<<pstr<<endl;
  cout<<str<<endl;
 
}
