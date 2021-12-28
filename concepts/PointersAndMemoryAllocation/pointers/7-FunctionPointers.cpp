#include<iostream>
using namespace std;

void print(int* p)
{//A function that basically prints the dereferrence of an pointer
  cout<<*p<<endl;
}

void incrementPointer(int* p)
{
  p = p+1;
}

void increment(int *p)
{
  (*p)++;//this increases the address which the pointer is pointing to by 4bytes.
}

int main()
{
  int i=10;
  int *p = &i;
 
  print(p);//calling the print funcion 
 
  cout<<p<<endl;
  incrementPointer(p);
  cout<<p<<endl;//will it increment?
  //It won't because the function increments a copy of the patameter we gave it and not the actual element
  
  cout<<*p<<endl;
  increment(p);//the function goes to the address and increments the value at teh address hece changing the varibale i
  cout<<*p<<endl;
}
