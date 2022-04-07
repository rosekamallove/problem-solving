**3. [First Unique Character in a String](https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/)**

<details><summary>Code:</summary>

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> mp;
        int ans(-1);
        for(char &x : s){
            mp[x]++;
        }
        for(int i=0; i<s.size(); i++){
            if(mp[s[i]] == 1){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
```

</details>
