#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

/*
 * Given an array containing N integers, and an number S
 * denoting a target sum.
 *
 * Find all disiting integers taht can add up to form the
 * target sum. The number in each triplet should be ordered in
 * ascending order, and triplets should be ordered too.
 *
 * Return empty array if no such triplets present
 */

vector<int> pairSum(vector<int> &v, int n, int s) {
    /* 
     * We can use pairSum Problem to solve this Problem 
     *
     * We can iterate over all the elements and pass rest
     * of the elements to the pair sum function.
     */
    vector<int> ans;
    unordered_set<int> st;

    for(int i=0; i<n; i++) {
        int temp = s - v[i];
        if(st.find(temp) != st.end()) {
            ans.push_back(v[i]);
            ans.push_back(temp);
            return ans;
        }
        st.insert(v[i]);
    }
    return ans;
}

vector<int> twoPointerPairSum(vector<int> &v, int n, int s){
    /* 
     * We didn't use this approach in solvin pair sum problem
     * because complexity was O(NlogN) which made sorting a
     * bottleneck but it won't be a bottleneck when solvin this
     * triplet problem.
     *
     * By doing this instead of using unordered_set we reduce the
     * space complexity from O(n) to O(1)
     * While maintaining the time complexity of O(n*n)
     */
    vector<int> ans;


    return ans;
}

vector<vector<int>> triplets(vector<int> arr, int n, int sum){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for(int i=0; i<=n-3; i++){
        int j = i + 1;
        int k = n - 1;
    }

    return ans;
}

int main() {
    int n, s; cin>>n;
    vector<int> v(n);
    for(int x : v) cin>>x;
    cin>>s;
}

vector<int> bruteForce() {
    vector<int> ans;
    /*
     * O(n^3)
     * Don't even bother writing
     */
    return ans;
}

