#include <bits/stdc++.h>
using namespace std;

/*
 * Given an array, say a = {4,5,2,25,7,8}
 * return the next greatest element for each element of the array,
 * for a, it will be b = {5,25,25,-1,8,-1}
 */

void simpleSol();

vector<int> NGE(vector<int> v)
{
    /*
     * What we can do is:
     * we get a number n, then we push it in the stack
     * and now if n+i > n, n+i is the next greatest element,
     * which can now be stored in an array.
     *
     * and if n+i < n, then we'll push n+i in the stack too
     *
     * We'll pop n and push n+1 and do it all over again
     */

    vector<int> nge(v.size());
    stack<int> st;

    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() and v[i] > v[st.top()])
        {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }
    return nge;

} // returns the vector of next greatest element's indexes

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> nge = NGE(v);

    for (int i = 0; i < n; i++)
        cout << v[i] << " " << (nge[i] == -1 ? -1 : v[nge[i]]) << endl;
}

void simpleSol()
{
    int n;
    cin >> n;
    int arr[n];
    int next[n] = {0};
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            if (arr[i] < arr[j])
                next[i] = max(next[i], arr[j]);
            else
                next[i] = -1;
        }

    for (int i = 0; i < n; i++)
        cout << next[i] << ' ';
}
