**1. [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/)**

- We need to do it in place: O(1) space complexity
- We can use Two Pointers for it.
- If the elements are different then, we'll update the idx else we'll update the iterator.

<details><summary>Code: </summary>

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx(0), i(0);
        for(i = 0; i<nums.size(); i++){
            if(i == 0 or nums[i] != nums[i - 1]){
                nums[idx] = nums[i];
                idx++;
            }
        }
        return idx;
    }
};
```

</details>

- We can also use set to get the duplicates out of the array if we're not bound by O(1) space

<details><summary>Code: </summary>

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(int &x : nums){
            st.insert(x);
        }
        vector<int> ans(st.begin(), st.end());
        nums = ans;
        return st.size();
    }
};
```

</details>
