**6. [Two Sum](https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/)**

- Brute Force approach would be to check every pair and their differnece
- Another optimised approach would be to use a hash map and check if the `target - a[i]` is present or not, else we can
  push `i` into the map

<details><summary>Code:</summary>

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> map;
        vector<int> ret;
        int i;
        for(i=0; i<numbers.size(); i++){

            if(map.find(numbers[i]) == map.end())
                map[target-numbers[i]] = i;

            else {
                ret.push_back(map[numbers[i]]);
                ret.push_back(i);
                break;
            }
        }
        return ret;
    }
};
```

</details>
