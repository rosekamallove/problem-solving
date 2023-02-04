#include<iostream>
using namespace std;

int main()
{  
  int i = 65;
  char c = i;//this is known as typecasting.
  //this is implicit typecastin: the computer does it for us
  cout<<c<<endl;

  int * p = &i;
//  char * pc = p;//the compiler says it is bullshit and what the fuck are you even trying to do.
  //but what we can do is tell the compiler to shut up.
  //and we can change it to,

  char * pc = (char*)p;//we are explicitly asking the compiler to typecaste.
  
  cout<<p <<endl;
  cout<<pc<<endl;

  cout<<*p<<endl;
  cout<<*pc<<endl;
  cout<<*(pc+1)<<endl;
  cout<<*(pc+2)<<endl;
  cout<<*(pc+3)<<endl;

}
