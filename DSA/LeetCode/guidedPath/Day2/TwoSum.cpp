class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> map;
        vector<int> ret;
        int i;
        for(i=0; i<numbers.size(); i++){
            if(map.find(numbers[i])==map.end())
                map[target-numbers[i]] = i;
            else{
                ret.push_back(map[numbers[i]]);
                ret.push_back(i);
                break;
            }
        }
        return ret;
    }
        
    vector<int> unorderedSetSolution(vector<int>& nums, int target) {
        vector<int> ans(2);
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++){
            int diff = abs(target - nums[i]);
            if(st.find(diff) == st.end()){
                st.insert(nums[i]);
            } else {
                ans[0] = *st.find(diff);
                ans[1] = i;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == ans[0]){
                if(ans[1] != i){
                    ans[0] = i;
                }
            }
        }
        return ans;
    }
    
    vector<int> badSolution(vector<int>& nums, int target) {// O(n*2)
        vector<int> ans(2);
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(i != j){
                    if(nums[i] + nums[j] == target){
                        ans[0] = i;
                        ans[1] = j;
                    }
                }
            }
        }
        return ans;
    }
};
