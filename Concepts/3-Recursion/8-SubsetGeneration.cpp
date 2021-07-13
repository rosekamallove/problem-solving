#include<iostream>
#include<vector>
using namespace std;

/*
 * Given an integer array `nums` of unique elements, return all possible
 * subsets (the power set).
 * The solution set must not contain duplicate subsets.
 *
 * Input : nums=[1,2,3];
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 */

vector<vector<int>> subsets;

void generate(vector<int> &subset, int i, vector<int> &nums){
    if(i == nums.size()){
        subsets.push_back(subset);
        return;
    }

    /* i'th element not in subset */
    generate(subset, i+1, nums);

    /* i'th element in subset */
    subset.push_back(nums[i]);
    generate(subset,i+1, nums);
    subset.pop_back();
}

int main(){
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n ;  i++){
        cin>>nums[i];
    }
    vector<int> empty;
    generate(empty,0,nums);
    for(auto subset : subsets){
        for(auto element : subset){
            cout<<element<<' ';
        }
        cout<<endl;
    }
}
