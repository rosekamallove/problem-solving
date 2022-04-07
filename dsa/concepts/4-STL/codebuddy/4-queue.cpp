// FIFO
#include <bits/stdc++.h>
using namespace std;

int main()
{
  /*
   * Function:
   * => queue<dataType>queueName
   * => q.push()
   * => q.front()
   * => q.pop()
   * => q.empty()
   * => q.clear()
   */
  queue<int> q;
  int n, x;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> x;
    q.push(x);
  }

  while (!q.empty())
  {
    int current = q.front();
    q.pop();
    cout << current;
    cout << endl;
  }
}
