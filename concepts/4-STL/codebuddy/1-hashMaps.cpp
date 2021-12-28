// find frequency of all the integers in an given array

#include <bits/stdc++.h>
using namespace std;

int main()
{
  /* we can use hash array to do the question in O(n), then why do we need maps?
   * The problem wiht hasArray approach:
   * 1. Too much memory waste.
   * 2. Problem with big integers, we cannot declare array of more than 10^8 size.
   */

  // map<key,value> mapName;

  map<long long int, int> m;
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    m[a[i]]++; // to insert n elements it will take nlog(n) time
  }

  map<long long int, int>::iterator it;

  for (it = m.begin(); it != m.end(); ++it)
  {
    cout << it->first << " " << it->second << endl;
  }
  /*
   * Properties of Map:
    => map always stores in sorted order
    => map can never store duplicate keys
    => m.find(x) -> returns directly the pointer to x in O(log(n))
  */

  int X;
  cin >> X;
  it = m.find(X);
  if (it != m.end())
    cout << it->first << " " << it->second << endl;

  /*
   * Time Complexities:
   * insertion  -> nlog(n)
   * traversion -> nlog(n)
   * searching  -> log(n)
   */
}
