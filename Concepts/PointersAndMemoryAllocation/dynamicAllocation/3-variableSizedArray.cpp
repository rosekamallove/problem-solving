#include<bits/stdc++.h>
using namespace std;

int main()
{
  int *p = new int;
  *p = 10;
  cout<<*p<<endl;

  double *pd = new double;
  char* c = new char;
  
  //=> Now declaring a variable sized array 

  int *pa = new int[50];
  int n;
  cin>>n;
  
  int * pa2 = new int[n];//dynamically allocated array

  pa2[0] = 10;//-> *(pa2 +0)


}

