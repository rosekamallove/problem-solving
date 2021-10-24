#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int start(0), end(size);
        
        while(start < end){
            int mid = (start + end)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                start = mid + 1;
            else 
                end = mid;
        }
        return -1;
    }
};
