#include<iostream>
using namespace std;

int main()
{
  int n=10;
  int *p = &n;

  cout<<sizeof(p)<<endl;
  cout<<n<<endl;//prints 10
  cout<<*p<<endl;//prints 10 as well

  n++;

  cout<<n<<endl;//prints 11
  cout<<*p<<endl;//prints 11 as well

  int a = n;// n is exactly same as *p so this is eqivalent to a = *pi
  a++;
 
  cout<<a<<endl;//prints 12
  cout<<*p<<endl; //prints 11

  n = 12;//changes the value of memory address of i
  cout<<n<<endl;//prints 11
  cout<<*p<<endl;//prints 11

  *p = 32;//also changes the value of memory address of i
  cout<<n<<endl;//prints 32
  cout<<*p<<endl;//prints 32

  (*p)++;
  cout<<n<<endl;//prints 33
  cout<<*p<<endl;//prints 33
}
