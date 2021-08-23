#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

/*
 * Given an array containing N integers, and an number S
 * denoting a target sum.
 *
 * Find two distinct integers that can pair up to form
 * target sum. Let us assume there will be only one such
 * pair.
 *
 * Input:
 * arr = [10, 5, 2, 3, -6, 9, 11]
 * S = 4
 *
 * Output:
 * [10, -6]
 */

vector<int> bruteForce(vector<int> v, int n, int s) {
    vector<int> ans;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i!=j) {
                if(v[i] + v[j] == s) {
                    ans.push_back(v[i]);
                    ans.push_back(v[j]);
                }
            }
        }
    }
    return ans;
}

vector<int> wrongOptimized(vector<int> v, int n, int s) {
    /*
     * we can put the numbers in an unordered_set,
     * and look up s - v[i] in O(1)
     */
    vector<int> ans;
    unordered_set<int> st;
    /*
     * This is not the correct approach,
     * you can get a (2,2) as a ans which
     * is not correct, resulting in WA
     *
     * Instead we should add to set as we
     * go along iterating.
     */
    for(int i=0; i<n; i++) {
        st.insert(v[i]);
    }
    for(int i=0; i<n; i++) {
        int temp = s - v[i];
        if(st.find(temp) != st.end()) {
            ans.push_back(v[i]);
            ans.push_back(temp);
        }
    }
    return ans;
}

vector<int> optimized(vector<int> v, int n, int s) {
    vector<int> ans;
    unordered_set<int> st;

    /* Correct approach */

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

int main() {
    int n, s;
    cin>>n;
    vector<int> v(n);
    vector<int> ans;
    vector<int> hsh(10000);
    for(int i=0; i<n; i++) {
        cin>>v[i];
        hsh[v[i]]++;
    }
    cin>>s;
    ans = optimized(v, n, s);
    if(ans.size() == 0) {
        cout<<"No such pair"<<endl;
    } else {
        cout<<ans[0]<<','<<ans[1]<<endl;
    }
}

