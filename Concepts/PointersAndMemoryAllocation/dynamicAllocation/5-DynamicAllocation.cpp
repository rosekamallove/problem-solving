#include<bits/stdc++.h>
using namespace std;

int main()
{
  while(true) int i = 10; // this will run forever without any problem.
  //because after we get out of the scope of one iteratio memory is cleared and only 4byts will be used

  //but if we allocate i dyanmically then:

  while(true) int *p = new int;

}

