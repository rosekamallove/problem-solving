#include<iostream>
using namespace std;

int main()
{
  int n = 10; 
  int *p = &n;
  cout<<p<<endl;

  p=p+1; 
  cout<<p<<endl;//okay, the address is changed and is equal to 4 + the prev address
                        //because an integer is of 4 bytes 
 
  p=p+2;
  cout<<p<<endl;//similarly this add 8 to the prev memory address

}
