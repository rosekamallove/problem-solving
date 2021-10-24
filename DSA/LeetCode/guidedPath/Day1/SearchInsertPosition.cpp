#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start(0), end((int)nums.size() - 1), position(-1);
        
        while(start <= end){
            int mid = (start + end) / 2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target) {
                start = mid + 1;
                position = mid + 1;
            } else {
                end = mid - 1;
                position = mid;
            }
        }
        return position;
    }
};
