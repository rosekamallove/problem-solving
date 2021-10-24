/*
 * Solve this question again with maps
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if ((nums.size() == 0) or (k <= 0)) {
            return;
        }
        k = k%nums.size();
            
        /* Approach 1:
         * Store the last k elements in an temp array
         * move the first n - k elements to the last
         * add the temp array in the begenning
         * O(n) => Time
         * O(n) => Space
         */

        /* Approact 2:
         * Divide the array in two parts
         * a[0] , a[n - k - 1] and a[n - k], a[n - 1]
         * reverse both the array
         * put the second array at the begenning
         * reverse the whole array again
         * O(n) => Time
         * O(1) => Space
         */
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());


        cout<<'[';
        for(int i=0; i<nums.size(); i++){
            if(nums.size() - 1 == i){
                cout<<nums[i];
            } else {
                cout<<nums[i]<<',';
            }
        }
        cout<<']';
    }
};
