#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
 * The inbuilt sort function in cpp-stl is
 * cosidered the best sorting function
 *
 * Introsort begins with quicksort and if the recursion depth goes 
 * more than a particular limit it switches to Heapsort to avoid 
 * Quicksort’s worse case O(N2) time complexity.
 * It also uses insertion sort when the number of elements to sort is quite less.
 * So first it creates a partition. 
 *
 * #  Three cases arises from here :-
 *
 * => If the partition size is such that there is a possibility to exceed the maximum 
 *    depth limit then the Introsort switches to Heapsort. 
 *    We define the maximum depth  limit as 2*log(N)
 *
 * => If the partition size is too small then Quicksort decays to Insertion Sort. 
 *    We define this cutoff as 16 (due to research). 
 *    So if the partition size is less than 16 then we will do insertion sort.
 *
 * => If the partition size is under the limit and not too small 
 *    (i.e- between 16 and 2*log(N)), then it performs a simple quicksort.
 */

int main()
{
    int n; cin>>n;
    int a[n];

    for(int i=0; i<n; i++)
        cin>>a[i];

    sort(a,a+n);
    /*
     * -> The sort function takes two parameters, the pointer of where to begin sorting 
     *    and the pointer just next to the last element or till where we need to sort.
     * => Hence, we use sort(a,a+n) instead of sort(a, a+(n-1)) as latter will sort till n-2.
     */

    for(int i=0; i<n; i++)
        cout<<a[i]<<' ';
    cout<<endl;

    vector<int> v(n);

    for(int i=0; i<n; i++)
        cin>>v[i];

    sort(v.begin(), v.end());

    for(int i=0; i<n; i++)
        cout<<v[i]<<' ';
    cout<<endl;
}
