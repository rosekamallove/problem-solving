**4. [Valid Anagram](https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/)**

<details><summary>Code:</summary>

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp1, mp2;
        for(char &x : s){
            mp1[x]++;
        }
        for(char &x : t){
            mp2[x]++;
        }
        return mp1 == mp2;
    }
};
```

</details>
