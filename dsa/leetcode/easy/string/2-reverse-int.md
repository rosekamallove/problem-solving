**2. [Reverse Int](https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/880/)**

<details><summary>Code:</summary>

```cpp
class Solution {
public:
    int reverse(int x) {
        int ans(0);
        while(x){
            bool noOverflow = (ans > INT_MAX/10) or (ans < INT_MIN/10);
            if(noOverflow){
                return 0;
            }
            ans = ans*10 + x%10;
            x = x/10;
        }
        return ans;
    }
};
```

</details>
