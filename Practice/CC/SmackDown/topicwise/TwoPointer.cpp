#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/* Two Pointer
 *
 * -> Easy & Effectice technique that is typically used for
 * searching pairs in sorted array.
 *
 * Ex: Binary Search:-
 * int lo = 0, hi = n - 1; ( Two Pointers )
 * lo -> | <- hi ( At least one value between hi and lo )
 */

void problem1() {
    /* Given an sorted array, find if exists any
     * pair of elements (a[i], a[j]) such that
     * their sum is x.
     *
     * Ex: arr[] => {1,4,5,10,12,18}, x = 23;
     * Output : {18, 5}, ans = {2,5} ( The indices )
     */
    int n, x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];

    /* With O(n^2) we can just
     * generate all the pairs
     * and get the ans.  */


    /* As the array is sorted,
     * we can use two pointer */
    int i=0, j=n-1;
    while(i < j) { //O(n)
        if(a[j] + a[i] == x) {
            cout<<i<<' '<<j<<endl;
            break;
        } else if(a[j] + a[i] < x) {
            i++;
        } else {
            j--;
        }
    }
}

void problem2() {
    /* Given a sorted array & x, find the pair
     * with sum closest to x. 
     *
     * Ex: {10, 22, 28, 29, 30, 40}, x = 54
     * Output: {1, 4} => {22, 30}
     */

    int n, x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];

    int mn = INT_MAX;
    int l(0), h(0);
    int i=0, j=n-1;
    while(i < j){
        int sum = a[i] + a[j];
        if(abs(sum - x) < mn){
            l = i, h = j;
            mn = abs(sum - x);
        }
        if( sum < x ) i++;
        else j--;
    }
    cout<<l<<' '<<h<<endl;
}

int main() {
}

