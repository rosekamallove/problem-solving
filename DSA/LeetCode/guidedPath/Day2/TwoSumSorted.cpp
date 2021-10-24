class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo(1), hi(numbers.size());
        vector<int> ans(2);
        while(true){
            int sum = numbers[lo - 1]  + numbers[hi - 1];
            if(sum < target){
                lo++;
            } else if(sum > target){
                hi--;
            } else {
                ans[0] = lo;
                ans[1] = hi;
                break;
            }
        }
        return ans;
    }
};
