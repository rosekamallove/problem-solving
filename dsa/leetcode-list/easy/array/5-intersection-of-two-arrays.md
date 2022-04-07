**5. [Intersection of two arrays](https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/674/)**

**Approach 1:**

- Create a set for both the arrays.
- Now push the same elements in an array and voila.

**Approach 2:**

- Sort one of the arrays.
- Iterate over the second array and using binary search check if the ith element exist and push it to ans array
  accordingly

**Approach 3:**

- If the arrays are given sorted then use this approach.
- Else sort both the array and use two pointers to solve the problem

<details><summary>Code:</summary>

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        sort(b.begin(), b.end());
        sort(a.begin(), a.end());
        vector<int> ans;
        int i(0), j(0), n(a.size()), m(b.size());

        while(i < n and j < m) {
            if(a[i] < b[j]) {
                i++;
            } else if(a[i] > b[j]) {
                j++;
            } else {
                ans.push_back(a[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};
```

</details>
