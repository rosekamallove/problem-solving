#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i; i=10; // allocate a memory of 4bytes because it of int type and label it to the address of i and fill it with the value 10
    cout<<'i'<<" is at: "<<&i<<endl; //& gives the addres of the memory allocated to a variable.
 
    /*
     now we want to store this memory address (&a) in a variable.
    to store the memory address of a variabl a special type of variabl is to be created
    this varibale is known as a POINTER .
   */
  
    int * p = &i; //here p is an pointer which is pointing to an int, which has it's address at &i.
   
    cout<<'i'<<" is at: "<<p<<endl;//prints the address of i
   
    cout<<'i'<<" is: "<<*p<<endl;//prints the value stored of the address stored in p : the value of i.
                       // *p is called the decrefference operator.


   //We can create pointers of all the data types 
    float f = 545.544;
    float* pf = &f;

    double d = 45.567;
    double *pd = &d;
    return 0;
}
