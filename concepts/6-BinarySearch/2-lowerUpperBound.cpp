#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> &v, int el)
{
    int l(0), h(v.size() - 1);
    while (h - l > 1)
    {
        int mid = (h + l) / 2;
        if (v[mid] < el)
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }
    if (v[l] >= el)
    {
        return l;
    }
    if (v[h] >= el)
    {
        return h;
    }
    else
    {
        return -1;
    }
}

int upperBound(vector<int> &v, int el)
{
    int l(0), h(v.size() - 1);
    while (h - l > 1)
    {
        int mid = (h + l) / 2;
        if (v[mid] <= el)
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }
    if (v[l] > el)
    {
        return l;
    }
    if (v[h] > el)
    {
        return h;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int el;
    cin >> el;
    cout << lowerBound(arr, el) << ' ' << arr[lowerBound(arr, el)] << endl;
    cout << upperBound(arr, el) << ' ' << arr[upperBound(arr, el)] << endl;
}
