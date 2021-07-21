#include<iostream>
using namespace std;

void increment1(int** p)
{//think about this for a little bit!  
  p = p + 1;
}//changes nothing 

void increment(int**p)
{//think about this for a little bit!
  *p = *p+1;
}//changes the value of the pointer this double pointer is pionting to

void increment3(int **p)
{
  **p = **p +1;
}//changes the value of the integer.
int main()
{
// ==> Double pointers are basically pointers which are storing the address of another pointer.
// For Ex, we create a int i, and then store the address of i in a pointer p
  int i;
  int * p = &i;
// Now lookin at the syntax of the line above, it suggests us that p is a pointer that is storing address of an int--> int*
// What if we wanna store the adress of the poniter itself, we can do that by:
  int* *p2 = &p;
// The int* suggests that it is a pointer which is storing the adress of a pointer that is sotring the address of a integer.
// This p2 is considered a double pointer.
// Look at the outputs of the following lines to better understand.
 
  cout<<p2<<endl;
  cout<<&p<<endl;//these two lines print the same thing as &p gives the address of p and p2 sotres the address of p.

  cout<<p<<endl;//this prints what is stored in p --> address of i
  cout<<*p2<<endl;//this dereferrences to what is stored in p as it points to p, hence same as the above line.
  cout<<&i<<endl;

  cout<<i<<endl;//prints the value stored in i
  cout<<*p<<endl;//dereferrnces the address stored in p and prints the value stored at that address -> the value of i -> 10
  cout<<**p2<<endl;//dereferrnces the address stored in p2 which dereferrences the address stored in p and prints the value stored at that address -> the value of i -> 10



}
