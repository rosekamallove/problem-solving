#include<bits/stdc++.h>
using namespace std;

  struct node 
  {
    string name;
    int marks;
  };

  node a[10005];

  int cmp(node p, node q)
  {//the comparator
    if(p.marks != q.marks)
      return p.marks > q.marks;
    else
      return p.name < q.name;
  }

int main()
{
  /* sort_comparator
   * => sort(a,a+n,funtionsName);
   * => Conditions in funtion
   * => POINTS on codechef
   */

  int n,x; cin>>n;

  for(int i=0; i<n; i++)
  {
    cin>>a[i].name>>a[i].marks;
  }

  sort(a,a+n,cmp);

  for(int i=0; i<n; i++)
  {
    cout<<a[i].name<<" "<<a[i].marks<<endl;
  }
}
