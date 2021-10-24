#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        if(st.size() < nums.size()){
            return true;
        } else {
            return false;
        }    
    }
    
    bool containsDuplicateSlow(vector<int>& nums) {
        map<int, int> freq;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        for(auto it = freq.begin(); it!=freq.end(); it++){
            if(it->second > 1){
                return true;
            }
        }
        return false;
    }
};
