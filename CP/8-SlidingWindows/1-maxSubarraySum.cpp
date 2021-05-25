#include<iostream>
#include<climits>
using namespace std;

/*
 * Given an array of integers,
 * find the maximum sum subarray of the required size
 */

int brute(int n, int m, int arr[])
{
    /*
     * => Calculate all the possible subarray with k memebers and store them in a map,
     * => Iterate over the map and find the max element.
     *
     * Time Complexity: O(n) for the hash table creation, O(1) for every lookup afterwards,
     * Space Complexity: O(n)
     */
    int mx(INT_MIN);

    return mx;
}

int slidingWindow(int n, int m, int arr[])
{
    /*
     * => Start calculating window sum starting with the first two elements,
     * => Slide the window with by one element at a time.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
}

int main()
{
    int n, m; cin>>n>>m;
    int arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];
}
