// print distinct charachters

#include <iostream>
#include <set>
using namespace std;

int main()
{
  /*
   * => set doesn't store duplicate values
   * => set always stores in sorted order
   */
  set<char> s;
  int n;
  cin >> n;
  char a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    s.insert(a[i]);
  }

  set<char>::iterator it;
  for (it = s.begin(); it != s.end(); it++)
    cout << *(it) << " ";
  cout << endl;

  //=> searching:
  char X;
  cin >> X;
  it = s.find(X);
  if (it != s.end())
  {
    cout << *(it) << endl;
  }

  /*
   * Time complexities:
   * insertion -> nlog(n)
   * searching -> log(n)
   */
}
