#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        /* Brute Force
        => Find all the subarrays and then check which has the max sum
        => O(n^2)
        */
        
       
        
        /* Checking if all the nums are negative */
        
        bool allNegative = 1;
        int mx(INT_MIN);
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= 0)
                allNegative = 0;
            mx = max(mx, nums[i]);
        }
        if(allNegative){
            return mx;
        }
        
        
        /* Kadane's Alog
        => We'll traverse through the array once
        and if the sum of the current subarray 
        becomes negative then we'll drop the current
        subarray and move on to the next.
        */ 
        int mxSum(0), curSum(0);
        for(int i=0; i<nums.size(); i++){
            curSum += nums[i];
            
            if(curSum > mxSum){
                mxSum = curSum;
            }
            
            if(curSum < 0){
                curSum = 0;
            }
        }
        return mxSum;
    }
};
