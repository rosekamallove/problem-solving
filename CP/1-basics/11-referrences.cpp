#include<bits/stdc++.h>
using namespace std;

void increment(int n)
{
  n++;
}
void decrement(int &n)// &=> Pass by referrence
{
  n--;
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}
//_Note: Arrays are always passed by refference and never by value_
int main()
{
  int a; cin>>a;
  increment(a);
  cout<<a<<endl;
  decrement(a);
  cout<<a<<endl;

}

