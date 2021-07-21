
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int i=10;
  int j = i;

  i++;
  cout<<j<<endl;//this prints 10 instead of 11.
  
  //so to make i and j related we will have to make
  //j a referrence varibale.
  
  int &J = i;//this doesn't create another memory block for J 
  // but instead references it to the address of i
  i++;
  cout<<J<<endl;

}

