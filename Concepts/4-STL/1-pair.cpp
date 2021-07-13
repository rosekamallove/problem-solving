#include<iostream>
using namespace std;

int main()
{
  pair<int,string> p;
  //p = make_pair(2,"abc");
  p={2,"abc"};
  pair<int, string> p1=p;
  p1.first = 3;
  cout<<p.first<<" "<<p.second<<endl;


  //why pairs?
  int a[] = {1,3,3};
  int b[] = {2,3,4};

  pair<int, int> pArray[3];
  pArray[0] = {1,2};
  pArray[1] = {2,3};
  pArray[2] = {3,4};

  for(int i=0; i<3; i++)
    cout<<pArray[i].first << " " <<pArray[i].second<<endl;
  cout<<endl;
  swap(pArray[2],pArray[1]);
  for(int i=0; i<3; i++)
    cout<<pArray[i].first << " " <<pArray[i].second<<endl;
}
