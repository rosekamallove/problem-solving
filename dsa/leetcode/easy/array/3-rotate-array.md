**3. [Rotate Array](https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/)**

- p1 + p2 (Breaking the array into two parts)
- p1^ + p2^ (Reversing Individually)
- p2^^ + p1^^ (Reversing Whole)
- p2 + p1 (What we wanted)

<details><summary>Code:</summary>

```cpp
class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        k = k%arr.size();

        reverse(arr.begin(), arr.end() - k);
        reverse(arr.end() - k, arr.end());
        reverse(arr.begin(), arr.end());
    }

};

```

</details>
