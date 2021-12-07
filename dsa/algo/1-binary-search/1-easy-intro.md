**Problem Statement:**

Given an array of integers nums which is sorted in ascending order, and
an integer `target`, write a function to search target in `nums`. If `target`
exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**

```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

**Example 1:**

```
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```

**Constraints:**

```
1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.
```

**Solution Approach**:

- Array is sorted so we know it definately is increasing
- We can check the middle of the array and compare it with the target and then
  - If the `target < mid` then we are sure that it is not in the `mid ->` part of the array
  - Else if `target > mid` then we are sure that it is not in the `<- mid` part of the array
  - This decreases the size of the array in every step

**Code:**

```cpp
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
                // now the array starts from mid
            else
                end = mid;
                // now the array ends at mid
        }
        return -1;
    }
};
```
