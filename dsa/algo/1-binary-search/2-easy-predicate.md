**Problem Statement:**

You are a product manager and currently leading a team to develop a new product.
Unfortunately, the latest version of your product fails the quality check. Since
each version is developed based on the previous version, all the versions after
a bad version are also bad.

Suppose you have `n` versions `[1, 2, ..., n]` and you want to find out the first
bad one, which causes all the following ones to be bad.

You are given an API bool `isBadVersion(version)` which returns whether `version` is bad.
Implement a function to find the first bad version.
You should minimize the number of calls to the API.

**Example 1:**

```
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
```

**Example 2:**

```
Input: n = 1, bad = 1
Output: 1
```

**Constraints**

```
1 <= bad <= n <= 231 - 1
```

**Solution Approach:**

- We are going to use the concept of `monotonic predicate function` here
- A predicate function is a function which only returns either true
  or false up till an index after which it only returns the opposite.
- 000000011111111 or 1111111111111100 these both can be return values for a predicate function
- We need to find the the point at which the return value changes to false (a bad version) in this question
- Now how do we find that index
  - We can use Binary Search in the following way:
  - If the return value of ` isBadVersion(mid)` is `false` then we are in the bad zone of the products and we can update
    our `lo` to be `mid + 1`
  - else we will update our `hi` to be `mid - 1` since we are in the good zome
  - At last as we need to find the first false value we'll check if `lo` is bad otherwise we'll return `lo + 1`

**Code:**

```cpp
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo(1), hi(n);
        while(lo < hi){
            int mid =  lo + (hi - lo) /2;
            if(isBadVersion(mid))
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        lo = isBadVersion(lo) ? lo : lo + 1;
        return lo;
    }
};
```
