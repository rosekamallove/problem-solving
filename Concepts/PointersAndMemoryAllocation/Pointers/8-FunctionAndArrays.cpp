#include<iostream>
using namespace std;

int sum(int *a, int size)//we can change a[] -> *a and use it normally like a[i] bcz it is automatically converted, a[i]=> *(a+5)
{
// cout<<sizeof(a) <<endl;//this prints 8 proving that array is parsed as an pointer
 int sum = 0;
 for(int i=0; i<size; i++)
 {
   sum += a[i];// --> *(a+i);
 }
 return sum;
}

int main()
{
  int a[10];
  cout<<sizeof(a)<<endl;//this prints 40 which is the size of the array(4*10)
  cout<<sum(a,10)<<endl;
  //Knowing this much about array and functions what we can do is pass a part of an array to the functio.
  cout<<sum(a+3, 7) <<endl; 
}
