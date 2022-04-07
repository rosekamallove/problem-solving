#include<iostream>
using namespace std;

int main()
{
  int a[10];
  cout<<a<<endl;//prints the address of a
  cout<<&a[0]<<endl;//notice it is the same as a[0]

  a[0] = 5;
  
  cout<<*a<<endl;//treating a like a pointer -> a[0]
  
  cout<<a+1<<endl;//now this points to the next element in the array (a[1])
  cout<<&a[1]<<endl;

  a[1] = 12;

  cout<<*a<<endl;//prints the value of a[0]
  cout<<*(a+1)<<endl;//prints the value of a[1]

  int *p = &a[0];

  cout<<a<<endl;
  cout<<p<<endl;//both print the same address

  cout<<&p<<endl;//this is where tha pointer is stored
  cout<<&a<<endl;//this is same as printing a and different from the address of p
                 //bcz there is no extra space allocated for the array unlike a pointer

  cout<<sizeof(p)<<endl;
  cout<<sizeof(a)<<endl;

  p = p+1; //this is aboslutely fine
  a = a+1; //this is not! a cannot be re assigned
  //however
  p = a+1; // is fine but a cannot be reassignedi
}
