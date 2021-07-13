#include<bits/stdc++.h>
using namespace std;

int main()
{
  /*
   * -> priority_queue<DT,vector<DT>> pq_name; (MAX)
   *    => when we ask for the top element of a max heap it gives the max number in the heap,
   *    => now if we pop this element the heap will again give the max of what is left, i.e. second max
   *
   * -> priority_queue<DT,vector<DT>,greater<DT>> pq_name; (MIN)
   */
  priority_queue<int,vector<int>> pqmx;
  priority_queue<int,vector<int>,greater<int>> pqmn;

  int n, x; cin>>n;

  for(int i=0; i<n; i++)
  {
    cin>>x;
    pqmx.push(x);
  }

  while(!pqmx.empty())
  {
    int current = pqmx.top();
    pqmx.pop();
    cout<<current;
    cout<<endl;
  }

  int m,y; cin>>m;

  for(int i=0; i<m; i++)
  {
    cin>>y; 
    pqmn.push(y);
  }

  while(!pqmn.empty())
  {
    int current = pqmn.top();
    pqmn.pop();
    cout<<current;
    cout<<endl;
  }

}
