#include <bits/stdc++.h>
using namespace std;
/*
 * # Lower Bound :
 *  -> It returns the element to find's first index if it is present,
 *     and if it isn't present then it returns the element next to it.
 *  => 4 5 5 7 8 25 : lower bound of 5 will return the element at index 1,
 *                  : lower bound of 7 will return the element at index 3,
 *                  : lower bound of 6 will return the element at index 3.
 */

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    // int *ptr = lower_bound(a, a+n, 55);
    int *ptr = upper_bound(a, a + n, 5);

    if (ptr == a + n)
    {
        cout << "Not Found" << endl;
        return 0;
    }
    cout << (*ptr) << endl;
}
