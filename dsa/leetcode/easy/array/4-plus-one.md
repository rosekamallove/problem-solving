**4. [Plus One](https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/559/)**

- Observe what will happen if the numbers are 9;

<details><summary>Code:</summary>

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size() - 1;
        if(digits[idx] != 9){
            digits[idx]++;
            return digits;
        }
        while(digits[idx] == 9){
            digits[idx] = 0;
            idx--;
            if(idx < 0){
                break;
            }
        }
        if(idx == -1){
            digits.push_back(0);
            digits[0] = 1;
            return digits;
        } else {
            digits[idx]++;
            return digits;
        }
    }
};
```

</details>
